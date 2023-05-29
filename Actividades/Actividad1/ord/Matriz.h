#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 private:
 double **matriz;
  
  int n_filas;
  int n_columnas;

 public:

/* Constructor default. Crea una matriz que no tiene
elementos por tanto el número de filas y columnas será 0 y el
puntero matriz deberá apuntar a NULL.
	   Parámetro: ninguno
	   Retorno: una nueva matriz sin elementos.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(1)		//tiempo de compilacion o carga del algoritmo ( el maximo para los for, while, etc)
	   Complejidad Espacial: O(1)       //espacio en memoria, lo que ocupa memoria


*/
Matriz();

/* Constructor por parametros. Inicializalos atributos n_filas y n_columnas y
reserva de forma dinámica espacio suficiente para
poder almacenar una matriz con las dimensiones solicitadas. 
	   Parámetro:  la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas)
	   Complejidad Espacial: O(n_filas * n_columnas)


*/
Matriz(int n_filas, int n_columnas);

/* Constructor copia. Este constructor recibirá como parámetro
una matriz e inicializa su matriz con las mismas
dimensiones que las indicadas por el parámetro y además se
copian sus elementos.
	   Parámetro:  la matriz que va a copiar
	   Retorno: una nueva matriz copia de la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(1)
	   Complejidad Espacial: O(n_filas * n_columnas)


*/
Matriz(const Matriz &m); 

/* Implementa la sobrecarga del operador suma que permite sumar dos
matrices que tienen las mismas dimensiones. Este método
 crea una matriz nueva con las dimensiones de las
originales y que contiene la suma de ellas elemento a
elemento
	   Parámetro:  la matriz que va a sumar
	   Retorno: una nueva matriz con la suma de ambas matrices.
	   Precondicion: n_filas == m.n_filas && n_columnas==m.n_columnas.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


*/
Matriz operator+ (const Matriz &m);

/* Implementa la sobrecarga del operador resta que permite sumar dos
matrices que tienen las mismas dimensiones. Este método
 crea una matriz nueva con las dimensiones de las
originales y que contiene la resta de ellas elemento a
elemento
	   Parámetro:  la matriz que va a restar
	   Retorno: una nueva matriz con la resta de ambas matrices.
	   Precondicion: n_filas == m.n_filas && n_columnas==m.n_columnas.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


*/
Matriz operator- (const Matriz &m);

/* Este método permite multiplicar dos matrices que tienen
dimensiones compatibles según la operación de producto. El
resultado de esta operación es una matriz con el producto de
ambas matrices. 
	   Parámetro:  la matriz que va a multiplicar
	   Retorno: una nueva matriz con la multiplicacion de ambas matrices.
	   Precondicion: n_columnas == m.n_filas.
	   Complejidad Temporal: O(n_filas * n_columnas * m.n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


*/
Matriz operator* (const Matriz &m);

/* implementa la sobrecarga del operador producto para la multiplicación por un
escalar. Este método crea una matriz nueva con las
dimensiones de las originales y cuyos elementos son los de la
matriz original multiplicados por el escalar.

	   Parámetro:  la constante que va a multiplicar
	   Retorno: una nueva matriz con la multiplicacion.
	   Precondicion: ninguna
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


*/
Matriz operator* (const double num);

/* crea una matriz para almacenar la matriz traspuesta de la original.

	   Parámetro: ninguno
	   Retorno: una nueva matriz con la traspuesta.
	   Precondicion: ninguna
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


*/
Matriz calcularTraspuesta();

/* Este método indica si la matriz es simétrica o no

	   Parámetro: ninguno
	   Retorno: true si es simetrica false si no lo es
	   Precondicion: ninguna
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(1)


*/
bool esSimetrica();

/* Estos método devuelven el elemento con el máximo o
mínimo valor de toda la matriz.

	   Parámetro: ninguno
	   Retorno: el double con el valor maximo o minimo de la matriz
	   Precondicion: ninguna
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(1)


*/
double obtenerMaximo(); 

//calcula max
double obtenerMinimo(); 

/* Se encarga de liberar la memoria que fue
reservada de forma dinámica para almacenar la matriz.

	   Parámetro: ninguno
	   Retorno: ninguno
	   Complejidad Temporal: O(1)
	   Complejidad Espacial: O(1)


*/
~Matriz();


/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  Matriz& operator= (const Matriz &m);


/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/
  
  void rellenarManual();


/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	   Parámetro: semilla que se utiliza para el generador aleatorio
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void rellenarAleatorio(long seed);



/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void mostrarMatriz();
  
};

#endif // MATRIZ_H
