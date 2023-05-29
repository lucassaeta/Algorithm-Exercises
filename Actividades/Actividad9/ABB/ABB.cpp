#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"
using namespace std;

ABB::ABB(){
	
  this->raiz = NULL;
	this->n = 0;
}

ABB::~ABB(){
	
  eliminarSubarbol(this->raiz);
}

void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

void ABB::insertar(int nuevoElemento){

  Nodo *nuevoNodo = new Nodo();
  Nodo *padreNodo = buscarHueco(raiz, nuevoElemento);
  
  nuevoNodo->contenido = nuevoElemento;

  if(this->n == 0){ //no hay nodos

    nuevoNodo->padre = NULL;
    this->raiz = nuevoNodo;
  }else{

    nuevoNodo->padre = padreNodo;

    if(padreNodo->contenido > nuevoElemento){

      padreNodo->hijoIzquierdo = nuevoNodo;
    }else{

      padreNodo->hijoDerecho = nuevoNodo;
    }
  }
  
  this->n++;
}

Nodo* ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){

  if(raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo == NULL){ //caso base 

    return raizSubarbol; 
  }else{
    
    if(raizSubarbol->contenido > elementoAInsertar){ //se tiene que ir a la izq
      
      if(raizSubarbol->hijoIzquierdo != NULL){

        return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
      }else{

        return raizSubarbol;
      }    
    }else if(raizSubarbol->contenido < elementoAInsertar){ //se tiene que ir a la der
      
      if(raizSubarbol->hijoDerecho != NULL){

        return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
      }else{

        return raizSubarbol;
      } 
    }
  }

  return raizSubarbol;
}

Nodo* ABB::buscar(int elementoABuscar){

  //assertdomjudge(this->n > 0);

  return buscarRecursivo(raiz, elementoABuscar);
}

Nodo* ABB::buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar){

  if(raizSubarbol->contenido == elementoABuscar){ //caso base

    return raizSubarbol;
  }else{
    
    if(elementoABuscar > raizSubarbol->contenido && raizSubarbol->hijoDerecho == NULL){ //casos en los que no existe
		  
      return NULL;
	  }else if(elementoABuscar < raizSubarbol->contenido && raizSubarbol->hijoIzquierdo == NULL){ // ''

      return NULL;
    }else if(elementoABuscar > raizSubarbol->contenido && raizSubarbol->hijoDerecho != NULL){ //seguir buscando
		  
      raizSubarbol = buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
	  }else if(elementoABuscar > raizSubarbol->contenido && raizSubarbol->hijoIzquierdo != NULL){ // ''
		  
      raizSubarbol = buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
	  }
  }

  return raizSubarbol;
}

void ABB::eliminar(int elementoAEliminar){

  eliminarNodo(buscar(elementoAEliminar));
}

Nodo* ABB::buscarMaximo(Nodo *raizSubarbol){
	
  if(raizSubarbol->hijoDerecho == NULL){
		
    return raizSubarbol;
	}else{
		
    return buscarMaximo(raizSubarbol->hijoDerecho);
	}
}

Nodo* ABB::buscarMinimo(Nodo *raizSubarbol){
	
  if(raizSubarbol->hijoIzquierdo == NULL){
		
    return raizSubarbol;
	}else{
		
    return buscarMaximo(raizSubarbol->hijoIzquierdo);
	}
}

int ABB::alturaNodo(Nodo *raizSubarbol){
	
  int altIzq = 0;
  int altDer = 0;

	if(raizSubarbol == NULL){ //caso base (no hay subarbol)
		
    return -1;
	}else if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL){ //ult nivel
		
    return 0;
	}else{
		
    altIzq = alturaNodo(raizSubarbol->hijoIzquierdo);
		altDer = alturaNodo(raizSubarbol->hijoDerecho);
		
		if(altDer > altIzq){
			
      return altDer + 1;
		}else{
			
      return altIzq + 1;
		}
	}
}

void ABB::eliminarNodo(Nodo *nodoParaEliminar){

  Nodo *nodoAux;

  if(nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL){

    if(nodoParaEliminar->padre->hijoIzquierdo == nodoParaEliminar){

      nodoParaEliminar->padre->hijoIzquierdo=NULL;

    }else if(nodoParaEliminar->padre->hijoDerecho == nodoParaEliminar){

      nodoParaEliminar->padre->hijoDerecho = NULL;

    }else{

      this->raiz = NULL;
    }
    
    delete nodoParaEliminar;
  
  }else if(nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho == NULL){ //nodo solo tiene un hijo izquierdo

    nodoAux = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
    int contenidoAux = nodoAux->contenido;
    nodoAux->contenido = nodoParaEliminar->contenido;
    nodoParaEliminar->contenido = contenidoAux;
    eliminarNodo(nodoAux);
  
  }else if(nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL){ //nodo solo tiene un hijo derecho
    
    nodoAux = buscarMinimo(nodoParaEliminar->hijoDerecho);
    int contenidoAux = nodoAux->contenido;
    nodoAux->contenido = nodoParaEliminar->contenido;
    nodoParaEliminar->contenido = contenidoAux;
    eliminarNodo(nodoAux);

  }else{ //nodo tiene ambos hijos
        
    if(alturaNodo(nodoParaEliminar->hijoIzquierdo) > alturaNodo(nodoParaEliminar->hijoDerecho)){ //alturaIzq > alturaDer

      nodoAux = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
      int contenidoAux = nodoAux->contenido;
      nodoAux->contenido = nodoParaEliminar->contenido;
      nodoParaEliminar->contenido = contenidoAux;
      eliminarNodo(nodoAux);

    }else{

      nodoAux = buscarMinimo(nodoParaEliminar->hijoDerecho);
      int contenidoAux = nodoAux->contenido;
      nodoAux->contenido = nodoParaEliminar->contenido;
      nodoParaEliminar->contenido = contenidoAux;
      eliminarNodo(nodoAux);
    }    
  }
}

bool ABB::esABB(){
  
  if(this->raiz == NULL){

    return true;
  }else{

    return esSubABB(raiz);
  } 
}

bool ABB::esSubABB(Nodo *raizSubarbol){

  if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL){ //caso base

    return true;
  }else if(raizSubarbol->hijoIzquierdo != NULL && raizSubarbol->hijoDerecho == NULL){ //si solo hijo izq

    if(raizSubarbol->hijoIzquierdo->contenido < raizSubarbol->contenido){
			
      return esSubABB(raizSubarbol->hijoIzquierdo);
		}
		
    return false;

  }else if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho != NULL){ //si solo hijo der

    if(raizSubarbol->hijoDerecho->contenido > raizSubarbol->contenido){
			
      return esSubABB(raizSubarbol->hijoDerecho);
		}

	  return false;

  }else{ //dos hijos

    if(raizSubarbol->hijoIzquierdo->contenido < raizSubarbol->contenido && raizSubarbol->hijoDerecho->contenido > raizSubarbol->contenido){

      return esSubABB(raizSubarbol->hijoIzquierdo) + esSubABB(raizSubarbol->hijoDerecho);
    }else{

      return false;
    }
  }
}

bool ABB::esAVL(){
	
  if(this->raiz == NULL){

    return true;
  }else if(esABB()){
		
   return esSubAVL(this->raiz);
  }else{
		
    return false;
  }
}

bool ABB::esSubAVL(Nodo *raizSubarbol){
	
  int alturaIzquierda = alturaNodo(raizSubarbol->hijoIzquierdo);
  int alturaDerecha = alturaNodo(raizSubarbol->hijoDerecho);

	if(abs(alturaIzquierda - alturaDerecha) < 2){
		
    return true;

	}else{
		
    return false;

	}
}

void ABB::eliminarSubarbol (Nodo *raizSubarbol){
	
  if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL){ //caso base (si no continua)
    
    delete raizSubarbol;
  }
  else if(raizSubarbol->hijoIzquierdo != NULL && raizSubarbol->hijoDerecho == NULL){ //si solo hijo izq
    
    eliminarSubarbol(raizSubarbol->hijoIzquierdo);
    delete raizSubarbol;

  }else if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho != NULL){ //si solo hijo der

    eliminarSubarbol(raizSubarbol->hijoDerecho);
    delete raizSubarbol;

  }else{ //dos hijos

    eliminarSubarbol(raizSubarbol->hijoIzquierdo);
    eliminarSubarbol(raizSubarbol->hijoDerecho);
    delete raizSubarbol;
  }
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}


