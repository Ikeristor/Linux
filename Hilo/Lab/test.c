#include <stdio.h>

int main() {
    int arreglo_padre[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int longitud_arreglo_hijo = 4;
    int cantidad_arreglos_hijo = 3;
    int arreglos_hijo[cantidad_arreglos_hijo][longitud_arreglo_hijo];
    int i, j, k = 0;

    
    printf("\n");

    printf("Dividiendo en %d arreglos hijos de longitud %d:\n", cantidad_arreglos_hijo, longitud_arreglo_hijo);
    for (i = 0; i < cantidad_arreglos_hijo; i++) {
        printf("Arreglo hijo %d: ", i + 1);
        for (j = 0; j < longitud_arreglo_hijo; j++) {
            arreglos_hijo[i][j] = arreglo_padre[k];
            printf("%d ", arreglos_hijo[i][j]);
            k++;
        }
        printf("\n");
    }

    return 0;
}
