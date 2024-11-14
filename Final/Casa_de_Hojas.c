#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>

#define THREADS_NO 3

char table[25][25];
char input[10];
char puntos[] = {" ."};
char hor_1[3][50] = {"castillo", "camino", "barco"};
char ver_2[3][50] = {"arbol", "alfil","arbol"};
char hor_3[3][50] = {"laguna", "lamento", "latin"};
char ver_4[3][50] = {"ganado", "ganso", "gangrena"};
char hor_5[3][50] = {"dragon", "adoquin", "admiran"};
char ver_6[3][50] = {"doncella", "daga", "duelo"};
int lon_1, lon_2, lon_3, lon_4, lon_5, lon_6;
int chec_ver_1 = 0, chec_ver_2 = 0, chec_ver_3 = 0, chec_ver_4 = 0, chec_ver_5 = 0, chec_ver_6 = 0;
int num_con = 0, correct = 0, p = 0, timer = 30, life = 5;
int status, t;
pid_t pid_M, pid_V, pid_H;
pthread_t threads[THREADS_NO];
pthread_mutex_t mutex_id;
pthread_cond_t tab, pal_ver, pal_hor;
 
void print_image(FILE *fptr)
{
    char read_string[1000];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}


int mygetch ( void ) 
{
  int ch;
  struct termios oldt, newt;
  
  tcgetattr ( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );
  
  return ch;
}

void imprimir_tablero()
{
     // imprime arrgelo
    for (int i = 0; i < 25; i++) {
        // Agregar espacios para centrar el arreglo
        for (int k = 0; k < (25 - 20) / 2; k++) {
            printf("                                   ");
        }
    for (int j = 0; j < 25; j++) {
            printf("%c ", table[i][j]);
        }
    printf("\n");
    }
    printf("\n");
    printf("\n");
}

void* llenar_tab_aste(void *args)
{
    int k = 0;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            table[i][j] = puntos[1];
        }
    }
    if(chec_ver_1 != 0)
    {
        k = 0;
        if(chec_ver_1 == 1)
        {
            for(int j = 6; j < lon_1 + 6; j++)
                {
                    table[8][j + 1] = hor_1[0][k];
                    k ++;

                }
        }
        if(chec_ver_1 == 2)
        {
            for(int j = 6; j < lon_1 + 6; j++)
                {
                    table[8][j + 1] = hor_1[1][k];
                    k ++;

                }
        }
         if(chec_ver_1 == 3)
        {
            for(int j = 6; j < lon_1 + 6; j++)
                {
                    table[8][j + 1] = hor_1[2][k];
                    k ++;

                }
        }
    }
    if(chec_ver_2 != 0)
    {
        k = 0;
        if(chec_ver_2 == 1)
        {
            for(int j = 7; j < lon_2 + 7; j++)
            {
                table[j + 1][8] = ver_2[0][k];
                k ++;

            }
        }
        if(chec_ver_2 == 2)
        {
            for(int j = 7; j < lon_2 + 7; j++)
            {
                table[j + 1][8] = ver_2[1][k];
                k ++;

            }
        }
         if(chec_ver_2 == 3)
        {
            for(int j = 7; j < lon_2 + 7; j++)
            {
                table[j + 1][8] = ver_2[2][k];
                k ++;

            }
        }
    }
    if(chec_ver_3 != 0)
    {
        k = 0;
        if(chec_ver_3 == 1)
        {
            for(int j = 7; j < lon_3 + 7; j++)
            {
                table[12][j + 1] = hor_3[0][k];
                k ++;

            }
        }
        if(chec_ver_3 == 2)
        {
            for(int j = 7; j < lon_3 + 7; j++)
            {
                table[12][j + 1] = hor_3[1][k];
                k ++;

            }
        }
         if(chec_ver_3 == 3)
        {
            for(int j = 7; j < lon_3 + 7; j++)
            {
                table[12][j + 1] = hor_3[2][k];
                k ++;

            }
        }
    }
    if(chec_ver_4 != 0)
    {
        k = 0;
        if(chec_ver_4 == 1)
        {
            for(int j = 11; j <= lon_4 + 10; j++)
            {
                table[j + 1][10] = ver_4[0][k];
                k ++;

            }
        }
        if(chec_ver_4 == 2)
        {
            for(int j = 11; j <= lon_4 + 10; j++)
            {
                table[j + 1][10] = ver_4[1][k];
                k ++;

            }
        }
         if(chec_ver_4 == 3)
        {
            for(int j = 11; j <= lon_4 + 10; j++)
            {
                table[j + 1][10] = ver_4[2][k];
                k ++;

            }
        }
    }
    if(chec_ver_5 != 0)
    {
        if(chec_ver_5 == 1)
        {
            lon_5 = strlen(hor_5[0]);
            k = lon_5 - 1;
            for(int j = lon_5 + 5; j >= 6; j--)
            {
                table[14][j - 1] = hor_5[0][k];
                k --;
            }
        }
        if(chec_ver_5 == 2)
        {
            lon_5 = strlen(hor_5[1]);
            k = lon_5 - 1;
            for(int j = lon_5 + 5; j >= 6; j--)
            {
                table[14][j - 1] = hor_5[1][k];
                k --;
            }
        }
         if(chec_ver_5 == 3)
        {
            lon_5 = strlen(hor_5[2]);
            k = lon_5 - 1;
            for(int j = lon_5 + 5; j >= 6; j--)
            {
                table[14][j - 1] = hor_5[2][k];
                k --;
            }
        }
    }
    if(chec_ver_6 != 0)
    {
        if(chec_ver_6 == 1)
        {
            for(int j = 13; j < lon_6 + 13; j++)
            {
                table[j + 1][5] = ver_6[0][k];
                k ++;

            }
        }
        if(chec_ver_6 == 2)
        {
            for(int j = 13; j < lon_6 + 13; j++)
            {
                table[j + 1][5] = ver_6[1][k];
                k ++;
            }
        }
         if(chec_ver_6 == 3)
        {
            for(int j = 13; j < lon_6 + 13; j++)
            {
                table[j + 1][5] = ver_6[2][k];
            k ++;
            }
        }
    }

}

void* llenar_hor_num( void *args )
{
    if(chec_ver_1 == 0)
        {
        // Saca el numero de letras de la palbra 1
           lon_1 = strlen(hor_1[p]);
        //Colocar los espacios para la palabra 1
            for (int j = 6; j < lon_1 + 6; j++) 
            {
                table[8][j + 1] = '1';
            }
        }
    if(chec_ver_3 == 0)
    {
        lon_3 = strlen(hor_3[p]);;
        for (int j = 7; j < lon_3 + 7; j++) 
        {
            table[12][j + 1] = '3';
        }
    }
    if(chec_ver_5 == 0)
    {
        lon_5 = strlen(hor_5[p]);
        for (int j = lon_5 + 5; j >= 6 ; j--) {
            table[14][j - 1] = '5';
        }
    }
    pthread_cond_signal( &pal_hor );
    pthread_exit( NULL );
}

void* llenar_ver_num( void *arg )
{
    pthread_mutex_lock( &mutex_id );
    pthread_cond_wait(&pal_hor, &mutex_id);
    if(chec_ver_2 == 0)
    {
        lon_2 = strlen(ver_2[p]);
        for (int j = 7; j < lon_2 + 7; j++) 
        {
            table[j + 1][8] = '2';
        }
    }
    if(chec_ver_4 == 0)
    {
    lon_4 = strlen(ver_4[p]);
        for (int j = 11; j < lon_4 + 10; j++) 
        {
            table[j + 1][10] = '4';
        }
    }
    if(chec_ver_6 == 0)
    {
       lon_6 = strlen(ver_6[p]);
        for (int j = 13; j < lon_6 + 13; j++) 
        {
            table[j + 1][5] = '6';
        }
    }
    pthread_mutex_unlock( &mutex_id );
    pthread_exit( NULL );
}
void preguntas()
{
    if(p == 0)
    {
        printf("1) Es un símbolo de poder y fortaleza, una impresionante obra de arquitectura medieval que evoca la grandeza y la majestuosidad de épocas pasadas.\n");
        printf("\n");
        printf("2) Es mucho más que una simple planta: es un símbolo de vida, fortaleza y belleza en el paisaje natural. Su presencia es una fuente de inspiración y asombro, recordándonos la maravilla y la grandeza del mundo natural que nos rodea.\n");
        printf("\n");
        printf("3) Se pueden encontrar senderos naturales que invitan a explorar los alrededores y descubrir la diversidad de vida que habita en este ecosistema acuático. Es un lugar de belleza serena y atemporal, donde el tiempo parece detenerse y se puede disfrutar de la calma y la tranquilidad de la naturaleza. \n");
        printf("\n");
        printf("4) Un pastor vigila desde la distancia, asegurándose de que estén seguras y bien cuidadas.\n");
        printf("\n");
        printf("5) Su presencia se siente en todo el reino, infundiendo temor y respeto en aquellos que lo conocen. Es una criatura de leyenda y mito, cuya mera existencia despierta la imaginación y la admiración de aquellos que buscan la aventura y el peligro en el mundo.\n");
        printf("\n");
        printf("6) Es conocida por su amabilidad y generosidad, siempre dispuesta a ayudar a los demás en tiempos de necesidad. Es una presencia reconfortante en la comunidad, un faro de esperanza y alegría en medio de la adversidad. \n");
        printf("\n");
    }
    if(p == 1)
    {
        printf("1) Invita a la aventura y la exploración, prometiendo descubrimientos emocionantes y encuentros inesperados. Es un recordatorio de que el viaje es tan importante como el destino, y que cada paso nos acerca un poco más a la comprensión del mundo que nos rodea.\n");
        printf("\n");
        printf("2) En el tablero evoca un aura de misterio y cálculo, recordando a los jugadores la importancia de la planificación y la anticipación en el ajedrez. Es una pieza de gran valor, capaz de cambiar el curso de una partida con un solo movimiento audaz y bien calculado.\n");
        printf("\n");
        printf("3) Es una expresión de duelo y aflicción, un tributo a los que se han ido y a los que quedan atrás. Es un grito de desesperación en medio de la oscuridad, una súplica silenciosa de paz y redención.\n");
        printf("\n");
        printf("4) Son aves sociales que forman vínculos fuertes entre sí y cuidan de sus crías con dedicación y ternura. Son criaturas inteligentes y curiosas, que exploran su entorno con interés y alerta ante cualquier peligro que pueda acechar.\n");
        printf("\n");
        printf("5) Es único en su forma y tamaño, pero todos están cuidadosamente cortados y pulidos para encajar de manera uniforme en el pavimento. Cuando se colocan juntos, forman un patrón geométrico que puede variar desde simples líneas rectas hasta intrincados diseños en espiga o espina de pescado.\n");
        printf("\n");
        printf("6) Un arma blanca de hoja corta y afilada, diseñada para el combate cuerpo a cuerpo. Su hoja suele ser de metal, forjada con precisión para maximizar su capacidad de corte y penetración. \n");
        printf("\n");
    }
    if(p == 2)
    {
        printf("1) Es más que un simple medio de transporte; es un símbolo de aventura y descubrimiento, un recordatorio de la capacidad del ser humano para conquistar los elementos y explorar los rincones más remotos del los mares\n");
        printf("\n");
        printf("2) Es mucho más que una simple planta: es un símbolo de vida, fortaleza y belleza en el paisaje natural. Su presencia es una fuente de inspiración y asombro, recordándonos la maravilla y la grandeza del mundo natural que nos rodea.\n");
        printf("\n");
        printf("3) Miles fortis, armatus gladio, equum regale conscendens, ad castrum oppugnatum properavit, ubi captivam principissam, periclitantem, e periculo liberavit.\n");
        printf("\n");
        printf("4) Una enfermedad grave en la que los tejidos del cuerpo, generalmente debido a una falta de suministro de sangre, comienzan a morir. \n");
        printf("\n");
        printf("5) Es la tercera persona  de sentir respeto, estima o sorpresa por alguien o algo debido a sus cualidades, acciones o características excepcionales.\n");
        printf("\n");
        printf("6) Un enfrentamiento formal entre dos oponentes, a menudo regido por ciertas reglas o códigos de conducta.\n");
        printf("\n");
    }
}
void sig_handler(int signum)
{
  if(p == 2)
  {
    p = -1;
  }
  p++;
  printf("\n");
  printf("\n");
  printf("\n");
  pthread_create( &threads[t], NULL, llenar_tab_aste, NULL);
  pthread_create( &threads[t], NULL, llenar_ver_num, NULL );
  pthread_create( &threads[t], NULL, llenar_hor_num, NULL);

  life --;
  imprimir_tablero();

  printf("Te tardeste en contestar ahora se ha cambiado el crusigrama                                                                                      te quedan %d vidas \n", life);
  
  preguntas();

  printf("\n");


  alarm(timer);

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
            for(int j = 6; j < lon_1 + 6; j++)
            {
                table[8][j + 1] = hor_1[p][k];
                k ++;
            }
            if(p == 0)
            {
                chec_ver_1 = 1;
            }else if(p == 1)
            {
                chec_ver_1 = 2;
            }else if(p == 2)
            {
                chec_ver_1 = 3;
            }
            correct++;
        }
        imprimir_tablero();
         if(strcmp(input, hor_1[p]) != 0)
         {
             life --;
            printf("Esa no es la palabra correcta                                                                                     te quedan %d vidas \n", life);

         }
    }
    if(num_con == 2)
    {
        printf("Ingrese la palabra_2 ");
        scanf("%s", &input);

        if(strcmp(input, ver_2[p]) == 0)
        {
            // Si es igual
            for(int j = 7; j < lon_2 + 7; j++)
            {
                table[j + 1][8] = ver_2[p][k];
                k ++;
            }
            if(p == 0)
            {
            chec_ver_2 = 1;
            }else if(p == 1)
            {
            chec_ver_2 = 2;
            }else if(p == 2)
            {
            chec_ver_2 = 3;
            }
            correct++;
        }
        imprimir_tablero();

        if(strcmp(input, ver_2[p]) != 0)
         {
             life --;
            printf("Esa no es la palabra correcta                                                                                     te quedan %d vidas \n", life);

         }
    }
    if(num_con == 3)
    {
        printf("Ingrese la palabra_3 ");
        scanf("%s", &input);

        if(strcmp(input, hor_3[p]) == 0)
        {
            // Si es igual
            for(int j = 7; j < lon_3 + 7; j++)
            {
                table[12][j + 1] = hor_3[p][k];
                k ++;
            }
            if(p == 0)
            {
                chec_ver_3 = 1;
            }else if(p == 1)
            {
                chec_ver_3 = 2;
            }else if(p == 2)
            {
                chec_ver_3 = 3;
            }
            correct++;
        }
        imprimir_tablero();
         if(strcmp(input, hor_3[p]) != 0)
         {
             life --;
            printf("Esa no es la palabra correcta                                                                                     te quedan %d vidas \n", life);

         }
    }
    if(num_con == 4)
    {
        printf("Ingrese la palabra_4 ");
        scanf("%s", &input);

        if(strcmp(input, ver_4[p]) == 0)
        {
            // Si es igual
            for(int j = 11; j <= lon_4 + 10; j++)
            {
                table[j + 1][10] = ver_4[p][k];
                k ++;
            }
            if(p == 0)
            {
                chec_ver_4 = 1;
            }else if(p == 1)
            {
                chec_ver_4 = 2;
            }else if(p == 2)
            {
                chec_ver_4 = 3;
            }
            correct++;
        }
        imprimir_tablero();
         if(strcmp(input, ver_4[p]) != 0)
         {
             life --;
            printf("Esa no es la palabra correcta                                                                                     te quedan %d vidas \n", life);

         }
    }
    if(num_con == 5)
    {
        printf("Ingrese la palabra_5 ");
        scanf("%s", &input);

        if(strcmp(input, hor_5[p]) == 0)
        {
            k = lon_5 - 1;
            // Si es igual
            for(int j = lon_5 + 5; j >= 6; j--)
            {
                table[14][j - 1] = hor_5[p][k];
                k --;
            }
            if(p == 0)
            {
                chec_ver_5 = 1;
            }else if(p == 1)
            {
                chec_ver_5 = 2;
            }else if(p == 2)
            {
                chec_ver_5 = 3;
            }
            correct++;
        }
        imprimir_tablero();
        if(strcmp(input, hor_5[p]) != 0)
         {
             life --;
            printf("Esa no es la palabra correcta                                                                                     te quedan %d vidas \n", life);

         }
    }
    if(num_con == 6)
    {
        printf("Ingrese la palabra_1 ");
        scanf("%s", &input);

        if(strcmp(input, ver_6[p]) == 0)
        {
            // Si es igual
            for(int j = 13; j < lon_6 + 13; j++)
            {
                table[j + 1][5] = ver_6[p][k];
                k ++;
            }
            if(p == 0)
            {
                chec_ver_6 = 1;
            }else if(p == 1)
            {
                chec_ver_6 = 2;
            }else if(p == 2)
            {
                chec_ver_6 = 3;
            }
            correct++;
        }
        imprimir_tablero();
       if(strcmp(input, ver_6[p]) != 0)
         {
             life --;
            printf("Esa no es la palabra correcta                                                                                     te quedan %d vidas \n", life);

         }
    }
    else if(num_con > 6)
    {
        printf("No hay tantas preguntas vuelve a ingresar el numero que sea entre 1 y 6 \n");
        imprimir_tablero();
    }
}

void signal_handler_sigusr1(int signum)
{
   timer = 0;
   kill(getpid(), SIGKILL);
}

int main(void)
{

    pthread_mutex_init( &mutex_id, 0 ); 
    pthread_cond_init( &pal_hor, 0 );
    pthread_cond_init( &pal_ver, 0 );

    pid_M = fork();
    if(pid_M == 0)
    {
        char *filename = "image.txt";
        FILE *fptr = NULL;
 
        if((fptr = fopen(filename,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename);
            return 1;
        }
        print_image(fptr);
 
        fclose(fptr);
        printf("\n");
 
        printf("                                                                              Presiona enter para empezar.");
        mygetch();

        printf("\n");
        printf("\n");
        printf("\n");
        return 1;
    }
    waitpid(pid_M, &status, 0);
    
    printf("\n");
    pthread_create( &threads[t], NULL, llenar_tab_aste, NULL);
    pthread_create( &threads[t], NULL, llenar_ver_num, NULL );
    pthread_create( &threads[t], NULL, llenar_hor_num, NULL);

  

    imprimir_tablero();
    preguntas();
    while(correct < 6)
    {  
        signal(SIGALRM,sig_handler); // Register signal handler
        
        alarm(timer);
        signal(SIGUSR2, signal_handler_sigusr1);
    if(life <= 0)
    {
        
         char *filename = "fin.txt";
        FILE *fptr = NULL;
 
        if((fptr = fopen(filename,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename);
            return 1;
        }
        print_image(fptr);
 
        fclose(fptr);
        printf("\n");
        kill(getpid(), SIGUSR2);
        wait(&status);
    }

        printf("Cual es la que quieres resolver? ");
        scanf("%d",&num_con);
        selector_de_palabras();
        preguntas();
    }

     char *filename = "win.txt";
        FILE *fptr = NULL;
 
        if((fptr = fopen(filename,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename);
            return 1;
        }
        print_image(fptr);
 
        fclose(fptr);



    pthread_mutex_destroy( &mutex_id );
    pthread_cond_destroy( &pal_hor );
    pthread_cond_destroy( &pal_ver );
    return 0;
}