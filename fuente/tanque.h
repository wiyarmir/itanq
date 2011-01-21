/* 
 * File:   tanque.h
 * Author: guillermo
 *
 * Created on 25 de marzo de 2009, 18:19
 */

#ifndef _TANQUE_H
#define	_TANQUE_H
#ifdef DEB
#include <iostream>
using namespace std;
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "tipos.h"

class Tanque {
public:
    Tanque();
    Tanque(Uint16 iw, Uint16 ih, float lax, float lay, float vi,  Uint16 i_f = 0, Uint16 i_c = 0);
    Tanque(const Tanque& orig);
    virtual ~Tanque();
    bool dentro_tabl(Orientacion ori);
    bool colision(Tanque *t);
    void mira(Orientacion ori);
    void ve(Orientacion ori);
    float diX() const;
    float diY() const;
    Sint16 diW() const;
    Sint16 diH() const;
    Orientacion diOr() const;
    void destruir();
    Uint16 diCol() const;
    Uint16 diFil() const;
private:
    static const Uint16 LIMIX = 0;
    static const Uint16 LIMSX = 760;
    static const Uint16 LIMIY = 0;
    static const Uint16 LIMSY = 560;
    float x, y;
    Uint16 w, h;
    Uint16 img_col, img_fil;
    float mov;
    float dx, dy;
    Orientacion orient;
};



#endif	/* _TANQUE_H */

