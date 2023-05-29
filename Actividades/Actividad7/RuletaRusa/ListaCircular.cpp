#include <iostream>
#include "ListaCircular.h"
using namespace std; 

ListaCircular::ListaCircular(){

    this->lista = NULL;
    this->n = 0;
}

ListaCircular::~ListaCircular(){

    Nodo *nodo;
    Nodo *nodoAux;
    nodo = this->lista; //para que empiece borrando desde el primero

    for(int i = 0; i<this->n; i++){
        
        nodoAux = nodo;
        nodo = nodo->siguienteNodo;
        delete nodoAux; 
    }
    
    delete nodo;
}

Nodo * ListaCircular::getNodo (int pos){

    Nodo *nodo; 
    nodo = this->lista;

    if(pos > 0){
        
        for(int i = 0; i<pos; i++){

            nodo = nodo->siguienteNodo;
        }
    
    }else{
        
        for(int i = 0; i>pos; i--){

            nodo = nodo->anteriorNodo;
        }
    }   
    return nodo;
}

string ListaCircular::getValor(int posicion){
    
    Nodo *nodo; 
    nodo = getNodo(posicion); 

    return nodo->elemento;
}

void ListaCircular::setValor(int posicion, string nuevoValor){ 
    
    Nodo *nodo; 
    nodo = getNodo(posicion);
    nodo->elemento = nuevoValor;
}

int ListaCircular::getN(){

    return this->n;
}

void ListaCircular::insertar(int posicion, string nuevoValor){

    Nodo *nodoAux;
    Nodo *nodoNuevo = new Nodo();

    nodoNuevo->elemento = nuevoValor;

    if(posicion == 0 && this->n == 0){ //primer nodo de lista

        this->lista = nodoNuevo;
        nodoNuevo->siguienteNodo = NULL;
        nodoNuevo->anteriorNodo = NULL;
    }else if(posicion == 0){ //insertar nodo en primera posicion

        this->lista->anteriorNodo->siguienteNodo = nodoNuevo;
        nodoNuevo->siguienteNodo = this->lista; 
        nodoNuevo->anteriorNodo = this->lista->anteriorNodo;
        this->lista->anteriorNodo = nodoNuevo;
        this->lista = nodoNuevo; 
    }else if(posicion == n){ //insertar nodo en ultima posicion

        nodoAux = getNodo(n-1);
        nodoAux->siguienteNodo = nodoNuevo;
        nodoNuevo->anteriorNodo = nodoAux;
        nodoNuevo->siguienteNodo = this->lista;
    }else{

        nodoAux = getNodo(posicion);
        nodoAux->siguienteNodo->anteriorNodo = nodoNuevo;
        nodoNuevo->siguienteNodo = nodoAux->siguienteNodo; 
        nodoAux->siguienteNodo = nodoNuevo;  
    }
    
    this->n++;
}