/* 
 * File:   enemigos.cpp
 * Author: guillermo
 * 
 * Created on 21 de abril de 2009, 11:43
 */

#include "enemigos.h"

Enemigos::Enemigos() {
#    ifdef DEB
    cout << "Constructor:Enemigos" << endl;
#    endif
    nEnem = 0;
    vi = .5;
    rango = 200;
    srand(time(NULL));
#    ifdef DEB
    cout << "iniciando arrays enemigos y balas" << endl;
#    endif
    for (int e = 0; e < MAXENEM; e++) {
        enems[e] = NULL;
    }
    for (int b = 0; b < MAXENEM; b++) {
        balas[b] = NULL;
    }
#    ifdef DEB
    cout << "creando puntos de aparicion aleatorios" << endl;
#    endif
    int i = 0;
    Punto pr;
    while (i < MAXENEM) {
#        ifdef DEB
        cout << "punto " << i;
#        endif
        pr.x = 100 + rand() % 500;
        pr.y = 100 + rand() % 300;
#        ifdef DEB
        cout << " (" << pr.x << ", " << pr.y << ")" << endl;
#        endif
        PRespawn.Agregar(1, pr);
        i++;
    }
}

Enemigos::Enemigos(const Enemigos& orig) { }

Enemigos::~Enemigos() {
#    ifdef DEB
    cout << "enemigos>Liberando enemigos" << endl;
#    endif
    for (int e = 0; e < MAXENEM; e++) {
        if (enems[e] != NULL) {
            delete enems[e];
        }
    }
    for (int b = 0; b < MAXENEM; b++) {
        if (balas[b] != NULL) {
            delete balas[b];
        }
    }
}

void Enemigos::agnadirEnems(int nEnems) {
    Uint32 r = rand();
    float x, y;
    int i = 0;
    while (i < nEnems && i < MAXENEM) {
        if (enems[i] == NULL) {//Si está libre
#            ifdef DEB
            cout << "enemigo " << i + 1 << " de " << nEnems << endl;
#            endif
            x = PRespawn.Consultar(i + 1).x;
            y = PRespawn.Consultar(i + 1).y;
            enems[i] = new Tanque(40, 40, x, y, vi, r % 4);
#            ifdef DEB
            cout << "enemigos>Creando enemigo..." << endl;
            cout << "Coordenadas: (" << x << ", " << y << ")" << endl;
#            endif
            tiempos[i] = 0;
            nEnem++;
        }
        i++;
    }
}

void Enemigos::elimEnem(Uint8 n) {
#    ifdef DEB
    cout << "Eliminando al oponente " << (int)n << endl;
#    endif
    delete enems[n];
    enems[n] = NULL;
    nEnem--;
}

void Enemigos::actualizaEnem(const float tx, const float ty) {
    Uint32 tAhora;
    for (int i = 0; i < MAXENEM; i++) {
        if (enems[i] != NULL) {
            //            compruebaBala(aux);
            if (teHeVisto(enems[i]->diX(), enems[i]->diY(), tx, ty)) {
#                ifdef DEB
                //                cout << "enemigos>Te he visto! :)" << endl;
#                endif
                persigue(enems[i], tx, ty);
                dispara(enems[i]);
            } else {
                tAhora = SDL_GetTicks();
                if (esLaHora(i, tAhora)) {
#                    ifdef DEB
                    //                    cout << "Es la horaaa... Tiempo: " << tAhora - aux->tMod << "ms" << endl;
#                    endif
                    tiempos[i] = SDL_GetTicks();
                    decide(enems[i]);
                }
            }
        }
    }
}

bool Enemigos::teHeVisto(const float ex, const float ey, const float tx, const float ty) {
#    ifdef DEB
    float d = distancia(ex, ey, tx, ty);
    if (rango > d) {
        //        cout << "distancia:" << d << endl;
    }
    return (rango > d);
#    else
    return (rango > distancia(ex, ey, tx, ty));
#    endif
}

float distancia(const float x1, const float y1, const float x2, const float y2) {
    return sqrt((x2 - x1)*(x2 - x1)+(y2 - y1)*(y2 - y1));
}

void Enemigos::orientate(Tanque *t, const float tx, const float ty) {
    if (t->diY() >= ty) {
        if (t->dentro_tabl(ARR)) {
            t->mira(ARR);
        }
    }
    if (t->diY() < ty) {
        if (t->dentro_tabl(ABA)) {
            t->mira(ABA);
        }
    }
    if (t->diX() > tx) {
        if (t->dentro_tabl(IZQ)) {
            t->mira(IZQ);
        }
    }
    if (t->diX() < tx) {
        if (t->dentro_tabl(DER)) {
            t->mira(DER);
        }
    }
}

//void Enemigos::compruebaBala(TNodoEnem* e) {
//    if (e->b != NULL) {
//        e->b->mov();
//        if (e->b->fueraPantalla()) {
//            delete e->b;
//            e->b = NULL;
//        }
//    }
//}

void Enemigos::persigue(Tanque *t, const float tx, const float ty) {
    orientate(t, tx, ty);
    if (t->dentro_tabl(t->diOr())) {
        t->ve(t->diOr());
    }
}

void Enemigos::dispara(const Tanque* t) {
    //    if (e->b == NULL) {
    //#        ifdef DEB
    //        cout << "Enemigo disparando!" << endl;
    //#        endif
    //        e->b = new Bala("bala.png", t.diX() + 15, t.diY() + 15, pantalla,t.diOr());
    //    }
}

void Enemigos::decide(Tanque *t) {
    Uint8 somerandom = rand() % 6;
    EnHace e = numToEstado(somerandom);
    switch (e) {
        case PERSIGO:
            break;
        case PARADO:

            break;
        case MARR:
            t->ve(ARR);
            break;
        case MABA:
            t->ve(ABA);
            break;
        case MIZQ:
            t->ve(IZQ);
            break;
        case MDER:
            t->ve(DER);
            break;
    }
}

EnHace Enemigos::numToEstado(Uint8 rand) {
    EnHace ret = PARADO;
    switch (rand) {
        case 0:
            ret = PARADO;
            break;
        case 1:
            ret = MARR;
            break;
        case 2:
            ret = MABA;
            break;
        case 3:
            ret = MIZQ;
            break;
        case 4:
            ret = MDER;
            break;
        case 5:
            ret = PERSIGO;
    }
    return ret;
}

bool Enemigos::esLaHora(int ind, Uint32 tAhora) {
    return ((tAhora - (tiempos[ind] + (rand() % tMargen))) > tRefresh);
}

void Enemigos::colisiones(Tanque* j, Bala* b, CCola<TColision> &col) {

    TColision tmp;
    while (!col.esVacia()) {
        col.descartar();
    }
    for (int i = 0; i < MAXENEM; i++) {
        if (enems[i] != NULL) {
            tmp = ColisionGenerica(j->diX(), j->diY(), j->diW(), j->diH(), enems[i]->diX(), enems[i]->diY(), enems[i]->diW(), enems[i]->diH());
            if (tmp.col) {
#                ifdef DEB
                cout << "Colision! Jugador:(" << j->diX() << "," << j->diY() << "), enem:(" << enems[i]->diX() << "," << enems[i]->diY() << endl;
#                endif
                tmp.col = i+1;
                tmp.que = TANQUE;
                col.encolar(tmp);
            }
            if (b != NULL) {
                tmp = ColisionGenerica(b->diX(), b->diY(), b->diW(), b->diH(), enems[i]->diX(), enems[i]->diY(), enems[i]->diW(), enems[i]->diH());
                if (tmp.col) {
#                    ifdef DEB
                    cout << "Colision Bala" << endl;
#                    endif
                    tmp.col = i+1;
                    tmp.que = BALA;
                    col.encolar(tmp);

                }
            }


        }
    }
}

Uint8 Enemigos::numEnem() {
    return nEnem;
}

Tanque *Enemigos::selecEnem(int n) {
    return enems[n];
}

Bala *Enemigos::selecBala(int n) {
    return balas[n];
}

