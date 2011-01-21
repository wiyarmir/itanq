/* 
 * File:   objeto.h
 * Author: guillermo
 *
 * Created on 8 de mayo de 2009, 10:51
 */

#ifndef _OBJETO_H
#define	_OBJETO_H

#ifdef DEB
#include <iostream>
using namespace std;
#endif

#include <cstdlib>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "tipos.h"

class Objeto {
public:
    Objeto();
    Objeto(SDL_Surface *pantalla, const char* pic, Uint16 iw, Uint16 ih, float lax, float lay, Uint16 i_f = 0, Uint16 i_c = 0);
    void inicializa(SDL_Surface *pantalla, const char* pic, Uint16 iw, Uint16 ih, float lax, float lay, Uint16 i_f = 0, Uint16 i_c = 0);
    Objeto(const Objeto& orig);
    virtual ~Objeto();
    void dibujate(SDL_Surface *pantalla);

    bool iniciado() {
        return inicializado;
    }

protected:
    bool inicializado;
    float x, y;
    Uint16 w, h;
    Uint16 img_col, img_fil;
    SDL_Rect corte;
    SDL_Surface *img;

private:
};

SDL_Surface* creaSuperficieVacia(int w, int h);
#endif	/* _OBJETO_H */

