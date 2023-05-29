#include<iostream>
#include <string.h>
using namespace std;

struct Agenda{
  	
	private:
		int capacidad; //max numero contactos
		int n;
		string* nombres;
		long* telefonos;
		bool* vacias; //indica si la posicion de la tabla hash esta ocupada
		bool* borradas;

	public:
		Agenda(int capacidad);
		~Agenda();
		int obtenerPosicion(long telefono); 
		int buscarContacto(long telefono); 
		int buscarHueco(long telefono); 
		bool isLlena();
		bool existeContacto(long telefono);
		string getContacto(long telefono);
		void introducirContacto (long telefono, string contacto);
		void eliminarContacto (long telefono);
		void imprimir();
};

