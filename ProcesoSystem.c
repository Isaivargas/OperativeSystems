w//
//  ProcesoSystemExec.c
//
//
//  Created by Beatriz Paulina Garcia Salgado on 10/17/17.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 50

int main()
{
    char commline1[MAX_CHARS];
    char commline2[MAX_CHARS];
    char commline3[MAX_CHARS];
    char *nombreArchivo = {"archivo1.txt"};
    
    //Imprimir en la variable commline la sentencia touch y el nombre del archivo
    sprintf(commline1,"touch %s", nombreArchivo);
    system(commline1);
    
    //Imprimir en la variable commline la sentencia para imprimir en el archivo el contenido de la carpeta en la posici—n actual
    sprintf(commline2,"ls -la > %s", nombreArchivo);
    system(commline2);
    
    //Imprimir en la variable commline la sentencia para imprimir un mensaje al final del archivo
    sprintf(commline3,"echo Beatriz Paulina Garcia Salgado >> %s", nombreArchivo);
    system(commline3);
    
    exit(EXIT_SUCCESS);
}
