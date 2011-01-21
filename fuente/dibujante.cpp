/* 
 * File:   dibujante.h
 * Author: guillermo
 *
 * Created on 25 de marzo de 2009, 18:30
 */

#include "enemigos.h"


#include "dibujante.h"

Dibujante::Dibujante(SDL_Surface *p, const char* picTanque, const char* picEnem, const char* picBala, const char* picObjetos) {
    Uint32 colorkey;
    pantalla = p;
    //Tanque
    imgTanque = IMG_Load(picTanque);
    imgTanque = SDL_DisplayFormat(imgTanque);
    colorkey = SDL_MapRGB(pantalla->format, 0, 0xFF, 0);
    SDL_SetColorKey(imgTanque, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    //Enemigos
    imgEnemigos = IMG_Load(picEnem);
    imgEnemigos = SDL_DisplayFormat(imgEnemigos);
    SDL_SetColorKey(imgEnemigos, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    //Bala
    imgBala = IMG_Load(picBala);
    imgBala = SDL_DisplayFormat(imgBala);
    SDL_SetColorKey(imgBala, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    //Objetos
    imgObjetos = IMG_Load(picObjetos);
    imgObjetos = SDL_DisplayFormat(imgObjetos);
    SDL_SetColorKey(imgObjetos, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
   }

Dibujante::Dibujante(const Dibujante& orig) { }

Dibujante::~Dibujante() {
#    ifdef DEB
    cout << "dibujante>Liberando dibujante" << endl;
#    endif
    SDL_FreeSurface(imgTanque);
    SDL_FreeSurface(imgBala);
    SDL_FreeSurface(imgEnemigos);
    SDL_FreeSurface(imgObjetos);
}

void Dibujante::dibujar(Tanque* t) {
    if (t != NULL) {
        Uint16 img_col = t->diCol(), img_fil = t->diFil();
        switch (t->diOr()) {
            case ARR:
                img_col = 0;
                break;
            case DER:
                img_col = 1;
                break;
            case ABA:
                img_col = 2;
                break;
            case IZQ:
                img_col = 3;
                break;
        }
        SDL_Rect sitio, corte;
        corte.h = t->diH();
        corte.w = t->diW();
        corte.x = t->diW() * img_col;
        corte.y = t->diH() * img_fil;
        sitio.x = t->diX();
        sitio.y = t->diY();
        sitio.h = sitio.w = 40;
        SDL_BlitSurface(imgTanque, &corte, pantalla, &sitio);
    } else {
#        ifdef DEB
        cout << "No se puede dibujar tanque: Puntero Nulo" << endl;
#        endif
    }
}

void Dibujante::dibujar(Enemigos *e) {
    if (e != NULL) {
        Tanque* enemigo;
        for (int i = 0; i < MAXENEM; i++) {
            enemigo = e->selecEnem(i);
            if (enemigo != NULL) {
                Uint16 img_col = enemigo->diCol(), img_fil = enemigo->diFil();
                switch (enemigo->diOr()) {
                    case ARR:
                        img_col = 0;
                        break;
                    case DER:
                        img_col = 1;
                        break;
                    case ABA:
                        img_col = 2;
                        break;
                    case IZQ:
                        img_col = 3;
                        break;
                }
                SDL_Rect sitio, corte;
                corte.h = enemigo->diH();
                corte.w = enemigo->diW();
                corte.x = enemigo->diW() * img_col;
                corte.y = enemigo->diH() * img_fil;
                sitio.x = enemigo->diX();
                sitio.y = enemigo->diY();
                sitio.h = sitio.w = 40;
                SDL_BlitSurface(imgEnemigos, &corte, pantalla, &sitio);
            }
        }
        Bala* bala;
        for (int i = 0; i < MAXENEM; i++) {
            bala = e->selecBala(i);
            if (bala != NULL) {
                dibujar(bala);
            }
        }
    } else {
#        ifdef DEB
        cout << "No se puede dibujar enemigos: Puntero Nulo" << endl;
#        endif
    }
}

void Dibujante::dibujar(Bala* b) {
    Uint16 col;
    if (b != NULL) {
        switch (b->diOr()) {
            case ARR:
                col = 0;
                break;
            case ABA:
                col = 1;
                break;
            case IZQ:
                col = 2;
                break;
            case DER:
                col = 3;
                break;
        }

        SDL_Rect corte;
        corte.h = 10;
        corte.w = 10;
        corte.x = corte.w * col;
        corte.y = corte.h * b->diFil();
        SDL_Rect sitio;
        sitio.x = b->diX();
        sitio.y = b->diY();
        sitio.h = 10;
        sitio.w = 10;
        SDL_BlitSurface(imgBala, &corte, pantalla, &sitio);
    }
}

void Dibujante::dibujar(Boton * b, Uint16 rx, Uint16 ry) {
    if (b != NULL) {
        b->dibujate(pantalla, rx, ry);
    }
#        ifdef DEB
    else {
        cout << "No se puede dibujar: Puntero Nulo" << endl;
    }
#    endif
}

void Dibujante::dibujar(Cifra *c) {
    if (c != NULL) {
        c->dibujate(pantalla);
    }
}

void Dibujante::dibujar(SDL_Surface * s, SDL_Rect* corte_pantalla, SDL_Rect * corte_s) {
    if (s != NULL) {
        SDL_BlitSurface(s, corte_s, pantalla, corte_pantalla);
    }
#        ifdef DEB
    else {
        cout << "ERROR: Dibujando superficie NULA" << endl;
    }
#    endif
}

void Dibujante::dibujarSubMenu(SDL_Surface *f, Boton *bsi, Boton *bno, Uint16 rx, Uint16 ry) {
    SDL_Rect dest;
    dest.w = f->w;
    dest.h = f->h;
    dest.x = 200;
    dest.y = 200;
    dibujar(f, &dest);
    dibujar(bsi, rx, ry);
    dibujar(bno, rx, ry);
}
