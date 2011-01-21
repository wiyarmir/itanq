
#include "CDiccionario.hpp"

template <typename TClave, typename TObj>
CDiccionario<TClave, TObj>::CDiccionario() {
    top = NULL;
}

template <typename TClave, typename TObj>
CDiccionario<TClave, TObj>::~CDiccionario() {
    TNodo *aux = top;
    while (top != NULL) {
        top = top->sig;
        delete aux;
        aux = top;
    }
}

template <typename TClave, typename TObj>
void CDiccionario<TClave, TObj>::sumar(TClave clave, TObj coso) {
    TNodo *nuevo, *aux = top;
    while (aux != NULL && aux->key != clave) {
        aux = aux->sig;
    }
    if (aux == NULL) {
        nuevo = new TNodo;
        nuevo->key = clave;
        nuevo->nom = coso;
        nuevo->sig = top;
        top = nuevo;
    } else {
        aux->key = clave;
        aux->nom = coso;
    }
}

template <typename TClave, typename TObj>
int CDiccionario<TClave, TObj>::encontrar(TClave clave) {
    TNodo *aux;
    int ret = -1, c = 0;
    while (aux != NULL && aux->key != clave) {
        aux = aux->sig;
        c++;
    }
    if (aux != NULL) {
        ret = c;
    }
    return ret;
}

template <typename TClave, typename TObj>
TObj CDiccionario<TClave, TObj>::elemento(TClave clave) {
    TNodo *aux;
    TObj ret;
    while (aux != NULL && aux->key != clave) {
        aux = aux->sig;
    }
    if (aux != NULL) {
        ret = aux->nom;
    }
    return ret;
}

template <typename TClave, typename TObj>
int CDiccionario<TClave, TObj>::medida() {
    TNodo *aux;
    int ret = 0;
    while (aux != NULL) {
        aux = aux->sig;
        ret++;
    }
    return ret;
}

template <typename TClave, typename TObj>
TObj CDiccionario<TClave, TObj>::operator[](TClave clave) {
    TNodo *aux;
    TObj ret;
    while (aux != NULL && aux->key != clave) {
        aux = aux->sig;
    }
    if (aux != NULL) {
        ret = aux->nom;
    } else {
        ret = NULL;
    }
    return ret;
}
