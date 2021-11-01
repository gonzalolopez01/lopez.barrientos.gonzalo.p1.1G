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
/**
 * menu principal
 * @return: opcion elegida
 */
int menu();
/**
 * menu cuando el arreglo de pacientes esta vacio
 * @return: opcion elegida
 */
int menuVacio();
/**
 * menu para modificaciones
 * @return opcion elegida
 */
int menuModificacion();
/**
 * Inicializa el arreglo del tipo ePaciente al poner en 1 el campo isEmpty
 * @param lista: arreglo de tipo ePaciente
 * @param tam: tamanio del arreglo
 * @return -1 error. 0 exito
 */
int inicializarPersona(ePaciente lista[], int tam);
/**
 * busca en el arreglo algun campo isEmpty en estado 0
 * @param lista: arreglo de tipo ePaciente
 * @param tam: tamanio del arreglo
 * @return: -1 error o no hay posicion libre
 */
int buscarLibre(ePaciente lista[], int tam);
/**
 * ingresa un paciente el arreglo del tipo ePaciente
 * @param lista: arreglo ePaciente
 * @param tam: tamño del arreglo ePaciente
 * @param pId: puntero a varible que lleva la cuenta de los numeros de id
 * @param provincias: arreglo del tipo eProvincia
 * @param tamProv: tamaño del arreglo
 * @return -1 error 0 exito de ejecucion
 */
int altaPaciente(ePaciente lista[], int tam, int* pId, eProvincia provincias[], int tamProv);
int ingresoNombre(char nombre[]);
int ingresoEdad(int* pEdad);
char ingresoRiesgo();
/**
 *
 * @param idProvincia
 * @param provincias
 * @param tam
 * @return -1 error, 1 exito de ejecucion y validacion
 */
int ingresoIdProvincia(int* idProvincia, eProvincia provincias[], int tam);
/**
 * muestra un paciente
 * @param paciente
 * @param provincias
 * @param tam
 */
void mostrarPaciente(ePaciente paciente, eProvincia provincias[], int tam);
/**
 * muestra las variable de tipo paciente dentro de un arreglo
 * @param lista: arreglo del tipo ePaciente
 * @param tam: tamaño del arreglo ePaciente
 * @param provincias:  arreglo del tipo eProvincia
 * @param tamProv: tamaño del arreglo eProvincia
 * @return 0 error 1 exito en la ejecucion
 */
int mostrarPacientes(ePaciente lista[], int tam, eProvincia provincias[], int tamProv);
/**
 * busca un id determinado dentro de los campos de un arreglo del tipo ePaciente
 * @param lista: arreglo ePaciente
 * @param tam: tamaño del arreglo
 * @param id: id ingresado y que se va abuscar dentro del arreglo
 * @return -1 no se encontro el id pasado. > -1 el indice encontrado para el id ingresado
 */
int buscarPersonaId(ePaciente lista[], int tam, int id);
/**
 * Permite modificar los campos idProvincia y grupo de riesgo
 * @param pacientes: arreglo del tipo ePaciente
 * @param tamPac: tamaño del arreglo ePAciente
 * @param provincias: arrglo del tipo eProvincia
 * @param tamProv: tamaño del arreglo eParovincia
 * @return-1 error 0 exito
 */
int modificarPaciente(ePaciente pacientes[], int tamPac, eProvincia provincias[], int tamProv);
/**
 * permite hacer una baja logica en el arrglo de tipo ePaciente
 * @param lista: arreglo del tipo ePaciente
 * @param tam: tamaño
 * @param provincias: arreglo del tipo eProvincias
 * @param tamProv: tamaño
 * @return-1 error o baja cancelada. 0: baja con exito
 */
int bajaPersona(ePaciente lista[], int tam, eProvincia provincias[], int tamProv);
/**
 * ordena el arreglo de tipo ePaciente por provincia y grupo de riesgo
 * @param lista: arreglo del tipo ePaciente
 * @param tam: tamaño
 * @param provincias: arreglo del tipo eProcincias;
 * @param tamProv tamaño
 * @return-1 error. 0 exito en la ejecucion
 */
int ordenarPacientesProvinciaRiesgo(ePaciente lista[], int tam, eProvincia provincias[], int tamProv);


#endif /* PACIENTE_H_ */
