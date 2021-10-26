/*
 * provincia.h
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#ifndef PROVINCIA_H_
#define PROVINCIA_H_

typedef struct
{
	int id;
	char nombreProvincia[20];
}eProvincia;

void mostrarProvincia(eProvincia provincia);
int mostrarProvincias(eProvincia provincias[], int tam);
int cargarNombreProvincia(eProvincia provincias[], int tam, int idProvincia , char descripcion[]);

#endif /* PROVINCIA_H_ */
