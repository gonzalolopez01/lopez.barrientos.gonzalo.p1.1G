/*
 * laboratorio.c
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#include "laboratorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

void mostrarLaboratorio(eLaboratorio laboratorio)
{
	printf("%6d %-15s \n",laboratorio.id,laboratorio.nacionalidad);
}
int mostrarLaboratorios(eLaboratorio laboratorios[], int tam)
{
	int returnAux = -1;
	if(laboratorios != NULL && tam > 0)
	{
		printf("              *** Lista de Laboratorios ***\n");
		printf("-----------------------------------------------------------\n");
		printf("  Id  Nacionalidad\n");
		printf("-----------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			mostrarLaboratorio(laboratorios[i]);
		}
		returnAux = 0;
	}
	return returnAux;
}
