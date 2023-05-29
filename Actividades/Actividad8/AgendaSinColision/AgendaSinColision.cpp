#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"
using namespace std;

Agenda::Agenda(int capacidad){

	this->capacidad = capacidad; 
	this->nombres = new string[this->capacidad];
	this->telefonos = new long[this->capacidad];
	this->ocupados = new bool[this->capacidad];

	for(int i = 0; i<capacidad; i++){
		this->ocupados[i] = false;
	}
}

Agenda::~Agenda(){

	delete[] this->nombres; 
	delete[] this->telefonos; 
	delete[] this->ocupados;
}

int Agenda::obtenerPosicion(long telefono){

	return telefono % this->capacidad;
}

bool Agenda::existeContacto(long telefono){

	if(this->ocupados[obtenerPosicion(telefono)] == true && this->telefonos[obtenerPosicion(telefono)] == telefono){

		return true;
	}else{

		return false;
	}
}

string Agenda::getContacto(long telefono){

	assertdomjudge(existeContacto(telefono) == true);
	
	return this->nombres[obtenerPosicion(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto){

	assertdomjudge(this->ocupados[obtenerPosicion(telefono)] == false);
	this->telefonos[obtenerPosicion(telefono)] = telefono;
	this->nombres[obtenerPosicion(telefono)] = contacto;
	this->ocupados[obtenerPosicion(telefono)] = true;
}

void Agenda::eliminarContacto(long telefono){

	assertdomjudge(existeContacto(telefono) == true);

	this->ocupados[obtenerPosicion(telefono)] = false;
}

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}


