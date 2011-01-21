/* 
 * File:   colisiones.hpp
 * Author: guillermo
 *
 * Created on 6 de mayo de 2009, 18:07
 */

#ifndef _COLISIONES_HPP
#define	_COLISIONES_HPP
#ifdef DEB
#include <iostream>
using namespace std;
#endif
#include <SDL/SDL.h>

namespace Colisiones {

    enum Col_Que {
        TANQUE, BALA, PARED, OBJETO, ENEM
    };

    typedef struct {
        Col_Que que;
        int col; // 0. No colision, 1. Si colision
        int zona;
        /* ---------
         * | 4 | 3 |
         * |---|---|
         * | 2 | 1 |
         * ---------
         */
    } TColision;

    TColision ColisionGenerica(float ax, float ay, Sint16 aw, Sint16 ah, float bx, float by, Sint16 bw, Sint16 bh);


}

#endif	/* _COLISIONES_HPP */

