#include <iostream>
#include <stdlib.h>
#include "ListaEnlazada.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;


ListaEnlazada::ListaEnlazada(){

    this->n = 0;
    this->lista = NULL;
}

ListaEnlazada::~ListaEnlazada(){

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

Nodo * ListaEnlazada::getNodo (int pos){

    Nodo *nodo; 
    nodo = this->lista;

    for(int i = 0; i<pos; i++){

        nodo = nodo->siguienteNodo;
    }

    return nodo;
}

Contacto ListaEnlazada::getValor(int posicion){

    assertdomjudge(posicion >= 0 && posicion < n);
    
    Nodo *nodo; 
    nodo = getNodo(posicion); 

    return nodo->elemento;
}

void ListaEnlazada::setValor(int posicion, Contacto nuevoValor){ //error en enunciado * int ---> void *

    assertdomjudge(posicion >= 0 && posicion < n);
    
    Nodo *nodo; 
    nodo = getNodo(posicion);

    nodo->elemento = nuevoValor;
}

int ListaEnlazada::getN(){

    return this->n;
}

void ListaEnlazada::insertar(int posicion, Contacto nuevoValor){

    assertdomjudge(posicion >= 0 && posicion <= n);

    Nodo *nodoAux;
    Nodo *nodoNuevo = new Nodo();

    nodoNuevo->elemento = nuevoValor;

    if(posicion == 0 && this->n == 0){

        this->lista = nodoNuevo;
        nodoNuevo->siguienteNodo = NULL;
    }else if(posicion == 0){

        nodoNuevo->siguienteNodo = this->lista; //apunta al que es el nuevo nodo actualmente
        this->lista = nodoNuevo; //y se pone como el nuevo primer nodo
    }else if(posicion == n){

        nodoAux = getNodo(n-1);
        nodoAux->siguienteNodo = nodoNuevo; 
        nodoNuevo->siguienteNodo = NULL;
    }else{

        nodoAux = getNodo(posicion);
        nodoNuevo->siguienteNodo = nodoAux->siguienteNodo; 
        nodoAux->siguienteNodo = nodoNuevo;  
    }
    
    this->n++;
}

void ListaEnlazada::eliminar(int posicion){

assertdomjudge(posicion >= 0 && posicion < n);

    Nodo *nodoBorrar; 
    Nodo *nodoAux;
    Nodo *nodoAux2;
    nodoBorrar = getNodo(posicion);

    if(posicion == 0){

        this->lista = getNodo(1);
    }else if(posicion == n-1){

        nodoAux = getNodo(n-2);
        nodoAux->siguienteNodo = NULL;
    }else{

        nodoAux = getNodo(posicion-1);
        nodoAux2 = nodoBorrar->siguienteNodo;
        nodoAux->siguienteNodo = nodoAux2;  
    }
    
    this->n--;    
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){ //error en enunciado * ListaContigua --> ListaEnlazada *

    assertdomjudge(listaAConcatenar->n > 0 && listaAConcatenar != NULL);
    Nodo *nodo;

    if(this->n == 0){

        this->lista = listaAConcatenar->getNodo(0); // o lista tb serviria

    }else{

        nodo = getNodo(n-1);
        nodo->siguienteNodo = listaAConcatenar->getNodo(0);
    }

    this->n += listaAConcatenar->n;
}

int ListaEnlazada::buscar(Contacto elementoABuscar){

    //assertdomjudge(this->n > 0);
    int pos = -1;

    for(int i = 0; i<n; i++){

        if (getValor(i).telefono == elementoABuscar.telefono){

            pos = i;
        }
    }
    
    return pos;
}
