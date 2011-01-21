#ifndef _CLISTA_HPP_
#define _CLISTA_HPP_

#include <cstdlib>

template <typename TElem> class CLista{
	private:
	struct TNodo{
		TElem elem;
		TNodo *sig;
	};
	TNodo *lis, *fin;
	int nEl;
	
	public:
	CLista();
        CLista(const CLista<TElem> &cop) ;
	~CLista();
	void insertar(TElem el);
	TElem extraer(int pos);
	void borrar(int pos);
	bool esVacia();
	int nElem();
};

#include "CLista.cpp"
#endif

