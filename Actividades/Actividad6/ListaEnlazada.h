#pragma once
#include "Nodo.h"

class ListaEnlazada
{
	Nodo *lista; //apunta al primer nodo de la lista

	int n; //num elementos

	Nodo * getNodo (int posicion);

public:

	ListaEnlazada();

	int getValor(int posicion);

	void setValor(int posicion, int nuevoValor);

	int getN(); 

	void insertar (int posicion, int nuevoValor);

	void eliminar (int posicion);

	void concatenar(ListaEnlazada *listaAConcatenar);

	int buscar(int elementoABuscar);

	~ListaEnlazada();
};







