
#include "CCola.hpp"

template <typename TElem>
CCola<TElem>::CCola() {
    cabeza = fin = NULL;
    nEl = 0;
}

template <typename TElem>
CCola<TElem>::CCola(const CCola<TElem> &cop) {
    cabeza = fin = NULL;
    nEl = 0;
    while (!cop.esVacia()) {
        this->encolar(cop.consulta());
    }
    if (this->nEl != cop.nEl) {
        exit(1);
    }
}

template <typename TElem>
CCola<TElem>::~CCola() {
    while (!esVacia()) {
        fin = cabeza;
        cabeza = cabeza->sig;
        delete fin;
    }
}

template <typename TElem>
void CCola<TElem>::encolar(TElem e) {
    TNodo *nuevo = new TNodo;
    nuevo->elem = e;
    nuevo->sig = NULL;
    nEl++;
    if (esVacia()) {
        fin = cabeza = nuevo;
    } else {
        fin->sig = nuevo;
        fin = nuevo;
    }
}

template <typename TElem>
TElem CCola<TElem>::consulta()const {
    TElem ret;
    if (!esVacia()) {
        ret = cabeza->elem;
    }
    return ret;
}

template <typename TElem>
void CCola<TElem>::descartar() {
    TNodo *aux = cabeza;
    if (!esVacia()) {
        cabeza = cabeza->sig;
        delete aux;
        nEl--;
    }
}

template <typename TElem>
bool CCola<TElem>::esVacia() const{
    return (cabeza == NULL);
}

template <typename TElem>
int CCola<TElem>::nElem() {
    return nEl;
}
