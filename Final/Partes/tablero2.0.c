#include <stdio.h>
#include <string.h>

char table[20][20];
char input[10];
char puntos[] = {" ."};
char hor_1[3][50] = {"bombero", "perro"};
char ver_2[3][50] = {"oruga", "eco"};
char hor_3[3][50] = {"galleta", "gallina"};
char ver_4[3][50] = {"aluminio", "mono"};
char hor_5[3][50] = {"dragon", "caballero"};
char ver_6[3][50] = {"arco", "flecha"};
int lon_1, lon_2, lon_3, lon_4, lon_5, lon_6;
int chec_ver_1 = 0, chec_ver_2 = 0, chec_ver_3 = 0, chec_ver_4 = 0, chec_ver_5 = 0, chec_ver_6 = 0;
int num_con = 0, correct = 0, p = 0;



void imprimir_tablero()
{
	 // imprime arrgelo
    for (int i = 0; i < 20; i++) {
        // Agregar espacios para centrar el arreglo
        for (int k = 0; k < (20 - 15) / 2; k++) {
            printf("            ");
        }
    for (int j = 0; j < 20; j++) {
            printf("%c ", table[i][j]);
        }
    printf("\n");
    }
}

void selector_de_palabras()
{
    int k = 0;
    if(num_con == 1)
    {
        printf("Ingrese la palabra_1 ");
        scanf("%s", &input);

        if(strcmp(input, hor_1[p]) == 0)
        {
            // Si es igual
            for(int j = 3; j < lon_1 + 3; j++)
            {
                table[1][j + 1] = hor_1[p][k];
                k ++;
            }
            correct++;

            chec_ver_1 = 1;
        }
        printf("Esa no es la palabra_1 correcta \n");
        imprimir_tablero();
    }
    if(num_con == 2)
    {
        printf("Ingrese la palabra_2 ");
        scanf("%s", &input);

        if(strcmp(input, ver_2[p]) == 0)
        {
            // Si es igual
            for(int j = 0; j < lon_2; j++)
            {
                table[j + 1][5] = ver_2[p][k];
                k ++;
            }
            correct++;
            chec_ver_2 = 1;
        }
        imprimir_tablero();
    }
    if(num_con == 3)
    {
        printf("Ingrese la palabra_3 ");
        scanf("%s", &input);

        if(strcmp(input, hor_3[p]) == 0)
        {
            // Si es igual
            for(int j = 4; j < lon_3 + 4; j++)
            {
                table[4][j + 1] = hor_3[p][k];
                k ++;
            }
            correct++;
            chec_ver_3 = 1;
        }
        imprimir_tablero();
    }
    if(num_con == 4)
    {
        printf("Ingrese la palabra_4 ");
        scanf("%s", &input);

        if(strcmp(input, ver_4[p]) == 0)
        {
            // Si es igual
            for(int j = 2; j <= lon_4 + 1; j++)
            {
                table[j + 1][7] = ver_4[p][k];
                k ++;
            }
            correct++;
            chec_ver_4 = 1;
        }
        imprimir_tablero();
    }
    if(num_con == 5)
    {
        printf("Ingrese la palabra_5 ");
        scanf("%s", &input);

        if(strcmp(input, hor_5[p]) == 0)
        {
            k = lon_5 - 1;
            // Si es igual
            for(int j = lon_5 + 2; j >= 3; j--)
            {
                table[8][j - 1] = hor_5[p][k];
                k --;
            }
            correct++;
            chec_ver_5 = 1;
        }
        imprimir_tablero();
    }
    if(num_con == 6)
    {
        printf("Ingrese la palabra_1 ");
        scanf("%s", &input);

        if(strcmp(input, ver_6[p]) == 0)
        {
            // Si es igual
            for(int j = 7; j < lon_6 + 7; j++)
            {
                table[j + 1][4] = ver_6[p][k];
                k ++;
            }
            correct++;
            chec_ver_6 = 1;
        }
        imprimir_tablero();
    }
    else if(num_con > 6)
    {
        printf("No hay tantas preguntas vuelve a ingresar el numero que sea entre 1 y 6 \n");
        imprimir_tablero();
    }


}

int main()
{

	for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            table[i][j] = puntos[1];
        }
    }
	

while(correct < 6)
    {
    if(chec_ver_1 == 0)
    {
	// Saca el numero de letras de la palbra 1
	   lon_1 = strlen(hor_1[p]);
    //Colocar los espacios para la palabra 1
        for (int j = 3; j < lon_1 + 3; j++) 
        {
            table[1][j + 1] = '1';
        }
    }

    if(chec_ver_2 == 0)
    {
        lon_2 = strlen(ver_2[p]);
        for (int j = 0; j < lon_2; j++) 
        {
            table[j + 1][5] = '2';
        }
    }

    if(chec_ver_3 == 0)
    {
        lon_3 = strlen(hor_3[p]);;
        for (int j = 4; j < lon_3 + 4; j++) 
        {
            table[4][j + 1] = '3';
        }
    }

    if(chec_ver_4 == 0)
    {
    lon_4 = strlen(ver_4[p]);
        for (int j = 2; j < lon_4 + 2; j++) 
        {
            table[j + 1][7] = '4';
        }
    }

    if(chec_ver_5 == 0)
    {
        lon_5 = strlen(hor_5[p]);
        for (int j = lon_5 + 2; j >= 3 ; j--) {
            table[8][j - 1] = '5';
        }
    }

    if(chec_ver_6 == 0)
    {
	   lon_6 = strlen(ver_6[p]);
        for (int j = 7; j < lon_6 + 7; j++) 
        {
            table[j + 1][4] = '6';
        }
    }

    imprimir_tablero();

    printf("Cual es la que quieres resolver \n");
    scanf("%d",&num_con);

    selector_de_palabras();
    }


    return 0;
}