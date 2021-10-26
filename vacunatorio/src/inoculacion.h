/*
 * inoculacion.h
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#ifndef INOCULACION_H_
#define INOCULACION_H_
#include "fecha.h"

typedef struct
{
	int id;
	int idPaciente;
	int idVacuna;
	eFecha fecha;
}eInoculacion;

#endif /* INOCULACION_H_ */
