/*
 * Orellana Ruiz, Guillermo;
 * 1ºB; Primera Convocatoria;
 * 2009-06-19
 */

#ifndef _CLISTAPOS_HPP_
#define _CLISTAPOS_HPP_

#include <cstdlib>

template<typename TElem>
class CListaPos {
public:
    CListaPos();
    CListaPos( CListaPos<TElem> &origen);
    ~CListaPos();
    void Agregar(int pos, TElem el);
    TElem Consultar(int pos);
    void Borrar(int pos);
    void Vaciar();
    bool esVacia();
    int Longitud();
    void CopiarLista(CListaPos<TElem> origen);

private:

    struct TNodo {
        TElem elem;
        TNodo *sig;
        TNodo *ant;
    };

    void iEsimo(int n);
    int menorDist(int n);

    TNodo *ini, *fin, *ultVis;
    int nEl, ind;
};

#include "CListaPos.cpp"

#endif