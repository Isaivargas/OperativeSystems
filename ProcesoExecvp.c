//
//  ProcesoExecvp.c
//
//
//  Created by Beatriz Paulina Garcia Salgado on 10/17/17.
//

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid;
    int status;
    char *argumentos[3] = {"ls","-l",NULL};
    pid = fork();
    switch(pid){
        case -1:
            perror("Error en creacion del hijo");
            exit(-1);
        case 0:
            //Intercambio de código del padre por ls -l
            execvp(argumentos[0],argumentos);
            perror("Error de execvp");
            exit(-1);
            break;
        default:
            //El padre espera hasta que termine el hijo
            while(wait(&status) != pid);
            if(status == 0)
                printf("Ejecucion normal del hijo %d\n", pid);
            else
                printf("Error del hijo %d\n", pid);
    }
    exit(0);
}

