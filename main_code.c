#include <stdio.h>

int verificar_ganador(); 
int coordenadas();
void gato();

int main()
{
    char array[3][3];
    int i,j, ganador=0,player=1,turnos = 0;
    //for que llena el arreglo con elementos vacíos
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            array[i][j] = ' '; //Le puse un espacio porque al imprimirse tiene que abarcar el espacio de la cacilla
        }
    }
    gato(array);
    //Llamado a la función
    do {
        player = coordenadas(array, player);
        turnos++;
        gato(array);

        ganador = verificar_ganador(array);
        if (ganador != 0) {
            printf("¡El jugador %d ha ganado!\n", ganador);
            break;
        } else if (turnos == 9) {
            printf("¡Empate! No hay más movimientos disponibles.\n");
            break;
        }
    } while (1);

    
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
            printf("array[%i][%i]: %c", fila,columna,array[fila][columna]); //BORRARLOS, SOLO PARA VERIFICAR QUE SI GUARDARA DATOS
        }
        if(player == 2 && array[fila][columna] == ' '){
            array[fila][columna] = 'O';
            player = 1;
            printf("array[%i][%i]: %c", fila,columna,array[fila][columna]);//BORRARLOS, SOLO PARA VERIFICAR QUE SI GUARDARA DATOS
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

// Función para verificar si hay un ganador
int verificar_ganador(char array[3][3]) {
    int i;
    // Revisar filas y columnas
    for (i = 0; i < 3; i++) {
        if (array[i][0] != ' ' && array[i][0] == array[i][1] && array[i][1] == array[i][2]) {
            return (array[i][0] == 'X') ? 1 : 2;
        }
        if (array[0][i] != ' ' && array[0][i] == array[1][i] && array[1][i] == array[2][i]) {
            return (array[0][i] == 'X') ? 1 : 2;
        }
    }
    // Revisar diagonales
    if (array[0][0] != ' ' && array[0][0] == array[1][1] && array[1][1] == array[2][2]) {
        return (array[0][0] == 'X') ? 1 : 2;
    }
    if (array[0][2] != ' ' && array[0][2] == array[1][1] && array[1][1] == array[2][0]) {
        return (array[0][2] == 'X') ? 1 : 2;
    }
    return 0; // No hay ganador aún
}
