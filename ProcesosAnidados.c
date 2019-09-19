//
//  ProcesosAnidados.c
//  
//
//  Created by Beatriz Paulina Garcia Salgado on 10/17/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
  int pidPadre;
  int pidFork;
  int pidFork2;
  int pidHijo;
  int pidHijo2;
  int status;
  
  pidPadre = getpid();
  pidFork = fork();
  switch(pidFork)
  {
	case -1:
		perror("Error en creación del hijo\n");
		exit(EXIT_FAILURE);
	case 0:
		pidHijo = getpid();
		printf("Soy proceso hijo con ID: %i\n",pidHijo);
		pidFork2 = fork();
		switch(pidFork2)
		{
		  case -1:
		    perror("Error en creación del hijo\n");
		    exit(EXIT_FAILURE);
		  case 0:
		    pidHijo2 = getpid();
		    printf("Soy proceso hijo con ID: %i\n",pidHijo2);
		    printf("Mi padre es %i\n",pidHijo);
		    exit(EXIT_SUCCESS);
		    break;
		  default:
		    while(wait(&status) != pidFork2);
		    if(status == 0)
			    printf("Soy el proceso padre %i\ny terminé de esperar a mi hijo %i\n",pidHijo,pidFork2);
		    else
			    perror("Error en espera del hijo \n");
		    exit(EXIT_SUCCESS);
		    break;
		}
	default:
		while(wait(&status) != pidFork);
		if(status == 0)
			printf("Soy el proceso padre %i\ny terminé de esperar a mi hijo %i\n",pidPadre,pidFork);
		else
			perror("Error en espera del hijo \n");
		exit(EXIT_SUCCESS);
  }
  exit(EXIT_SUCCESS);
}