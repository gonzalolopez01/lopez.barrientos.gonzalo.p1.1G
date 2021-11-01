/*
 * paciente.h
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_
#include "provincia.h"

typedef struct
{
	int id;
	char nombre[20];
	int edad;
	char grupoRiesgo;
	int idProvincia;
	int isEmpty;
}ePaciente;

int menu();
int menuVacio();
int menuModificacion();
int inicializarPersona(ePaciente lista[], int tam);
int buscarLibre(ePaciente lista[], int tam);
int altaPaciente(ePaciente lista[], int tam, int* pId, eProvincia provincias[], int tamProv);
int ingresoNombre(char nombre[]);
int ingresoEdad(int* pEdad);
char ingresoRiesgo();
int ingresoIdProvincia(int* idProvincia, eProvincia provincias[], int tam);
void mostrarPaciente(ePaciente paciente, eProvincia provincias[], int tam);
int mostrarPacientes(ePaciente lista[], int tam, eProvincia provincias[], int tamProv);
int buscarPersonaId(ePaciente lista[], int tam, int id);
int modificarPaciente(ePaciente pacientes[], int tamPac, eProvincia provincias[], int tamProv);
int bajaPersona(ePaciente lista[], int tam, eProvincia provincias[], int tamProv);
int ordenarPacientesProvinciaRiesgo(ePaciente lista[], int tam, eProvincia provincias[], int tamProv);


#endif /* PACIENTE_H_ */
