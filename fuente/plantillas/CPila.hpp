#ifndef _CPILA_HPP_
#define _CPILA_HPP_


#include <iostream>
using namespace std;

#include <cstdlib>

template <typename TBase> class CPila{

public:
	CPila();
	~CPila();
	bool estaVacia();
	void apilar(TBase dat);
	TBase desapilar();
	TBase cabeza();
private:

struct TNodo{
	TBase dato;
	TNodo *sig;
};
	TNodo *top;
};

#include "CPila.cpp"

#endif
