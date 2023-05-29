#include <iostream>
#include "ColaPrioridad.h"
using namespace std;

bool ColaPrioridad::estaVacia(){
	
    if(this->vector.getN() == 0){
		
        return true;
	}else{
	    
        return false;
    }
}

void ColaPrioridad::encolar(int num){

	this->vector.insertarAlFinal(num);
	reestructurar();
}

int ColaPrioridad::desencolar(){

	int valor = vector.getValor(vector.getN()-1);
	
    vector.setValor(vector.getN()-1, vector.getValor(0));
	vector.eliminarAlFinal();
	reestructurar();
	
    return valor;
}

void ColaPrioridad::reestructurar(){

	for(int i = 0; i < vector.getN(); i++){
		for(int j = i+1; j < vector.getN(); j++){

			if(vector.getValor(j) > vector.getValor(i)){              
                
                int valorAux = vector.getValor(i);
                vector.setValor(i, vector.getValor(j));
                vector.setValor(j, valorAux);
            }
		}
	}
}

