#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;

Agenda::Agenda(int capacidad){
	
	this->capacidad = capacidad;
	this->n = 0;
	
	this->nombres = new string[this->capacidad];
	this->telefonos = new long[this->capacidad];
	this->vacias = new bool[this->capacidad];
	this->borradas = new bool[this->capacidad];
	
	for(int i = 0; i < capacidad; i++){
		
		this->vacias[i] = true;
		this->borradas[i] = false;
	}
}

Agenda::~Agenda(){
	
	delete[] this->nombres;
	delete[] this->telefonos;
	delete[] this->vacias;
	delete[] this->borradas;
}

int Agenda::obtenerPosicion(long telefono){

	return telefono % this->capacidad;
}

int Agenda::buscarContacto(long telefono){ 

//hacer una búsqueda a partir de esta posición. 
//Esta función devolverá la posición donde se encuentra o -1 en caso de no encontrarse.

	for(int i = obtenerPosicion(telefono); i<this->capacidad; i++){

		if(this->telefonos[i] == telefono && this->vacias[i] == false){

			return i;
		}else if(i == this->capacidad-1){

			for(int j = 0; j<obtenerPosicion(telefono); j++){

				if(this->telefonos[i] == telefono && this->vacias[i] == false){

					return j;
				}
			}
		}
	}

	return -1;
}

int Agenda::buscarHueco(long telefono){
	
	for(int i = obtenerPosicion(telefono); i<this->capacidad; i++){

		if(this->vacias[i] == true || this->borradas[i] == true){

			return i;
		}else if(i == this->capacidad-1){

			for(int j = 0; j<obtenerPosicion(telefono); j++){

				if(this->vacias[i] == true || this->borradas[i] == true){

					return j;
				}
			}
		}
	}
	
	return -1;
}

bool Agenda::isLlena(){
	
	if(this->n == this->capacidad){
		
		return true;
	}else{
		
		return false;
	}
}

bool Agenda::existeContacto(long telefono){
	
	for(int i = 0; i<capacidad; i++){
		
		if(this->vacias[i] == false && this->borradas[i] == false && this->telefonos[i] == telefono){
			
			return true;
		}
	}
	
	return false;
}

string Agenda::getContacto (long telefono){

	assertdomjudge(existeContacto(telefono) == true);

	return this->nombres[buscarContacto(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto){

	assertdomjudge(isLlena() == false && buscarHueco(telefono) != -1);

	int pos = buscarHueco(telefono);

	this->telefonos[pos] = telefono;
	this->nombres[pos] = contacto; 
	this->vacias[pos] = false;

	this->n++;
}

void Agenda::eliminarContacto(long telefono){

	assertdomjudge(existeContacto(telefono) == true);

	int pos = buscarContacto(telefono);

	this->borradas[pos] = true;
	this->vacias[pos] = true;

	this->n--;
}

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

