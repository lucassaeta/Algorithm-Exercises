#include <iostream>
#include <stdlib.h>
#include "ListaContigua.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

ListaContigua::ListaContigua(int incremento){
	
    this->incremento = incremento;
    this->vector = NULL;
	this->n = 0;
	this->capacidad = 0;
}

ListaContigua::~ListaContigua(){
	
    delete[] this->vector;
}

int ListaContigua::getValor(int posicion){
	
    assertdomjudge(posicion >= 0 && posicion < n);
	
	return this->vector[posicion];
}

void ListaContigua::setValor(int posicion, int nuevoValor){
	
    assertdomjudge(posicion >= 0 && posicion < n);
	
	this->vector[posicion] = nuevoValor;
}

int ListaContigua::getN(){
	
    return this->n;
}

int ListaContigua::getCapacidad(){
	
    return this->capacidad;
}

int ListaContigua::buscar(int elementoABuscar){
	
    assertdomjudge(this->n > 0);
	
	for(int i = 0; i<n; i++){

		if(vector[i] == elementoABuscar){
			
            return i;
		}
	}
	
    return -1;
}
