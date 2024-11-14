#include <stdio.h>
#include <string.h>

int main() {
    char palabras[3][MAX_WORD_LENGTH];
    int i;

    // Inicializar el arreglo con palabras por defecto
    strcpy(palabras[0], "primera");
    strcpy(palabras[1], "segunda");
    strcpy(palabras[2], "tercera");

    // Mostrar las palabras originales
    printf("Las palabras originales son:\n");
    for (i = 0; i < 3; i++) {
        printf("%d: %s\n", i + 1, palabras[i]);
    }

    // Cambiar las palabras
    printf("\nPor favor, introduzca las nuevas palabras:\n");
    for (i = 0; i < 3; i++) {
        printf("Palabra %d: ", i + 1);
        scanf("%s", palabras[i]);
    }

    // Mostrar las palabras actualizadas
    printf("\nLas palabras actualizadas son:\n");
    for (i = 0; i < 3; i++) {
        printf("%d: %s\n", i + 1, palabras[i]);
    }

    return 0;
}