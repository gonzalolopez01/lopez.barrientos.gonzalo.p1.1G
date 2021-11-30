#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "emergencia.h"

static int isValidId(int id);
static int isValidName(char* nombre);
//static int isValidVacunas(int vacunas);
//static int isValidHorasTrabajadas(int horasTrabajadas);
//static int isValidSueldo(int sueldo);


eEmergencia* emeregencia_New(){
	eEmergencia* newEmergencia;

	return  newEmergencia = (eEmergencia*)malloc(sizeof(eEmergencia));
}
eEmergencia* emergencia_newParametros(char* id, char* descripion, char* calle, char* recursos, char* rubroId) {
	eEmergencia* pEmergencia = emeregencia_New();
	if(pEmergencia != NULL) {
		if (emergencia_setId(pEmergencia, atoi(id))
				|| emergencia_setDesc(pEmergencia, descripion)
				|| emergencia_setCalle(pEmergencia, calle)
				|| emergencia_setRecursos(pEmergencia, atoi(recursos))
				|| emergencia_setRubroId(pEmergencia, atoi(rubroId))) {
			emergencia_delete(pEmergencia);
			pEmergencia = NULL;
		}
	}
	return pEmergencia;
}
void emergencia_delete(eEmergencia* pEmergencia){
	free(pEmergencia);
}
//-----------------------------------
int emergencia_setId(eEmergencia* this, int id){//id
	int success = -1;
	if(this != NULL && isValidId(id)){
		this->id = id;
		success = 0;
	}

	return success;
}
int emergencia_getId(eEmergencia* this, int* id){
	int success = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		success = 0;
	}

	return success;
}
//------------------------------------------
int emergencia_setDesc(eEmergencia* this, char* descripcion){ //nombre
	int success = -1;
	if (this != NULL && descripcion != NULL){// && isValidName(_nombre)
										//&& strlen(_nombre) > 0) {
		stringToProperName(descripcion);
		strcpy(this->descripcion, descripcion);
		success = 0;
	}

	return success;
}
int emergencia_getDesc(eEmergencia* this, char* descripcion){
	int success = -1;
	if (this != NULL && descripcion != NULL) {
		strcpy(descripcion, this->descripcion);
		success = 0;
	}
	return success;
}
//------------------------------------------
int emergencia_setCalle(eEmergencia* this, char* nombre){ //calle***************
	int success = -1;
	if (this != NULL && nombre != NULL){// && isValidName(_nombre)
										//&& strlen(_nombre) > 0) {
		stringToProperName(nombre);
		strcpy((*this).direccion, nombre);
		success = 0;
	}

	return success;
}
int emergencia_getCalle(eEmergencia* this, char* nombre){
	int success = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, (*this).direccion);
		success = 0;
	}
	return success;
}
//------------------------------------------
/*int emergencia_setAltura(eEmergencia* this, int altura){//altura
	int success = -1;
	if(this != NULL && isValidId(altura)){
		(*this).direccion.altura = altura;
		//(*this).fecha.dia = dia;
		success = 0;
	}

	return success;
}
int emergencia_getAltura(eEmergencia* this, int* altura){
	int success = -1;
	if(this != NULL && altura != NULL){
		*altura = (*this).direccion.altura;
		success = 0;
	}

	return success;
}*/
//------------------------------------------
int emergencia_setRecursos(eEmergencia* this, int recursos){//recursos
	int success = -1;
	if(this != NULL && isValidId(recursos)){
		this->id = recursos;
		success = 0;
	}

	return success;
}
int emergencia_getRecursos(eEmergencia* this, int* recursos){
	int success = -1;
	if(this != NULL && recursos != NULL){
		*recursos = this->recursos;
		success = 0;
	}

	return success;
}
//------------------------------------------
int emergencia_setRubroId(eEmergencia* this, int rubroId){//rubroId
	int success = -1;
	if(this != NULL && isValidId(rubroId)){
		this->rubroId = rubroId;
		success = 0;
	}

	return success;
}
int emergencia_getRubroId(eEmergencia* this, int* rubroId){
	int success = -1;
	if(this != NULL && rubroId != NULL){
		*rubroId = this->rubroId;
		success = 0;
	}

	return success;
}
//------------------------------------------
static int isValidId(int id) {
	int answer = 0;
	if(id > 0) {
		answer = 1;
	}
	return answer;
}

static int isValidName(char* nombre) {
	int returnAux = 0;
	if(isStringAlpha(nombre) && strlen(nombre)<50) {
		returnAux = 1;
    }
	return returnAux;
}
//---------------
int emergencias_compareDescripcion(void* pAuxiliary1, void* pAuxiliary2){
	int compare = 0;
	eEmergencia* pAux1;
	eEmergencia* pAux2;
	pAux1 = (eEmergencia*)pAuxiliary1;
	pAux2 = (eEmergencia*)pAuxiliary2;
	char pAux1Nombre[50];
	char pAux2Nombre[50];
	emergencia_getDesc(pAux1, pAux1Nombre);
	emergencia_getDesc(pAux2, pAux2Nombre);

	if(pAux1!=NULL && pAux2!=NULL){
		compare = strcmp(pAux1Nombre, pAux2Nombre);
		if(compare > 0)	{
			compare = 1;
		}else{
				compare = -1;
			}
		}
	return compare;
}
//------------------

int emergencia_mostrarEmergencia(eEmergencia* pEmergencia) {
	int success = -1;
	if(pEmergencia != NULL) {
		int id;
		char descripcion[50];
		int direccion[50];
		int recursos;
		int rubroId;

		emergencia_getId(pEmergencia, &id);
		emergencia_getDesc(pEmergencia, descripcion);
		emergencia_getCalle(pEmergencia, direccion);
		emergencia_getRecursos(pEmergencia, &recursos);
		emergencia_getRubroId(pEmergencia, &rubroId);
		printf("||%5d||%25s||%25s||%5d||%5d||\n", id, descripcion, direccion, recursos, rubroId);
		success = 0;
	}
	return success;
}
void* emergencia_mapBajas(void* pEmer){
	eEmergencia *pAux = NULL;

	if (pEmer != NULL) {
		pAux = (eEmergencia*) pEmer;

		//var aux
		int auxId;
		char auxDesc[50];
		char auxCalle[50];
		int auxRecursos;
		int auxRubroId;


		//recibo los datos de la emergencia

		emergencia_getId(pAux, &auxId);
		emergencia_getDesc(pAux, auxDesc);
		emergencia_getCalle(pAux, auxCalle);
		emergencia_getRecursos(pAux, &auxRecursos);
		emergencia_getRubroId(pAux, &auxRubroId);


		//modifico var y las mando con el aux

		if(auxRubroId == 1 && auxRecursos >= 15){
			auxRecursos = auxRecursos -2;
		}
		if(auxRubroId == 4 && auxRecursos <= 20){
			auxRecursos = auxRecursos - 1;
		}
		emergencia_setId(pAux, auxId);
		emergencia_setDesc(pAux, auxDesc);
		emergencia_setCalle(pAux, auxCalle);
		emergencia_setRecursos(pAux, auxRecursos);
		emergencia_setRubroId(pAux, auxRubroId);

	}
	return (void*) pAux;
}
