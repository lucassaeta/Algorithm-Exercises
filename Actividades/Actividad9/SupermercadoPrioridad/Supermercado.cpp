#include <iostream>
#include "Supermercado.h"
using namespace std;

Supermercado::Supermercado(int n){
	
    this->n_cajas = n;
	this->cajas = new ColaPrioridad[this->n_cajas];
}

void Supermercado::nuevoUsuario(int n,int id){

	this->cajas[n].encolar(id);
}

int Supermercado::atenderUsuario(int n){ 
    
	return this->cajas[n].desencolar(); 
} 

bool Supermercado::cajaVacia(int n){ 

	if(this->cajas[n].estaVacia()){ 
		
		return true; 
	}else{ 
	
		return false; 
	}
}

void Supermercado::cerrarCaja(int n){

	int i = 0;

	while((this->cajas[n].estaVacia() != true)){

		if((this->cajas[i].estaVacia() != true) && i != n){

            int aux = this->cajas[n].desencolar();
            this->cajas[i].encolar(aux);
		}
				
        if (i == this->n_cajas - 1){
            i = 0;
        }else{
            
			i++;
        }
	}
} 
