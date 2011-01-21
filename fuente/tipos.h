/* 
 * File:   tipos.h
 * Author: guillermo
 *
 * Created on 21 de marzo de 2009, 19:02
 */

#ifndef _TIPOS_H
#define	_TIPOS_H

#include <cstdlib>

#ifdef DEB
#include <iostream>
using namespace std;
#endif

#include <SDL/SDL.h>

#define NOMBREAPP "iTanq"
#define TAM_TILE 40
#define RES_W 800
#define RES_H 600

#define MAXENEM 6

typedef enum {
    ARR, ABA, IZQ, DER
} Orientacion;

typedef struct {
    float x, y;
} Punto;

typedef enum {
    SALIR, JUEGO, MENU, SUBMENU, GAMEOVER, FINFASE
} Estado;

#endif	/* _TIPOS_H */
