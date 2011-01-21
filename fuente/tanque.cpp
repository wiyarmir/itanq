/* 
 * File:   tanque.cpp
 * Author: guillermo
 *
 * Created on 25 de marzo de 2009, 18:19
 */


#include "tanque.h"

Tanque::Tanque() { }

Tanque::Tanque(Uint16 iw, Uint16 ih, float lax, float lay, float vi, Uint16 i_f, Uint16 i_c) {
    img_fil = i_f;
    img_col = i_c;
    h = ih;
    w = iw;
    x = lax;
    y = lay;
    mov = vi;
    dx = dy = mov;
    orient = ARR;
}

Tanque::Tanque(const Tanque& orig) { }

Tanque::~Tanque() {
#    ifdef DEB
    cout << "tanque>Liberando tanque" << endl;
#    endif
}

bool Tanque::colision(Tanque *t) {
    bool ret = false;
    //Uint8 vert =
    return ret;
}

bool Tanque::dentro_tabl(Orientacion ori) {
    bool ret = false;
    switch (ori) {
        case ARR:
            if ((y - dy) > LIMIY) {
                ret = true;
            }
            break;
        case DER:
            if ((x + dx) < LIMSX) {
                ret = true;
            }
            break;
        case ABA:
            if ((y + dy) < LIMSY) {
                ret = true;
            }
            break;
        case IZQ:
            if ((x - dx) > LIMIX) {
                ret = true;
            }
            break;
    }
    return ret;
}

void Tanque::ve(Orientacion ori) {
    switch (ori) {
        case ARR:
            y -= dy;
            break;
        case ABA:
            y += dy;
            break;
        case IZQ:
            x -= dx;
            break;
        case DER:
            x += dx;
            break;
    }
}

void Tanque::mira(Orientacion ori) {
    switch (ori) {
        case ARR:
            orient = ARR;
            break;
        case ABA:
            orient = ABA;
            break;
        case IZQ:
            orient = IZQ;
            break;
        case DER:
            orient = DER;
            break;
    }
}

float Tanque::diX() const {
    return x;
}

float Tanque::diY() const {
    return y;
}

Sint16 Tanque::diH() const {
    return h;
}

Sint16 Tanque::diW() const {
    return w;
}

Orientacion Tanque::diOr() const {
    return orient;
}

Uint16 Tanque::diCol() const {
    return img_col;
}

Uint16 Tanque::diFil() const {
    return img_fil;
}

void Tanque::destruir() {
#    ifdef DEB
    cout << "\ttanque>Destruido!" << endl;
#    endif
    //animacion???

}

