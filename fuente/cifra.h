/* 
 * File:   cifra.h
 * Author: guillermo
 *
 * Created on 16 de abril de 2009, 17:14
 */

#ifndef _CIFRA_H_
#define	_CIFRA_H_

#ifdef DEB
#include <iostream>
using namespace std;
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Cifra {
public:
    Cifra(const char* pic, Uint8 cmax, Sint16 lax, Sint16 lay);
    Cifra(const Cifra& orig);
    virtual ~Cifra();
   void dibujate(SDL_Surface* pantalla);
   void actImg(SDL_Surface* pantalla);
   void incrementa();
   void resetea();
private:
    Uint16 h, w;
    Uint8 cifmax, nact, nant;
    Sint16 x, y;
    SDL_Surface *img, *src;
    static const Uint8 imgw = 20, imgh = 20;
};



#endif	/* _CIFRA_H */

