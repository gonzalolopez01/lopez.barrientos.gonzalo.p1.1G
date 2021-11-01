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
/**
 * menu principal
 * @return: opcion elegida
 */
int menu()
{
	int opcion;
	printf("\n    *** ABM Pacientes ***\n\n");
	printf("1- Alta Paciente\n");
	printf("2- Modificar Pacientes\n");
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
/**
 * menu cuando el arreglo de pacientes esta vacio
 * @return: opcion elegida
 */
int menuVacio()
{
	int opcion;
	printf("\n    *** ABM Pacientes ***\n\n");
	printf("1- Alta Paciente\n");
	printf("2- Salir\n");
	input_MenuOption(&opcion, "Ingrese la opcion deseada: ","Error, valor invalido. ",1,1,2, "Opcion invalida. ");
	return opcion;
}
/**
 * menu para modificaciones
 * @return opcion elegida
 */
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
/**
 * Inicializa el arreglo del tipo ePaciente al poner en 1 el campo isEmpty
 * @param lista: arreglo de tipo ePaciente
 * @param tam: tamanio del arreglo
 * @return -1 error. 0 exito
 */
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
/**
 * busca en el arreglo algun campo isEmpty en estado 0
 * @param lista: arreglo de tipo ePaciente
 * @param tam: tamanio del arreglo
 * @return: -1 error o no hay posicion libre
 */
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
/**
 * ingresa un paciente el arreglo del tipo ePaciente
 * @param lista: arreglo ePaciente
 * @param tam: tamño del arreglo ePaciente
 * @param pId: puntero a varible que lleva la cuenta de los numeros de id
 * @param provincias: arreglo del tipo eProvincia
 * @param tamProv: tamaño del arreglo
 * @return -1 error 0 exito de ejecucion
 */
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
/**
 * muestra un paciente
 * @param paciente
 * @param provincias
 * @param tam
 */
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
/**
 * muestra las variable de tipo paciente dentro de un arreglo
 * @param lista: arreglo del tipo ePaciente
 * @param tam: tamaño del arreglo ePaciente
 * @param provincias:  arreglo del tipo eProvincia
 * @param tamProv: tamaño del arreglo eProvincia
 * @return 0 error 1 exito en la ejecucion
 */
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
/**
 * busca un id determinado dentro de los campos de un arreglo del tipo ePaciente
 * @param lista: arreglo ePaciente
 * @param tam: tamaño del arreglo
 * @param id: id ingresado y que se va abuscar dentro del arreglo
 * @return -1 no se encontro el id pasado. > -1 el indice encontrado para el id ingresado
 */
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
/**
 * Permite modificar los campos idProvincia y grupo de riesgo
 * @param pacientes: arreglo del tipo ePaciente
 * @param tamPac: tamaño del arreglo ePAciente
 * @param provincias: arrglo del tipo eProvincia
 * @param tamProv: tamaño del arreglo eParovincia
 * @return-1 error 0 exito
 */
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
		input_IntegerNumber(&idAux, "Ingrese el ID del paciente a modificar: ", "Valor invalido, ingrese nuevamente: ");
		indice = buscarPersonaId(pacientes, tamPac, idAux);
		if(indice == -1)
		{
			printf("El id %d no esta registrado en el sistema", indice);
		}
		else
		{
			mostrarPaciente(pacientes[indice], provincias, tamProv);
			confirma = input_ClosedQuestion("confirma modificaion?[s/n]: " , "Valor invalido. ");
			if(confirma == 's')
			{
				switch(menuModificacion())
				{
				case 1://prov
					//mostrarProvincias(provincias, tamProv);
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
/**
 * permite hacer una baja logica en el arrglo de tipo ePaciente
 * @param lista: arreglo del tipo ePaciente
 * @param tam: tamaño
 * @param provincias: arreglo del tipo eProvincias
 * @param tamProv: tamaño
 * @return-1 error o baja cancelada. 0: baja con exito
 */
int bajaPersona(ePaciente lista[], int tam, eProvincia provincias[], int tamProv)
{
	int returnAux = -1;
	int indice;
	int id;
	char confirma;
	if(lista != NULL && tam >0)
	{
		mostrarPacientes(lista, tamProv, provincias, tamProv);
		printf("  *** Baja Persona *** \n\n");
		input_IntegerNumber(&id, "Ingrese id: ", "Valor invalido. ");
		indice = buscarPersonaId(lista, tam, id);
		if(indice == -1)
		{
			printf("El id %d no esta registrado en el sistema", id);
		}
		else
		{
			printf("-----------------------------------------------------------\n");
			printf("  Id  Nombre   Edad  GrupoRiesgo idPRov  NombreProv\n");
			printf("-----------------------------------------------------------\n");
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
/**
 * ordena el arreglo de tipo ePaciente por provincia y grupo de riesgo
 * @param lista: arreglo del tipo ePaciente
 * @param tam: tamaño
 * @param provincias: arreglo del tipo eProcincias;
 * @param tamProv tamaño
 * @return-1 error. 0 exito en la ejecucion
 */
int ordenarPacientesProvinciaRiesgo(ePaciente lista[], int tam, eProvincia provincias[], int tamProv)
{
	int returnAux = -1;
	ePaciente auxPaciente;
	char provinciaI[20];
	char provinciaJ[20];
	if(lista != NULL && tam > 0)
	{
		for(int i=0; i<tam-1; i++)
		{

			for(int j=i+1; j<tam; j++)
			{
				cargarNombreProvincia(provincias, tamProv, lista[i].idProvincia, provinciaI);
				cargarNombreProvincia(provincias, tamProv, lista[j].idProvincia, provinciaJ);
				if((strcmp(provinciaI, provinciaJ) > 0) ||
					((strcmp(provinciaI, provinciaJ) == 0) && (lista[i].grupoRiesgo > lista[j].grupoRiesgo)))
				{
					auxPaciente = lista[i];
					lista[i] = lista[j];
					lista[j] = auxPaciente;
				}
			}
		}
		returnAux = 0;
	}

	return returnAux;
}
