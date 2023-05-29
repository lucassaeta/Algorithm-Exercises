#include "Pila.h"

Pila::Pila(string name){

  this->name = name;
  this->cima = NULL;

}

std::string Pila::nombrePila(){

  return this->name;

}

void Pila::apilar(int num){

  Nodo *nodoNuevo; 
  nodoNuevo = new Nodo(num, this->cima);
  
  //nodos apuntan de cima para abajo
  
  //nodoNuevo->siguiente = this->cima; //el nuevo que entra pasa a apuntar a la cima actual
  this->cima = nodoNuevo; //y se convierte en la nueva cima 

  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
}
  
int Pila::desapilar(){    

  //Pila es LIFO
  
  int num = this->cima->valor;

  this->cima = this->cima->siguiente;
  
  cout<<"Desapilando disco "<<num<<" del poste "<<name<<endl;

  return num;

}

bool Pila::estaVacia(){

  if(this->cima == NULL){

    return true;
  }else{

    return false;
  }

}

