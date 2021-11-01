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
/**
 * busca un id en el arreglo de tipo eProvincia y carga la descripcion correspondiente a ese id
 * @param provincias: arreglo de tipo eProvincia
 * @param tam: tamaño del arreglo eProvincia
 * @param idProvincia: el numero de Id a buscar
 * @param descripcion: string con la descripcion
 * @return-1 error, 0 exito al ejecutar, 1 encontro el id buscado
 */
int cargarNombreProvincia(eProvincia provincias[], int tam, int idProvincia , char descripcion[]);
/**
 * valida el id de provincia
 * @param id
 * @param provincias arreglo de tipo eProvincia
 * @param tam: tamaño arreglo
 * @return 0: no encontro el id, 1: lo encontro
 */
int validarLocalidad(int id, eProvincia provincias[], int tam);


#endif /* PROVINCIA_H_ */
