#include<iostream>
#include <string.h>
using namespace std;

struct Agenda{
  	
	private:
		int capacidad; //max numero contactos
		string *nombres;
		long* telefonos;
		bool* ocupados; //indica si la posicion de la tabla hash esta ocupada

	public:
		Agenda(int capacidad);
		~Agenda();
		int obtenerPosicion(long telefono); 
		bool existeContacto(long telefono);
		string getContacto(long telefono);
		void introducirContacto (long telefono, string contacto);
		void eliminarContacto (long telefono);
		void imprimir();
};

