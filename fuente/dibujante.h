/*
 * File:   dibujante.h
 * Author: guillermo
 *
 * Created on 25 de marzo de 2009, 18:30
 */

#ifndef _DIBUJANTE_H
#define	_DIBUJANTE_H

#ifdef DEB
#include <iostream>
using namespace std;
#endif
#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "tanque.h"
#include "bala.h"
#include "boton.h"
#include "cifra.h"
#include "enemigos.h"

class Dibujante {
public:
    Dibujante(SDL_Surface *p,const char* picTanque, const char* picEnem, const char* picBala, const char* picObjetos);
    Dibujante(const Dibujante& orig);
    virtual ~Dibujante();
    void dibujar(Tanque *t);
    void dibujar(Bala *b);
    void dibujar(Boton *b, Uint16 rx, Uint16 ry);
    void dibujar(Cifra *c);
    void dibujar(Enemigos *e);
    void dibujar(SDL_Surface * s, SDL_Rect* corte_pantalla = NULL, SDL_Rect* corte_s = NULL);
    void dibujarSubMenu(SDL_Surface *f, Boton *bsi, Boton *bno, Uint16 rx, Uint16 ry);
private:
    SDL_Surface *pantalla,*imgTanque,*imgEnemigos,*imgBala,*imgObjetos, *imgCifra;
};


#endif	/* _DIBUJANTE_H */

