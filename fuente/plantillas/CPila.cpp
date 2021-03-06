template <typename TBase>
CPila<TBase>::CPila(){
	top = NULL;
}

template <typename TBase>
CPila<TBase>::~CPila(){
	while(!estaVacia()){
		desapilar();
	}
}

template <typename TBase>
bool CPila<TBase>::estaVacia(){
	return (top==NULL);
}

template <typename TBase>
void CPila<TBase>::apilar(TBase dat){
	TNodo *nuevo = new TNodo;
	nuevo->dato = dat;
	nuevo->sig=top;
	top = nuevo;
}

template <typename TBase>
TBase CPila<TBase>::desapilar(){
	TBase ret = -1;
	TNodo *aux;
	if(!estaVacia()){
		ret = top->dato;
		aux = top->sig;
		delete top;
		top = aux;
	} else {
		cout << "ERROR: Desapilando pila vacía" << endl;
		exit(1);
	}
	return ret;
}

template <typename TBase>
TBase CPila<TBase>::cabeza(){
	TBase ret;
	if(!estaVacia()){
		ret = top->dato;
	}
	return ret;
}

