#include"Nodo.h"  
class Cola
{
 private:
  Nodo *principio; //apunta a la primera posicion (primer nodo)
  Nodo *final; //apunta al final de la cola (ultimo nodo)
 
 public:
  Cola();
  void encolar(int num);  
  int desencolar();
  bool estaVacia();  
};

  
