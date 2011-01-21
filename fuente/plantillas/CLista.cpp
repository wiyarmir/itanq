template <typename TElem>
CLista<TElem>::CLista() {
    lis = fin = NULL;
    nEl = 0;
}

template <typename TElem>
CLista<TElem>::CLista(const CLista<TElem> &cop) {
    this->lis = this->fin = NULL;
    nEl = 0;
    int i = 0;
    while (i < cop.nEl) {
        this->insertar(cop.extraer(i));
        i++;
    }
}

template <typename TElem>
CLista<TElem>::~CLista() {
    TNodo *aux;
    while (!esVacia()) {
        aux = lis;
        lis = lis->sig;
        delete aux;
    }
}

template <typename TElem>
void CLista<TElem>::insertar(TElem el) {
    TNodo *nuevo = new TNodo;
    nuevo->elem = el;
    nuevo->sig = NULL;
    if (esVacia()) {
        fin = lis = nuevo;
    } else {
        fin->sig = nuevo;
        fin = nuevo;
    }
    nEl++;
}

template <typename TElem>
TElem CLista<TElem>::extraer(int pos) {
    TElem ret;
    int p = 0;
    TNodo *aux = lis;
    while (!esVacia() && p < pos) {
        aux = aux->sig;
        p++;
    }
    if (p == pos) {
        ret = aux->elem;
    }
    return ret;
}

template <typename TElem>
void CLista<TElem>::borrar(int pos) {
    int p = 0;
    TNodo *aux = lis, *ante = NULL;
    while (!esVacia() && p < pos) {
        ante = aux;
        aux = aux->sig;
        p++;
    }
    if (p == pos) {
        if (ante == NULL) {
            lis = lis->sig;
        } else {
            ante->sig = aux->sig;
        }
        delete aux;
        nEl--;
    }
}

template <typename TElem>
bool CLista<TElem>::esVacia() {
    return (lis == NULL);
}

template <typename TElem>
int CLista<TElem>::nElem() {
    return nEl;
}

