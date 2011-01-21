/* 
 * File:   Control.cpp
 * Author: guillermo
 * 
 * Created on 5 de abril de 2009, 16:45
 */

#include "juego.h"

Juego::Juego() {
    //Inicializacion array teclas
    for (int i = 0; i < nTecArr; i++) {
        arrTeclas[i] = false;
    }
    fondo = NULL;
    confirma = NULL;
    bSI = bNO = NULL;
    bal = NULL;
    jugador = NULL;
    oponentes = NULL;
    bjugar = NULL;
    bsalir = NULL;
    cif = NULL;
    BRizq = false;
    e = MENU;
    jugando = true;
}

Juego::Juego(const Juego& orig) { }

Juego::~Juego() {
    SDL_FreeSurface(fondo);
    if (oponentes != NULL) {
#        ifdef DEB
        cout << "\tcontrolador>";
#        endif
        delete oponentes;
    }
    if (jugador != NULL) {
#        ifdef DEB
        cout << "\tcontrolador>";
#        endif
        delete jugador;
    }
#    ifdef DEB
    cout << "\tcontrolador>";
#    endif
    delete pincel;
    if (bal != NULL) {
        delete bal;
    }
    if (bjugar != NULL) {
        delete bjugar;
    }
    if (bsalir != NULL) {
        delete bsalir;
    }
}

void Juego::tecla_pulsada(SDLKey tecla) {
    switch (tecla) {
        case SDLK_UP:
            arrTeclas[0] = true;
            break;
        case SDLK_DOWN:
            arrTeclas[1] = true;
            break;
        case SDLK_LEFT:
            arrTeclas[2] = true;
            break;
        case SDLK_RIGHT:
            arrTeclas[3] = true;
            break;
        case SDLK_SPACE:
            arrTeclas[4] = true;
            break;
        case SDLK_RETURN:
            arrTeclas[5] = true;
            break;
        case SDLK_RCTRL:
            arrTeclas[6] = true;
            break;
    }
}

void Juego::tecla_libre(SDLKey tecla) {
    switch (tecla) {
        case SDLK_UP:
            arrTeclas[0] = false;
            break;
        case SDLK_DOWN:
            arrTeclas[1] = false;
            break;
        case SDLK_LEFT:
            arrTeclas[2] = false;
            break;
        case SDLK_RIGHT:
            arrTeclas[3] = false;
            break;
        case SDLK_SPACE:
            arrTeclas[4] = false;
            break;
        case SDLK_RETURN:
            arrTeclas[5] = false;
            break;
        case SDLK_RCTRL:
            arrTeclas[6] = false;
            break;
    }
}

void Juego::movimiento() {
    switch (e) {
        case MENU:
            if (arrTeclas[0]) {//FLECHA ARRIBA
            }
            if (arrTeclas[1]) {//FLECHA ABAJO
            }
            if (arrTeclas[2]) {//FLECHA IZQUIERDA
            }
            if (arrTeclas[3]) {//FLECHA DERECHA
            }
            if (arrTeclas[4]) {//BARRA ESPACIADORA
            }
            if (arrTeclas[5]) {//RETORNO DE CARRO (ENTER)
                cambiaEstado(JUEGO);
                break;
            }
            if (arrTeclas[6]) {
            }
            break;
        case JUEGO:
            if (oponentes != NULL) {
                oponentes->actualizaEnem(jugador->diX(), jugador->diY());
            }
            if (arrTeclas[0]) {//FLECHA ARRIBA
                jugador->mira(ARR);
                if (jugador->dentro_tabl(ARR)) {
                    jugador->ve(ARR);
                }
            } else if (arrTeclas[1]) {//FLECHA ABAJO
                jugador->mira(ABA);
                if (jugador->dentro_tabl(ABA)) {
                    jugador->ve(ABA);
                }
            } else if (arrTeclas[2]) {//FLECHA IZQUIERDA
                jugador->mira(IZQ);
                if (jugador->dentro_tabl(IZQ)) {
                    jugador->ve(IZQ);
                }
            } else if (arrTeclas[3]) {//FLECHA DERECHA
                jugador->mira(DER);
                if (jugador->dentro_tabl(DER)) {
                    jugador->ve(DER);
                }
            }
            if (arrTeclas[4]) {//BARRA ESPACIADORA
                if (bal == NULL) {
                    bal = new Bala("bala.png", jugador->diX() + 15, jugador->diY() + 15, pantalla, jugador->diOr());
                }
            }
            if (arrTeclas[5]) {//RETORNO DE CARRO (ENTER)

            }
            if (arrTeclas[6]) {

            }
            //Movimiento de la bala del jugador
            if (bal != NULL) {
                bal->mov();
            }
            break;
        case SUBMENU:
            break;
    }
}

void Juego::eventos() {
    switch (e) {
        case SALIR:
            break;
        case JUEGO:
            if (oponentes->numEnem() == 0) {
                cambiaEstado(FINFASE);
            }
            break;
        case MENU:
            if (bjugar != NULL) {
                if (bjugar->encima(Mx, My) && BRizq) {
                    cambiaEstado(JUEGO);
                }
            }
            if (bsalir != NULL) {
                if (bsalir->encima(Mx, My) && BRizq) {
                    cambiaEstado(SALIR);
                }
            }
            break;
        case SUBMENU:
            if (bSI != NULL) {
                if (bSI->encima(Mx, My) && BRizq) {
                    cambiaEstado(MENU);
                }
            }
            if (bNO != NULL) {
                if (bNO->encima(Mx, My) && BRizq) {
                    cambiaEstado(JUEGO);
                }
            }
            break;
        case GAMEOVER:
            if (BRizq) {
                cambiaEstado(MENU);
            }
            break;
        case FINFASE:
            if (BRizq) {
                if (mapas.esVacia()) {
                    cambiaEstado(MENU);
                } else {
                    fondo = IMG_Load(mapas.consulta().c_str());
                    cambiaEstado(JUEGO);
                }
            }
            break;
    }
    colisiones();
    movimiento();
}

void Juego::colisiones() {
    switch (e) {
        case MENU:
            break;
        case JUEGO:
            //enemigos con balas del jugador y el jugador

            if (oponentes != NULL) {
                CCola<TColision> col;
                TColision tmp;
                oponentes->colisiones(jugador, bal, col);
                while (!col.esVacia()) {
                    tmp = col.consulta();
                    col.descartar();
                    if (tmp.col) {
                        switch (tmp.que) {
                            case TANQUE:
#                                ifdef DEB
                                cout << "Colision con jugador" << endl;
#                                endif
                                jugador->destruir();
                                cambiaEstado(GAMEOVER);
                                break;
                            case BALA:
#                                ifdef DEB
                                cout << "Colision con bala" << endl;
#                                endif
                                oponentes->elimEnem(tmp.col - 1);
                                delete bal;
                                bal = NULL;
                                cif->incrementa();
                                break;
                            case PARED:
#                                ifdef DEB
                                cout << "Colision con pared" << endl;
#                                endif
                                break;
                            case OBJETO:
#                                ifdef DEB
                                cout << "Colision con objeto" << endl;
#                                endif
                                break;
                            case ENEM:
#                                ifdef DEB
                                cout << "Colision con enemigo" << endl;
#                                endif
                                switch (tmp.zona) {
                                    case 1:
                                    case 2:
                                        oponentes->selecEnem(tmp.col - 1)->ve(ABA);
                                        break;
                                    case 3:
                                    case 4:
                                        oponentes->selecEnem(tmp.col - 1)->ve(ARR);
                                        break;
                                }
                                break;
                            default:
#                                ifdef DEB
                                cout << "Eing?" << endl;
#                                endif
                                break;
                        }
                    }
                }
                //#                ifdef DEB
                //                cout << "Cola vacía, continuando" << endl;
                //#                endif
            }
            //cuando hay balas en juego
            if (bal != NULL) {
                //Bala fuera de pantalla
                if (bal->fueraPantalla()) {
                    delete bal;
                    bal = NULL;
                }

            }


            //Jugador y enemigo
            break;
        case SUBMENU:
            break;
        case GAMEOVER:
            break;
        case FINFASE:
            break;
    }


}

void Juego::pintadas() {
    switch (e) {
        case MENU:
            pincel->dibujar(fondo);
            pincel->dibujar(bjugar, Mx, My);
            pincel->dibujar(bsalir, Mx, My);
            break;
        case JUEGO:
            if (fondo != NULL) {
                pincel->dibujar(fondo);
            }
#                ifdef DEB
            else {
                cout << "ERROR puntero a fondo NULO" << endl;
            }
#            endif

            if (jugador != NULL) {
                pincel->dibujar(jugador);
            }
            if (bal != NULL) {
                pincel->dibujar(bal);
            }
            if (oponentes != NULL) {
                pincel->dibujar(oponentes);
            }
            if (cif != NULL) {
                pincel->dibujar(cif);
            }
            break;
        case SALIR:

            break;
        case SUBMENU:
            if (confirma != NULL && bSI != NULL && bNO != NULL) {
                pincel->dibujarSubMenu(confirma, bSI, bNO, Mx, My);
            }
            break;
        case GAMEOVER:
            pincel->dibujar(fondo);
            break;
        case FINFASE:
            pincel->dibujar(fondo);
            break;
    }
}

void Juego::cambiaEstado(Estado es) {
    switch (es) {
        case MENU:
            liberaMem();
#            ifdef DEB
            cout << "CAMBIANDO ESTADO: MENU" << endl;
#            endif
            fondo = IMG_Load(fond.c_str());
            bjugar = new Boton(pantalla, "jugarOFF.png", "jugarON.png", 5, 475);
            bsalir = new Boton(pantalla, "salirOFF.png", "salirON.png", 5, 540);
            e = MENU;
#            ifdef DEB
            cout << "ESTADO CAMBIADO A MENU" << endl;
#            endif
            break;
        case JUEGO:
            if (e != SUBMENU) {
                liberaMem();
            }
#            ifdef DEB
            cout << "CAMBIANDO ESTADO: JUEGO" << endl;
#            endif
#            ifdef DEB
            cout << "\tcontrolador>Cambiando fondo" << endl;
#            endif
            fondo = IMG_Load(mapas.consulta().c_str());
            if (jugador == NULL) {
#                ifdef DEB
                cout << "\tcontrolador>Creando jugador" << endl;
#                endif
                jugador = new Tanque(40, 40, 550.0, 550.0, 1.0, 0);
            }
            if (oponentes == NULL) {
#                ifdef DEB
                cout << "\tcontrolador>Creando enemigos" << endl;
#                endif
                oponentes = new Enemigos();
#                ifdef DEB
                cout << "\tcontrolador>agnadiendo enemigos" << endl;
#                endif
                oponentes->agnadirEnems(2);
            }
            if (cif == NULL) {
#                ifdef DEB
                cout << "\tcontrolador>Creando Marcador" << endl;
#                endif
                cif = new Cifra("numeros2.png", 5, 690, 10);
            }
            e = JUEGO;
#            ifdef DEB
            cout << "ESTADO CAMBIADO A JUEGO" << endl;
#            endif
            break;

        case SALIR:
#            ifdef DEB
            cout << "CAMBIANDO ESTADO: SALIR" << endl;
#            endif
            if (e == JUEGO) {
                cambiaEstado(SUBMENU);
            } else if (e == MENU || e == SUBMENU) {

                liberaMem();
                e = SALIR;
#                ifdef DEB
                cout << "ESTADO CAMBIADO A SALIR" << endl;
#                endif
                finJuego();
            }
            break;
        case SUBMENU:
#            ifdef DEB
            cout << "CAMBIANDO ESTADO: SUBMENU" << endl;
#            endif
            confirma = IMG_Load("salirMenu.png");
            bSI = new Boton(pantalla, "siON.png", "siOFF.png", 300, 300);
            bNO = new Boton(pantalla, "noON.png", "noOFF.png", 300, 375);
#            ifdef DEB
            cout << "ESTADO CAMBIADO A SUBMENU" << endl;
#            endif
            e = SUBMENU;
            break;
        case GAMEOVER:
#            ifdef DEB
            cout << "CAMBIANDO ESTADO:GAMEOVER" << endl;
#            endif
            liberaMem();
            fondo = IMG_Load("gameover.png");
#            ifdef DEB
            cout << "ESTADO CAMBIADO A GAMEOVER" << endl;
#            endif
            e = GAMEOVER;
            break;
        case FINFASE:
#            ifdef DEB
            cout << "CAMBIANDO ESTADO:FINFASE" << endl;
#            endif
            liberaMem();
            fondo = IMG_Load("finfase.png");
#            ifdef DEB
            cout << "ESTADO CAMBIADO A FINFASE" << endl;
#            endif
            e = FINFASE;
            break;
    }
}

void Juego::actMouse(Uint16 x, Uint16 y) {
    Mx = x;
    My = y;
}

void Juego::actMouse(bool pressed) {
    BRizq = pressed;
}

void Juego::finJuego() {
    jugando = false;
}

void Juego::liberaMem() {
    if (bSI != NULL) {
        delete bSI;
        bSI = NULL;
    }
    if (bNO != NULL) {
        delete bNO;
        bNO = NULL;
    }
    if (confirma != NULL) {
        delete confirma;
        confirma = NULL;
    }
    if (oponentes != NULL) {
        delete oponentes;
        oponentes = NULL;
    }
    if (jugador != NULL) {
        delete jugador;
        jugador = NULL;
    }
    if (bal != NULL) {
        delete bal;
        bal = NULL;
    }
    if (cif != NULL) {
        delete cif;
        cif = NULL;
    }
    if (bjugar != NULL) {
        delete bjugar;
        bjugar = NULL;
    }
    if (bsalir != NULL) {
        delete bsalir;
        bsalir = NULL;
    }


}

void Juego::cargarMapList(const char* arch) {
    ifstream lista;
    Uint16 nmap = 0;
    char* mapa = new char[255];
    string temp;
    lista.open(arch, ios::in);
    if (!lista.fail()) {
        while (!lista.eof()) {
            lista.getline(mapa, 255);
            temp = mapa;
            if (temp != "") {
#                ifdef DEB
                cout << "Encontrado mapa: " << temp << endl;
#                endif
                mapas.encolar(temp);
                nmap++;
            }
        }
#        ifdef DEB
        cout << "Cargados " << nmap << " mapas." << endl;
#        endif
        lista.close();
    }
    delete[] mapa;
}

void Juego::inicia_SDL() {
#    ifdef DEB
    cout << "juego>Inicializando SDL..." << endl;
#    endif
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "main>Error iniciando interfaz de vídeo: " << SDL_GetError() << endl;
        exit(1);
    }
    atexit(SDL_Quit);
    SDL_WM_SetCaption(NOMBREAPP, NULL); //set del nombre de la ventana e icono
    icono = IMG_Load("icono.png");
    SDL_WM_SetIcon(icono, NULL);
    pantalla = SDL_SetVideoMode(RES_W, RES_H, 0, SDL_ANYFORMAT);
    if (pantalla == NULL) {
        cout << "main>Modo de vídeo no compatible o erróneo" << endl;
        exit(1);
    }
}

void Juego::Jugar() {//Bucle principal
    inicia_SDL();
    fond = "menu.png";
#    ifdef DEB
    cout << "\tcontrolador>Cargando lista de mapas" << endl;
#    endif
    cargarMapList("lista.lst");
#    ifdef DEB
    cout << "\tcontrolador>Creando Pincel" << endl;
#    endif
    pincel = new Dibujante(pantalla, "tanque.png", "enemigos.png", "bala.png", "objetos.png");
    cambiaEstado(MENU);
    cout << "amos al bucle, jugando es " << jugando << endl;
    SDL_Event evento;
    while (jugando) {
        if (SDL_GetTicks() - tiempo_gr >= TLIMGR) {//siLimiteGraficos ~30ms
            pintadas();
            SDL_Flip(pantalla);
            tiempo_gr = SDL_GetTicks();
        }
        if (SDL_GetTicks() - tiempo_ev >= TLIMEV) {//temporizacion//siLimiteEventos ~5ms
            while (SDL_PollEvent(&evento)) {
                switch (evento.type) {
                    case SDL_MOUSEBUTTONDOWN:
                        actMouse(true);
                        break;
                    case SDL_MOUSEBUTTONUP:
                        actMouse(false);
                        break;
                    case SDL_MOUSEMOTION:
                        actMouse(evento.motion.x, evento.motion.y);
                        break;
                    case SDL_KEYUP:
                        tecla_libre(evento.key.keysym.sym);
                        break;
                    case SDL_KEYDOWN:
                        if (evento.key.keysym.sym == SDLK_ESCAPE) {
                            cambiaEstado(SALIR);
                            break;
                        } else if (evento.key.keysym.sym == SDLK_f) { // Si pulsamos f pasamos a pantalla completa
                            if (!SDL_WM_ToggleFullScreen(pantalla)) {

#                                ifdef DEB
                                cout << "main>No se puede pasar a pantalla completa." << endl;
#                                endif
                            }
                        } else {
                            tecla_pulsada(evento.key.keysym.sym);
                        }
                        break;
                    case SDL_QUIT:
#                        ifdef DEB
                        cout << "Juego>Cerrando" << endl;
#                        endif
                        jugando = false;
                        break;
                }
            }
            eventos();
            tiempo_ev = SDL_GetTicks();
        }
        //cout << "l00p!"<<endl;
    }
}
