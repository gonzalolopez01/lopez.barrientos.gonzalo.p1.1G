/*
 * datawarehouse.c
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#include <string.h>
#include "datawarehouse.h"


char nombres[10][20] = {"Juan","Pedro","Sofia","Miguel","Valentina","Camila","Andrea","Luis","Diego","Analia"};
int edades[10]={23,21,28,32,45,29,39,23,28,27};
char riesgo[10]={'s','s','n','n','n','n','s','n','n','s'};
int idProvincias[10]={5002,5002,5000,5001,5004,5003,5004,5001,5000,5004};

int harcodearPersonas(ePaciente lista[], int tam, int cant, int* pId)
{
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam)
	{
		contador = 0;
		for(int i=0; i<cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].nombre, nombres[i]);
			lista[i].edad = edades[i];
			lista[i].grupoRiesgo = riesgo[i];
			lista[i].idProvincia = idProvincias[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
