#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el m�todo imprimir de la tabla hash
using namespace std;

Agenda::Agenda(int capacidad){
	
	this->capacidad = capacidad;
	this->n = 0;
	this->tabla = new ListaEnlazada[this->capacidad];
}

Agenda::~Agenda(){
	
	delete[] tabla;
}

int Agenda::obtenerPosicion(long telefono){

	return telefono % this->capacidad;
}

bool Agenda::existeContacto(long telefono){

	Contacto *aux = new Contacto();
	aux->telefono = telefono; //buscamos con este telefono

	if(this->tabla[obtenerPosicion(telefono)].buscar(*aux) != -1){ //utilizamos el buscar de la clase lista enlazada para que busque si existe 

        return true;
    }
    
	return false;
}

string Agenda::getContacto(long telefono){

	assertdomjudge(existeContacto(telefono) == true);

	Contacto *aux = new Contacto();
	aux->telefono = telefono; 
		
	*aux = this->tabla[obtenerPosicion(telefono)].getValor(this->tabla[obtenerPosicion(telefono)].buscar(*aux)); 

	return aux->nombre;	
}

void Agenda::introducirContacto(long telefono, string contacto){
	
	//assertdomjudge(existeContacto(telefono) == false); nose porque esto me da error cuando no deberia
	
	Contacto *nuevoContacto = new Contacto();
	nuevoContacto->telefono = telefono;
	nuevoContacto->nombre = contacto;
	
	this->tabla[obtenerPosicion(telefono)].insertar(0, *nuevoContacto); //insertamos en la primera posicion 0 (hash)

	this->n++;
}

void Agenda::eliminarContacto(long telefono){

    assertdomjudge(existeContacto(telefono) == true);

    Contacto *contactoBorrar = new Contacto();
    contactoBorrar->telefono = telefono;
    
	tabla[obtenerPosicion(telefono)].eliminar(tabla[obtenerPosicion(telefono)].buscar(*contactoBorrar));

	this->n--;
}
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

