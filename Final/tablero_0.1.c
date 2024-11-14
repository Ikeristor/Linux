#include <stdio.h>
#include <string.h>

#define ROWS 25
#define COLS 25

int main() {
    char array[ROWS][COLS];
    char palabra[] = "oso";
    
    // Llenar todo el arreglo con asteriscos
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = '*';
        }
    }
    
    // Colocar los espacios para la palabra "oso"
    for (int j = 0; j < 3; j++) {
        array[1][j + 1] = '1';
    }
    
    // Imprimir el arreglo antes de pedir la palabra "oso"
    printf("Arreglo con espacios para la palabra 'oso':\n");
    for (int i = 0; i < ROWS; i++) {
        // Agregar espacios para centrar el arreglo
        for (int k = 0; k < (COLS - 20) / 2; k++) {
            printf("                      ");
        }
        for (int j = 0; j < COLS; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
    
    // Pedir al usuario que ingrese la palabra "oso"
    char input[4];
    printf("\nIngrese la palabra 'oso': ");
    scanf("%s", input);
    
    // Comprobar si la entrada del usuario es igual a "oso"
    if (strcmp(input, palabra) == 0) {
        // Si es igual, colocar "1" en las posiciones correspondientes
        for (int j = 0; j < 3; j++) {
            array[1][j + 1] = palabra[j];
        }
    }
    
    // Imprimir el arreglo final
    printf("\nArreglo final:\n");
    for (int i = 0; i < ROWS; i++) {
        // Agregar espacios para centrar el arreglo
        for (int k = 0; k < (COLS - 20) / 2; k++) {
            printf("                      ");
        }
        for (int j = 0; j < COLS; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
