//
//  ProcesoExeclp.c
//  
//
//  Created by Beatriz Paulina Garcia Salgado on 10/17/17.
//

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_CHARS 50

int main()
{
    int pid;
    int status;
    char *argumentos[3] = {"ls","-l",NULL};
    char commline[MAX_CHARS];
    
    char *nombreArchivo = {"archivo1.txt"};
    
    //Primera bifurcación: utilización de sh para crear un archivo
    pid = fork();
    switch(pid){
        case -1:
            perror("Error en creacion del hijo\n");
            exit(-1);
        case 0:
            //Imprimir en la variable commline la sentencia touch y el nombre del archivo
            sprintf(commline,"touch %s", nombreArchivo);
            //Sustitución del código del padre por el programa sh
            execlp("sh","sh","-c",commline,NULL);
            perror("Error de execlp\n");
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
    
    //Segunda bifurcación: utilización de argumentos para imprimir en pantalla el contenido de la carpeta en posición actual
    pid = fork();
    switch(pid){
        case -1:
            perror("Error en creacion del hijo\n");
            exit(-1);
        case 0:
            //Sustitución del código del padre por el programa enunciado en argumentos[0]
            execlp(argumentos[0],argumentos[0],argumentos[1],NULL);
            perror("Error de execlp\n");
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
