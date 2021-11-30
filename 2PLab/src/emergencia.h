#ifndef emergencia_H_INCLUDED
#define emergencia_H_INCLUDED

#include "LinkedList.h"
#include "inputs.h"

typedef struct{
	char calle[50];
	int altura;
}eDireccion;

typedef struct
{
	int id;
    char descripcion[50];
    char direccion[50];
	int recursos;
	int rubroId;
}eEmergencia;

eEmergencia* emeregencia_New();
eEmergencia* emergencia_newParametros(char* id, char* descripion, char* calle, char* recursos, char* rubroId);
void emergencia_delete(eEmergencia* pEmergencia);
int emergencia_setId(eEmergencia* this, int id);
int emergencia_getId(eEmergencia* this, int* id);
int emergencia_setDesc(eEmergencia* this, char* descripcion);
int emergencia_getDesc(eEmergencia* this, char* descripcion);
int emergencia_setCalle(eEmergencia* this, char* nombre);
int emergencia_getCalle(eEmergencia* this, char* nombre);
//int emergencia_setAltura(eEmergencia* this, int altura);
//int emergencia_getAltura(eEmergencia* this, int* altura);
int emergencia_setRecursos(eEmergencia* this, int recursos);
int emergencia_getRecursos(eEmergencia* this, int* recursos);
int emergencia_setRubroId(eEmergencia* this, int rubroId);
int emergencia_getRubroId(eEmergencia* this, int* rubroId);

int emergencias_compareDescripcion(void* pAuxiliary1, void* pAuxiliary2);
void* emergencia_mapBajas(void* pEmer);

#endif // emergencia_H_INCLUDED
