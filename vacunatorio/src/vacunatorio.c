/*
 ============================================================================
 Name        : vacunatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "datawarehouse.h"
#include "laboratorio.h"
#include "provincia.h"
#include "vacuna.h"

#define TAM_LAB 4
#define TAM_PROV 5
#define TAM_VAC 6
#define TAM_PAC 10

int main(void) {
	setbuf(stdout,NULL);

	int nextId = 20000;

	eLaboratorio laboratorios[TAM_LAB] = {{1000,"Chino"},{1001,"Ingles"},{1002,"USA"},{1003,"Ruso"}};
	eProvincia provincias[TAM_PROV] = {{5000,"BsAs"},{5001,"Mendoza"},{5002,"Cordoba"},{5003,"San Luis"},{5004,"Corrientes"}};
	eVacuna vacunas[TAM_VAC] = {{20000,"Pfyzer",450,1002},
								{20001,"Moderna",500,1001},
								{20002,"Cancino",4000,1000},
								{20003,"Synopharm",410,1000},
								{20004,"Sputnik",390,1003},
								{20005,"Jhonson",470,1002}};
	ePaciente pacientes[TAM_PAC];

	char seguir = 's';

		if(inicializarPersona(pacientes, TAM_PAC))
		{
			printf("Problema al inicializar!\n");
		}
		harcodearPersonas(pacientes, TAM_PAC, 5, &nextId);

		do{
			switch(menu())
			{
			case 1:
				if(altaPaciente(pacientes, TAM_PAC, &nextId, provincias, TAM_PROV))
				{
					printf("No se pudo realizar el alta\n");
				}
				else
				{
					printf("Alta exitosa!!!\n");
				}
				break;
			case 3:
				if(bajaPersona(pacientes, TAM_PAC, provincias, TAM_PROV))
				{
					printf("no se pudo realizar la baja\n");//mostrarMujeres(lista, TAM, localidades, TAM_LOC);
				}
				break;
			case 2:
				if(modificarPaciente(pacientes, TAM_PAC, provincias, TAM_PROV))
				{
					printf("no se pudo realizar la modificacion\n");
				}
				break;
			case 4:
				mostrarPacientes(pacientes, TAM_PAC, provincias, TAM_PROV);
				/*if(ordenarPersonas(lista, TAM))
				{
					printf("no se pudo realizar el ordenamiento\n");
				}
				else
				{
					printf("ordenamiento exitoso\n");
				}*/
				break;
			case 5:
				mostrarProvincias(provincias, TAM_PROV);
				break;
			case 6:
				mostrarLaboratorios(laboratorios,TAM_LAB);
				break;
			case 7:
				mostrarVacunas(vacunas, TAM_VAC);
				break;
			case 10:
				printf("Ha seleccionado salir\n");
				seguir = 'n';
				break;
			default:
				printf("Opcion invalida");
			}
			//agregar presione una tecla para continuar

		}while(seguir == 's');

	return EXIT_SUCCESS;
}
