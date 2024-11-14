#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
   
    int fd = open("datos2.txt", 2);

   
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    float valor; 


    for (int i = 1; read(fd, &valor, sizeof(valor)) > 0; i++) {
        printf("Valor %d: %f\n", i, valor);
    }

    close(fd);

    return 0;
}
