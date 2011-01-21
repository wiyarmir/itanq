#ifndef _DICCIONARIO_HPP_
#define _DICCIONARIO_HPP_

template <typename TClave, typename TObj> class CDiccionario {
private:

    struct TNodo {
        TClave key;
        TObj nom;
        TNodo *sig;
    };
    TNodo *top;
public:
    CDiccionario();
    ~CDiccionario();
    void sumar(TClave clave, TObj coso);
    int encontrar(TClave clave);
    int medida();
    TObj elemento(TClave clave);
    TObj operator[](TClave clave);
};

#include "CDiccionario.cpp"
#endif
