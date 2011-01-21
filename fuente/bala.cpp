/* 
 * File:   bala.cpp
 * Author: guillermo
 *
 * Created on 25 de marzo de 2009, 18:28
 */

#include <SDL/SDL_video.h>

#include "bala.h"
#include "tanque.h"

Bala::Bala() { }

Bala::Bala(const char* pic, Uint16 lax, Uint16 lay, SDL_Surface *pantalla, Orientacion ori) {
#    ifdef DEB
    cout << "\tbala>Creando bala" << endl;
#    endif
    Uint16 vTemp = 5;
    img_fil = 0;
    img_col = 0;
    x = lax;
    y = lay;
    dx = dy = 0;
    switch (ori) {
        case ARR:dy = -vTemp;
            break;
        case ABA:dy = vTemp;
            break;
        case IZQ:dx = -vTemp;
            break;
        case DER:dx = vTemp;
            break;
    }
    orient = ori;
}

Bala::Bala(const Bala& orig) { }

Bala::~Bala() {
#    ifdef DEB
    cout << "\tbala>Liberando bala" << endl;
#    endif
}

Sint16 Bala::diX() {
    return x;
}

Sint16 Bala::diY() {
    return y;
}

Sint16 Bala::diW() const {
    return BW;
}

Sint16 Bala::diH() const {
    return BH;
}

Orientacion Bala::diOr() {
    return orient;
}

Uint16 Bala::diCol() const {
    return img_col;
}

Uint16 Bala::diFil() const {
    return img_fil;
}

void Bala::mov() {
    x += dx;
    y += dy;
}

bool Bala::fueraPantalla() {
    bool ret = false;
    if (x < 0 || x > RES_W || y < 0 || y > RES_H) {
        ret = true;
    }
    return ret;
}

bool Bala::colision(Tanque* t) {
    bool col = false;

    if ((t->diX() + 40 > this->x) && (t->diX() < this->x) && (this->y < t->diY() + 40) && (this->y > t->diY())) {
        col = true;
    }
    return col;
}
