#include <iostream>
#include "Supermercado.h"
using namespace std; 
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}


Supermercado::Supermercado(int n){

    this->n_cajas = n;
    cajas = new Cola[this->n_cajas];
}

void Supermercado::nuevoUsuario(int n,int id){

    this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){

    int i = 0;

    while(this->cajas[n].estaVacia() != true){

        if(i != n && this->cajas[i].estaVacia() != true){ //si el iterador esta en una caja que no es la caja que queremos cerrar y no esta vacia
            
            this->cajas[i].encolar(this->cajas[n].desencolar());
        }

        if(i == this->n_cajas){ //si el iterador ya ha llegado al numero de cajas que hay

            i = 0; //se reinicia para empezar el bucle otra vez

        }else{

            i++;
        }
    }   
}

int Supermercado::atenderUsuario(int n){

    int num = this->cajas[n].desencolar();

    return num;
}

bool Supermercado::cajaVacia(int n){

    if(this->cajas[n].estaVacia() == true){

        return true;
    }else{

        return false;
    }
}