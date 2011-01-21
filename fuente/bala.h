/* 
 * File:   bala.h
 * Author: guillermo
 *
 * Created on 25 de marzo de 2009, 18:28
 */

#ifndef _BALA_H
#define	_BALA_H
#ifdef DEB
#include <iostream>
using namespace std;
#endif
#include "tipos.h"
#include "tanque.h"

class Bala {
public:
    Bala();
    Bala(const char* pic, Uint16 lax, Uint16 lay, SDL_Surface *pantalla, Orientacion ori);
    Bala(const Bala& orig);
    virtual ~Bala();
    Sint16 diX();
    Sint16 diY();
    Sint16 diW() const;
    Sint16 diH() const;
    Orientacion diOr();
    Uint16 diCol() const;
    Uint16 diFil() const;
    void mov();
    bool colision(Tanque* t);
    bool fueraPantalla();
private:
    static const Uint8 BW = 10;
    static const Uint8 BH = 10;
    Uint8 img_col, img_fil;
    Sint16 x, y, dx, dy;
    Orientacion orient;
};


#endif	/* _BALA_H */

