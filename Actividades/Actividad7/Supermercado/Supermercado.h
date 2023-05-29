#include"Cola.h"

class Supermercado
{
private:
  Cola *cajas; //array de cajas en el supermercado 
  int n_cajas; //num de cajas

public:
  Supermercado(int n);
  void nuevoUsuario(int n,int id);  
  void cerrarCaja(int n);  
  int atenderUsuario(int n);
  bool cajaVacia(int n);
};
