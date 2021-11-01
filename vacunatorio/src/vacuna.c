/*
 * vacuna.c
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#include "vacuna.h".h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

void mostrarVacuna(eVacuna vacuna)
{
	printf("%6d %-12s %6.2f %6d\n",vacuna.id,vacuna.nombre,vacuna.precio,vacuna.idLaboratorio);
}
int mostrarVacunas(eVacuna vacunas[], int tam)
{
	int returnAux = -1;
	if(vacunas != NULL && tam > 0)
	{
		printf("              *** Lista de Vacunas ***\n");
		printf("-----------------------------------------------------------\n");
		printf("  Id    Nombre     Precio   IdLAb\n");
		printf("-----------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			mostrarVacuna(vacunas[i]);
		}
		returnAux = 0;
	}
	return returnAux;
}
