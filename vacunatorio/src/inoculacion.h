/*
 * inoculacion.h
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#ifndef INOCULACION_H_
#define INOCULACION_H_
#include "fecha.h"
#include "paciente.h"
#include "provincia.h"
#include "vacuna.h"


typedef struct
{
	int id;
	int idPaciente;
	int idVacuna;
	eFecha fecha;
	int isEmpty;
}eInoculacion;

int inicializarInoculacion(eInoculacion lista[], int tam);
int inoculacionesBuscarLibre(eInoculacion inoculaciones[], int tamInoculaciones);
int altaInoculacion(eInoculacion lista[], int tam, int* pId, ePaciente pacientes[], int tamPacientes,
					eVacuna vacunas[], int tamVacunas, eProvincia provincias[], int tamProvincias);
int ingresoIdPaciente(int* idProvincia, ePaciente pacientes[], int tamPacientes,
										eProvincia provincias[], int tamProvincias);
int ingresoIdVacuna(int* idVacuna, eVacuna vacunas[], int tamVacunas);
int ingresoFecha(eFecha* fecha);
void mostrarIncoulacion(eInoculacion incoulacion);
int mostrarInoculaciones(eInoculacion inoculaciones[], int tamInoculaciones);
#endif /* INOCULACION_H_ */
