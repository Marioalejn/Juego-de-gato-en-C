#include <stdio.h>
 
int coordenadas();
void gato();

int main()
{
    char array[3][3];
    int i,j, finish_marc=0,player=1;
    //for que llena el arreglo con elementos vacíos
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            array[i][j] = ' '; //Le puse un espacio porque al imprimirse tiene que abarcar el espacio de la cacilla
        }
    }
    gato(array);
    //Llamado a la función
    do{
    player = coordenadas(array,player);
    gato(array);
    }while(finish_marc == 0);
    
    return 0;
}

//Función para que el jugador eliga la coordenada 
int coordenadas(char array[3][3], int player){
    int fila, columna;
    printf("Ingresa la fila: ");
    scanf("%i", &fila);
    printf("Ingresa la columna: ");
    scanf("%i", &columna);
    
    if(fila >= 0 && fila <= 2 && columna >= 0 && columna <= 2){ //Si no está ocupada entra al if
        if(player == 1 && array[fila][columna] == ' '){
            array[fila][columna] = 'X'; //jugador 1 es X y jugador 2 es O
            player = 2; //Para que cambie de jugador y no se pongan siempre los mismos signos
        }
        if(player == 2 && array[fila][columna] == ' '){
            array[fila][columna] = 'O';
            player = 1;
        }
    }
    if(!(fila>=0 && fila<=2 && columna>=0 && columna<=2)){ //else por si agrega una coordenada ocupada o que no existe en el 0,1,2 del arreglo 3x3
        printf("Coordenada seleccionada ocupada o erronea, ingresa otra...\n");
        getchar();
        coordenadas(array,player);
    }
    return player;
    //Tal vez tenga que retornar el jugador o algo
}
 void gato(char array[3][3]){
     
    printf("\n %c | %c | %c \n",array[0][0], array[0][1], array[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n",array[1][0], array[1][1], array[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n",array[2][0], array[2][1], array[2][2]);
 }
