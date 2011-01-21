/* 
 * File:   Control.h
 * Author: guillermo
 *
 * Created on 5 de abril de 2009, 16:45
 */

#ifndef _JUEGO_H
#define	_JUEGO_H
#ifdef DEB
#include <iostream>
using namespace std;
#endif
#include <fstream>
#include <SDL/SDL.h>
#include "plantillas/CCola.hpp"
#include "plantillas/CLista.hpp"
#include "dibujante.h"
#include "tanque.h"
#include "bala.h"
#include "boton.h"
#include "cifra.h"
#include "enemigos.h"
#include "objeto.h"
#include "colisiones.hpp"
using namespace Colisiones;

#define TLIMGR 23
#define TLIMEV 3

class Juego {
public:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();
    void tecla_pulsada(SDLKey tecla);
    void tecla_libre(SDLKey tecla);
    void movimiento();
    void eventos();
    void colisiones();
    void pintadas();
    void cambiaEstado(Estado es);
    void actMouse(Uint16 x, Uint16 y);
    void actMouse(bool pressed);
    void finJuego();
    void liberaMem();
    void cargarMapList(const char* arch);
    void inicia_SDL();
    void Jugar();
private:
    Uint32 tiempo_gr, tiempo_ev;
    bool jugando, BRizq;
    CCola<string> mapas;
    string fond;
    CLista<Objeto> cosas;
    static const int nTecArr = 7;
    bool arrTeclas[nTecArr];
    SDL_Surface *pantalla, *fondo, *confirma, *icono;
    Estado e;
    Uint16 Mx, My;
    //Punteros a los objetos que controla
    Dibujante *pincel;
    Tanque *jugador;
    Enemigos *oponentes;
    Bala *bal;
    Boton *bsalir, *bjugar, *bSI, *bNO;
    Cifra *cif;
};

#endif	/* _CONTROL_H */

