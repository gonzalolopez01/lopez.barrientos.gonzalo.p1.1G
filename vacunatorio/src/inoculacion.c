/*
 * inoculacion.c
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#include "inoculacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "inputs.h"
/*int menu()
{
	int opcion;
	printf("    *** ABM Pacientes ***\n\n");
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
}*/
/*int menuModificacion()
{
	int opcion;

	printf("1- Provincia\n");
	printf("2- Grupo de Riesgo\n");
	printf("3- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);
	return opcion;
}*/
int inicializarInoculacion(eInoculacion lista[], int tam)
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

int inoculacionesBuscarLibre(eInoculacion inoculaciones[], int tamInoculaciones)
{
	int returnAux = -1;
	if(inoculaciones != NULL && tamInoculaciones >0)
	{
		for(int i=0; i<tamInoculaciones; i++)
		{
			if(inoculaciones[i].isEmpty)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}
int altaInoculacion(eInoculacion lista[], int tam, int* pId, ePaciente pacientes[], int tamPacientes,
					eVacuna vacunas[], int tamVacunas, eProvincia provincias[], int tamProvincias)
{
	int returnAux = -1;
	eInoculacion auxInoculacion;
	int indice;
	if(lista != NULL && tam > 0)
	{
		printf("ALTA INOCULACION\n");

		indice = inoculacionesBuscarLibre(lista, tam);
		if(indice == -1)
		{
			printf("no hay lugar para ingresar una inoculacion");
		}
		else
		{
			ingresoIdPaciente(&auxInoculacion.idPaciente, pacientes, tamPacientes, provincias, tamProvincias);
			ingresoIdVacuna(&auxInoculacion.idVacuna, vacunas, tamVacunas);
			ingresoFecha(&auxInoculacion.fecha);
			auxInoculacion.isEmpty = 0;
			auxInoculacion.id = *pId;
			(*pId)++;//*pId = *pId+1;
		}
		lista[indice] = auxInoculacion;
		returnAux = 0;
	}
	return returnAux;
}

int ingresoIdPaciente(int* idProvincia, ePaciente pacientes[], int tamPacientes,
										eProvincia provincias[], int tamProvincias)
{
	int returnAux = -1;
	int flag=1;
	if(idProvincia != NULL && pacientes != NULL && tamPacientes > 0 && provincias != NULL && tamProvincias > 0)
	{
		mostrarPacientes(pacientes, tamPacientes, provincias, tamProvincias);
		do{
			input_IntegerNumber(idProvincia, "Ingrese ID de Provincia: ","Error, valor invalido, ingrese ID: ");
			for(int i=0; i<tamProvincias; i++)
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
int ingresoIdVacuna(int* idVacuna, eVacuna vacunas[], int tamVacunas)
{
	int returnAux = -1;
	int flag=1;
	if(idVacuna != NULL && vacunas != NULL && tamVacunas)
	{
		mostrarVacunas(vacunas, tamVacunas);
		do{
			input_IntegerNumber(idVacuna, "Ingrese ID de Vacuna: ","Error, valor invalido, ingrese ID: ");
			for(int i=0; i<tamVacunas; i++)
			{
				if(*idVacuna == vacunas[i].id)
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
int ingresoFecha(eFecha* fecha)
{
	int returnAux = -1;
	if(fecha != NULL)
	{
		input_date(&fecha->dia, &fecha->mes, &fecha->anio, 2020, 2021);
		returnAux = 0;
	}
	return returnAux;
}
//----------------------------
void mostrarIncoulacion(eInoculacion incoulacion)
{
	printf("%10d %15d %10d   %02d/%02d/%d\n",
						incoulacion.id,
						incoulacion.idPaciente,
						incoulacion.idVacuna,
						incoulacion.fecha.dia,
						incoulacion.fecha.mes,
						incoulacion.fecha.anio);
}
int mostrarInoculaciones(eInoculacion inoculaciones[], int tamInoculaciones)
{
	int returnAux = 0;
	int flag=1;
	if(inoculaciones != NULL && tamInoculaciones > 0)
	{
		printf("              *** Lista de Inoculaciones ***\n");
		printf("-----------------------------------------------------------\n");
		printf("  IdInoculacion  idPaciente   idVacuna  fecha\n");
		printf("-----------------------------------------------------------\n");
		for(int i=0; i<tamInoculaciones; i++)
		{
			if(inoculaciones[i].isEmpty == 0)
			{
				mostrarIncoulacion(inoculaciones[i]);
				flag=0;
			}
		}
		if(flag)
		{
			printf("No hay inoculaciones para mostrar\n");
		}
		returnAux = 1;
	}
	return returnAux;
}
/*int buscarPersonaId(ePaciente lista[], int tam, int id)
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
		input_IntegerNumber(&id, "Ingrese id: ", "Valor invalido. ");
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
*/
