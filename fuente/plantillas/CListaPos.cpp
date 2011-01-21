/*
 * Orellana Ruiz, Guillermo;
 * 1ºB; Primera Convocatoria;
 * 2009-06-19
 */

template <typename TElem>
CListaPos<TElem>::CListaPos() {
    ini = new TNodo;
    fin = new TNodo;
    ultVis = ini;
    ini->sig = fin;
    fin->ant = ini;
    ini->ant = fin->sig = NULL;
    nEl = ind = 0;
}

template <typename TElem>
CListaPos<TElem>::CListaPos(CListaPos<TElem> &origen) {//Copia de CopiarLista para evitar llamadas recursivas si llamo a la funcion
    ini = new TNodo;
    fin = new TNodo;
    ultVis = ini;
    ini->sig = fin;
    fin->ant = ini;
    ini->ant = fin->sig = NULL;
    nEl = ind = 0;
    int l = origen.Longitud();
    for (int i = 1; i <= l; i++) {
        Agregar(i, origen.Consultar(i));
    }
}

template <typename TElem>
CListaPos<TElem>::~CListaPos() {
    TNodo *aux;
    ultVis = ini;
    while (ultVis != NULL) {
        aux = ultVis;
        ultVis = ultVis->sig;
        delete aux;
    }
}

template<typename TElem>
void CListaPos<TElem>::Agregar(int pos, TElem el) {
    TNodo *nuevo;
    if (pos >= 1 && pos <= nEl + 1) {
        nuevo = new TNodo;
        nuevo->elem = el;
        if (pos == nEl + 1) {
            ultVis = fin; //Para evitar duplicar codigo
        } else {
            iEsimo(pos);
        }
        ultVis->ant->sig = nuevo;
        nuevo->ant = ultVis->ant;
        ultVis->ant = nuevo;
        nuevo->sig = ultVis;
        ultVis = nuevo; //Actualizo el valor final de ultVis
        ind = pos; //Y pos también
        nEl++;
    }
}

template<typename TElem>
TElem CListaPos<TElem>::Consultar(int pos) {
    if (pos >= 1 && pos <= nEl) {
        iEsimo(pos);
        return (ultVis->elem);
    }
}

template<typename TElem>
void CListaPos<TElem>::Borrar(int pos) {
    TNodo *aux;
    iEsimo(pos);
    aux = ultVis->sig;
    ultVis->ant->sig = ultVis->sig;
    ultVis->sig->ant = ultVis->ant;
    delete ultVis;
    ultVis = aux;
    nEl--;
    if (ultVis == fin) {
        ultVis = fin->ant;
        ind = nEl;
    }
}

template<typename TElem>
void CListaPos<TElem>::Vaciar() {
    if (nEl > 0) {
        while (ini->sig != fin) {
            ultVis = ini;
            ini = ini->sig;
            delete ultVis;
        }
        nEl = 0;
        ultVis = ini;
        ind = 0;
    }
}

template<typename TElem>
bool CListaPos<TElem>::esVacia() {
    return (nEl == 0);
}

template<typename TElem>
int CListaPos<TElem>::Longitud() {
    return nEl;
}

//MÉTODOS PRIVADOS

template<typename TElem>
void CListaPos<TElem>::iEsimo(int n) {
    int paso, dir;
    if (n >= 1 && n <= nEl + 1) {
        if (n != ind) { //Si preguntáramos por el índice actual de ultVis, ya estamos
            dir = menorDist(n);
            switch (dir) {
                case 0: //Inicio hacia delante
                    ultVis = ini->sig;
                    paso = 1;
                    ind = 1;
                    break;
                case 1: //ultVis hacia atrás
                    paso = -1;
                    break;
                case 2: //ultVis hacia delante
                    paso = 1;
                    break;
                case 3: //Fin hacia atrás
                    ultVis = fin->ant;
                    paso = -1;
                    ind = nEl;
                    break;
            }
            if (paso == 1) { //Hacia delante
                while (ind < n) {
                    ultVis = ultVis->sig;
                    ind++;
                }
            } else { //Hacia detrás
                while (ind > n) {
                    ultVis = ultVis->ant;
                    ind--;
                }
            }
        }
    }
}

template<typename TElem>
int CListaPos<TElem>::menorDist(int n) {
    int m;
    if (n > ind) {//Si esta desde el ultVis en adelante
        if (n - ind > nEl - n) { //Si es mas largo desde el ultVis hacia delante que desde el fin
            //hacia detrás
            m = 3; //Fin hacia atrás
        } else {
            m = 2; //ultVis hacia delante
        }
    } else {//Esta del ultVis hacia atras
        if (ind - n > n) {//Si distancia desde ultVis hacia atras es mayor que desde inicio hacia
            //delante
            m = 0; //Inicio hacia delante
        } else {
            m = 1; //ultVis hacia atrás
        }
    }
    return m;
}

template<typename TElem>
void CListaPos<TElem>::CopiarLista(CListaPos<TElem> origen) {
    Vaciar();
    int l = origen.Longitud();
    for (int i = 1; i <= l; i++) {
        Agregar(i, origen.Consultar(i));
    }
}
