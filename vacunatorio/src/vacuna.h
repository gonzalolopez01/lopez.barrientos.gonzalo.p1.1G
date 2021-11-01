/*
 * vacuna.h
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */

#ifndef VACUNA_H_
#define VACUNA_H_

typedef struct
{
	int id;
	char nombre[20];
	float precio;
	int idLaboratorio;
}eVacuna;
/**
 * muestra el contenido los campos que tiene la variable del tipo eVacuna
 * @param vacuna: variable a mostrar
 */
void mostrarVacuna(eVacuna vacuna);
/**
 * muestra el contenido los campos que tienen las variables dentro de un arreglo del tipo eVacuna
 * @param vacunas: array de tipo evacuna
 * @param tam: tamaño del array
 * @return
 */
int mostrarVacunas(eVacuna vacunas[], int tam);

#endif /* VACUNA_H_ */
