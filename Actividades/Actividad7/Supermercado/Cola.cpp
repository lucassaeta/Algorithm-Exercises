#include <iostream>
#include "Cola.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

Cola::Cola(){

    this->principio = NULL;
    this->final = NULL;
}

void Cola::encolar(int num){

    //cola es FIFO 

    //nodos se apuntan de abajo a arriba (principio al final) y final apunta a null
    Nodo *nodoNuevo;        
    nodoNuevo = new Nodo(num);
    
    if(estaVacia() == true){ //si no hay nadie en la cola (el primer nodo)
        
        this->principio = nodoNuevo; 
        this->final = nodoNuevo;
    }else{

        this->final->siguiente = nodoNuevo; //el final actual pasa a apuntar al nuevo nodo (nuevo final)
        this->final = nodoNuevo; //y se convierte el nuevonodo en el nuevo final
    }

}

int Cola::desencolar(){

    int llegada = this->principio->valor;
    
    this->principio = this->principio->siguiente; //el nuevo principio pasa a ser el nodo al que apuntaba el principio
    
    return llegada;
}

bool Cola::estaVacia(){

    if(this->principio == NULL){

        return true;
    }else{

        return false;
    }

}