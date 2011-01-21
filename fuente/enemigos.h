/* 
 * File:   enemigos.h
 * Author: guillermo
 *
 * Created on 21 de abril de 2009, 11:43
 */

#ifndef _ENEMIGOS_H
#define	_ENEMIGOS_H


#ifdef DEB
#include <iostream>
using namespace std;
#endif
#include <map>
using namespace std;
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "tipos.h"
#include "tanque.h"
#include "bala.h"
#include "objeto.h"
#include "colisiones.hpp"
using namespace Colisiones;
#include "plantillas/CCola.hpp"
#include "plantillas/CListaPos.hpp"

enum EnHace {
    PARADO, MARR, MABA, MIZQ, MDER, PERSIGO
};

float distancia(float x1, float y1, float x2, float y2);

class Enemigos {
public:
    Enemigos();
    Enemigos(const Enemigos& orig);
    virtual ~Enemigos();
    void agnadirEnems(int nEnems = 1);
    void elimEnem(Uint8 n);
    void actualizaEnem(const float tx, const float ty);
    bool teHeVisto(float ex, const float ey, const float tx, const float ty);
    void orientate(Tanque *t, const float tx, const float ty);
    //    void compruebaBala(TNodoEnem *e);
    void persigue(Tanque *t, const float tx, const float ty);
    void dispara(const Tanque *t);
    void decide(Tanque *t);
    EnHace numToEstado(Uint8 rand);
    bool esLaHora(int ind, Uint32 tAhora);
    void colisiones(Tanque* j, Bala* b, CCola<TColision> &col);
    Uint8 numEnem();
    Tanque *selecEnem(int n);
    Bala *selecBala(int n);


private:
    static const Uint16 tRefresh = 5000;
    static const Uint16 tMargen = 1;
    Uint8 nEnem;
    float rango, vi;
    Tanque* enems[MAXENEM];
    Bala* balas[MAXENEM];
    CListaPos<Punto> PRespawn;
    Sint32 tiempos[MAXENEM];
};

#endif	/* _ENEMIGOS_H */
