/*
 * paciente.c
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#include "paciente.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "inputs.h"
#include "provincia.h"

#define TAM_STR 20

int menu()
{
	int opcion;
	printf("    *** ABM Pacientes ***\n\n");
	printf("1- Alta Paciente\n");
	printf("2- Modificar Pacientesn");
	printf("3- Baja Paciente\n");
	printf("4- Listar Pacientes\n");
	printf("5- Listar Provincias\n");
	printf("6- Listar Laboratorios\n");
	printf("7- Listar Vacunas\n");
	printf("8- Alta Inoculacion\n");
	printf("9- Listar Inoculaciones\n");
	printf("20- Salir\n");
	input_MenuOption(&opcion, "Ingrese la opcion deseada: ","Error, valor invalido. ",1,9,20, "Opcion invalida. ");
	return opcion;
}
int menuModificacion()
{
	int opcion;

	printf("1- Provincia\n");
	printf("2- Grupo de Riesgo\n");
	printf("3- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);
	return opcion;
}
int inicializarPersona(ePaciente lista[], int tam)
{
	int returnAux = -1;
	if(lista!=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			lista[i].isEmpty = 1;
		}
		returnAux = 0;
	}
	return returnAux;
}
int buscarLibre(ePaciente lista[], int tam)
{
	int returnAux = -1;
	if(lista != NULL && tam >0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}
int altaPaciente(ePaciente lista[], int tam, int* pId, eProvincia provincias[], int tamProv)
{
	int returnAux = -1;
	ePaciente auxPaciente;
	int indice;
	if(lista != NULL && tam > 0)
	{
		printf("ALTA PACIENTE\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1)
		{
			printf("no hay lugar");
		}
		else
		{
			ingresoNombre(auxPaciente.nombre);
			ingresoEdad(&auxPaciente.edad);
			auxPaciente.grupoRiesgo = ingresoRiesgo();
			ingresoIdProvincia(&auxPaciente.idProvincia, provincias, tamProv);
			auxPaciente.isEmpty = 0;
			auxPaciente.id = *pId;
			(*pId)++;//*pId = *pId+1;
		}
		lista[indice] = auxPaciente;
		returnAux = 0;
	}
	return returnAux;
}
int ingresoNombre(char nombre[])
{
	int returnAux = -1;
	if(nombre != NULL)
	{
		input_AlphaText(nombre, TAM_STR, "Ingrese Nombre: ","Error, Ingrese Nombre nuevamente: ");
		stringToProperName(nombre);
		returnAux = 0;
	}
	return returnAux;
}
int ingresoEdad(int* pEdad)
{
	int returnAux = -1;
	if(pEdad != NULL)
	{
		input_IntNumberMinMax(pEdad, "Ingrese edad: ", "Valor invalido, ingrese Edad: ", 1, 120, "Edad fuera de rango, ingrese nuevamente: ");
		returnAux = 0;
	}
	return returnAux;
}
char ingresoRiesgo()
{
	char riesgo;
	riesgo = input_ClosedQuestion("Es grupo de riesgo?[s/n] ", "Error. ");
	return riesgo;
}
int ingresoIdProvincia(int* idProvincia, eProvincia provincias[], int tam)
{
	int returnAux = -1;
	int flag=1;
	if(idProvincia != NULL && provincias != NULL && tam > 0)
	{
		mostrarProvincias(provincias, tam);
		do{
			input_IntegerNumber(idProvincia, "Ingrese ID de Provincia: ","Error, valor invalido, ingrese ID: ");
			for(int i=0; i<tam; i++)
			{
				if(*idProvincia == provincias[i].id)
				{
					returnAux = 0;
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				printf("ID desconocido. ");
			}
		}while (returnAux);
	}

	return returnAux;
}
//----------------------------
void mostrarPaciente(ePaciente paciente, eProvincia provincias[], int tam)
{
	char nombreProvincia[20];
	cargarNombreProvincia(provincias, tam, paciente.idProvincia, nombreProvincia);
	printf("%6d %-12s %-4d %-3c %-5d %15s\n",
						paciente.id,
						paciente.nombre,
						paciente.edad,
						paciente.grupoRiesgo,
						paciente.idProvincia,
						nombreProvincia);
}
int mostrarPacientes(ePaciente lista[], int tam, eProvincia provincias[], int tamProv)
{
	int returnAux = 0;
	int flag=1;
	if(lista != NULL && tam > 0)
	{
		printf("              *** Lista de Pacientes ***\n");
		printf("-----------------------------------------------------------\n");
		printf("  Id  Nombre   Edad  GrupoRiesgo idPRov  NombreProv\n");
		printf("-----------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarPaciente(lista[i], provincias, tamProv);
				flag=0;
			}
		}
		if(flag)
		{
			printf("No hay personas para mostrar\n");
		}
		returnAux = 1;
	}
	return returnAux;
}
int buscarPersonaId(ePaciente lista[], int tam, int id)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i<tam; i++)
		{
			if(lista[i].id == id && lista[i].isEmpty == 0)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int modificarPaciente(ePaciente pacientes[], int tamPac, eProvincia provincias[], int tamProv)
{
	int returnAux = -1;
	int indice;
	int idAux;
	char confirma;
	char auxGrupoRiesgo;
	int auxidProv;
	if(pacientes!= NULL && tamPac > 0 && provincias != NULL && tamProv >0)
	{
		printf("  *** Modificar Persona *** \n\n");
		input_IntegerNumber(&idAux, "Ingrese el ID del paciente a modificar", "Valor invalido, ingrese nuevamente: ");
		indice = buscarPersonaId(pacientes, tamPac, idAux);
		if(indice == -1)
		{
			printf("El id %d no esta registrado en el sistema", indice);
		}
		else
		{
			mostrarPaciente(pacientes[indice], provincias, tamProv);
			confirma = input_ClosedQuestion("confirma modificaion?" , "Valor invalido. ");
			if(confirma == 's')
			{
				switch(menuModificacion())
				{
				case 1://prov
					mostrarProvincias(provincias, tamProv);
					ingresoIdProvincia(&auxidProv, provincias, tamProv);
					pacientes[indice].idProvincia = auxidProv;
					break;
				case 2://gruporiesgo
					mostrarPacientes(pacientes, tamPac, provincias, tamProv);
					auxGrupoRiesgo = ingresoRiesgo();
					pacientes[indice].grupoRiesgo = auxGrupoRiesgo;
					break;
				default:
					printf("opcion invalida\n");
				}
			}
			else
			{
				printf("modificacion cancelada por el usuario\n");
			}
		}
		returnAux = 0;
	}
	return returnAux;
}
int bajaPersona(ePaciente lista[], int tam, eProvincia provincias[], int tamProv)
{
	int returnAux = -1;
	int indice;
	int id;
	char confirma;
	if(lista != NULL && tam >0)
	{
		printf("  *** Baja Persona *** \n\n");
		printf("Ingrese id: ");
		scanf("%d", &id);
		indice = buscarPersonaId(lista, tam, id);
		if(indice == -1)
		{
			printf("El id %d no esta registrado en el sistema", id);
		}
		else
		{
			mostrarPaciente(lista[indice], provincias, tamProv);
			confirma = input_ClosedQuestion("Confirma la baja? " , "Valor invalido. ");
			if(confirma == 's')
			{
				lista[indice].isEmpty = 1;
				returnAux = 0;
			}
			else
			{
				printf("baja cancelada por el usuario\n");
			}
		}
	}
	return returnAux;
}
