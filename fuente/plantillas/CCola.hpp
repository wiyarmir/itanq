#ifndef _CCOLA_HPP_
#define _CCOLA_HPP_

#include <cstdlib>

template <typename TElem>
class CCola {
private:

    struct TNodo {
        TElem elem;
        TNodo *sig;
    };
    TNodo *cabeza;
    TNodo *fin;
    int nEl;
public:
    CCola();
    CCola(const CCola<TElem> &cop);
    ~CCola();
    void encolar(TElem e);
    TElem consulta()const;
    void descartar();
    bool esVacia()const;
    int nElem();
};

#include "CCola.cpp"
#endif
