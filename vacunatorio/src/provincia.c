/*
 * provincia.c
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "provincia.h"

void mostrarProvincia(eProvincia provincia)
{
	printf("%6d %-15s \n",provincia.id,provincia.nombreProvincia);
}
int mostrarProvincias(eProvincia provincias[], int tam)
{
	int returnAux = -1;
	if(provincias != NULL && tam > 0)
	{
		printf("              *** Lista de Provincias ***\n");
		printf("-----------------------------------------------------------\n");
		printf("  Id  Nombre\n");
		printf("-----------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			mostrarProvincia(provincias[i]);
		}
		returnAux = 0;
	}
	return returnAux;
}
int cargarNombreProvincia(eProvincia provincias[], int tam, int idProvincia , char descripcion[])
{
	int returnAux = -1;
	if(provincias!=NULL && tam>0 && descripcion!=NULL)
	{
		for(int i=0; i<tam; i++)
		{
			if(provincias[i].id == idProvincia)
			{
				strcpy(descripcion, provincias[i].nombreProvincia);
				returnAux = 1;
				break;
			}
		}
		if(returnAux == -1)
		{
			returnAux = 0;
		}

	}

	return returnAux;
}
