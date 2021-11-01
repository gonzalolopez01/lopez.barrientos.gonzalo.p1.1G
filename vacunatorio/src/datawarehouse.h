/*
 * datawarehouse.h
 *
 *  Created on: Oct 25, 2021
 *      Author: gonzalo
 */
#include "paciente.h"
#include "inoculacion.h"
#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_


/**
 * hardcodea los datos para el arreglo de pacientes
 * @param lista: arreglo de tipo ePacientes
 * @param tam: tamaño arreglo ePacientes
 * @param cant: cantidad de elementos a ingresar
 * @param pId: puntero a variable int contador
 * @return: -1 error. 0 o mas: cantidad de ingresos
 */
int harcodearPersonas(ePaciente lista[], int tam, int cant, int* pId);

#endif /* DATAWAREHOUSE_H_ */
