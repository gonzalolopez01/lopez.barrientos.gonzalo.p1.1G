/*
 * laboratorio.h
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#ifndef LABORATORIO_H_
#define LABORATORIO_H_

typedef struct
{
	int id;
	char nacionalidad[20];
}eLaboratorio;

void mostrarLaboratorio(eLaboratorio laboratorio);
int mostrarLaboratorios(eLaboratorio laboratorios[], int tam);

#endif /* LABORATORIO_H_ */
