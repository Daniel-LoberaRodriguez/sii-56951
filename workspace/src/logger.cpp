#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char **argv) {
    int fd;
    char buffer[1024];

    // borrar FIFO por si existiera previamente
    unlink(p_fifo);

    /* crear el FIFO */
    if (mkfifo(p_fifo)<0) { //si devuelve un numero negativo es que ha habido un problema
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    if (fd = open(p_fifo,_RDONLY)) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while (bytes_leidos = read(fd,buffer,sizeof(buffer)-1)>0) {
        buffer[bytes_leidos] = \0; //añado el final para que printf no haga errores
	printf("%s\n",buffer); //imprimo lo que hay en el buffer
    }
    close(fd);
    unlink(p_fifo);
    return(0);
}
