#include<iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#define TAMFC 10

void buscarCamino(char ** laberintoMatriz , int x, int y, bool * exitoP, int * tesoroXp, int * tesoroYp);

int main(){

    char ** laberintoMatriz; // matriz
    bool exito; //si existe camino a tesoro o no / si se ha encontrado el tesoro o no 
    int tesoroX = 0, tesoroY = 0; //coordenadas de tesoro en matriz en caso de que haya

    laberintoMatriz = new char * [TAMFC]; //reserva memoria matriz

    for(int i = 0; i < TAMFC; i++)
    {
        laberintoMatriz[i] = new char[TAMFC]; //reserva memoria matriz
    }

    //para el input introducir matriz/laberinto
    for(int i = 0; i < TAMFC; i++){
        for(int j = 0; j < TAMFC; j++){

            cin>>laberintoMatriz[i][j];
        }
    }

    buscarCamino(laberintoMatriz, 0, 0, &exito, &tesoroX, &tesoroY); //llama a la funcion de buscar camino al tesoro con las posiciones/coordenadas
                                                                    //iniciales 0, 0

    if(exito == true){ //una vez terminada la busqueda de laberinto, si el valor de exito ha sido cambiado a true (ha encontrado el tesoro)

        //imprime matriz laberinto modificado con el camino resuelto
        for(int i = 0; i < TAMFC; i++){
            for(int j = 0; j < TAMFC; j++){

                cout<<laberintoMatriz[i][j];
            }   
          
          cout<<endl;
        }
        cout<<"ENCONTRADO "<<tesoroX<<" "<<tesoroY<<endl; //coordenadas/posicion de tesoro

    }else{ //si valor exito no ha sido cambiado significa que el tesoro no es alcanzable

        cout<<"INALCANZABLE"<<endl;
    }

    return 0;
}

void buscarCamino(char ** laberinto, int x, int y, bool * exitoP, int * tesoroXp, int * tesoroYp){

    //movimientos disponibles del usuario, primero arriba[0], derecha[1], abajo[2], izquierda[3]
    int dx[4] = {-1, 0, 1, 0};  //coordenadas x (filas)
    int dy[4] = {0, 1, 0, -1}; //coordenadas y (columnas)
    
    //posiciones actuales para ir sumandole los valores dx y dy
    int u = 0; //posicion actual x
    int v = 0; //posicion actual y

//si exito es false busca
 if(!*exitoP){

    if ((0 <= x) && (x < TAMFC) && (0 <= y) && (y < TAMFC)){ //condicion para que no se salga de la matriz
        
        if(laberinto[x][y] == '.'){ //si posicion actual es un punto

            laberinto[x][y] = 'X'; //lo marca X 
        
            for(int k = 0; k < 4; k++){ // comprueba las posibles diferentes posiciones (en orden) 
                    
                    //suma de posicion actual mas el proximo movimiento
                    u = x + dx[k];  
                    v = y + dy[k];
                    //y llama a la funcion con siguiente movimiento (se guarda la iteracion por la que se quedo en caso de volver)
                    buscarCamino(laberinto, u, v, exitoP, tesoroXp, tesoroYp);
                }

                //cuando ya ha probado todas las posiciones del for y no ha conseguido seguir, vuelve atras marcando como puntos las X
                if(!*exitoP){

                    laberinto[x][y] = '.';
                }   

        }else if(laberinto[x][y] == 'T') { //si la posicion actual es el tesoro
            
            *tesoroXp = x; //guarda sus coordenadas/posiciones
            *tesoroYp = y;
            *exitoP = true; //cambia exito a true
            return;  //y devuelve
        
        }else{
            return;
        }
    }
  }
}