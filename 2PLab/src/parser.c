#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "emergencia.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_emergenciasFromText(FILE* pFile , LinkedList* emergencias) {
	int returnAux = -1;
	if(pFile != NULL && emergencias != NULL) {
		returnAux = 0;
		char id[10];
		char desc[50];
		char calle[50];
		char recursos[10];
		char rubroId[10];

		eEmergencia* pEmergencia;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, desc, calle, recursos, rubroId);

		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, desc, calle, recursos, rubroId) == 5){
				pEmergencia = emergencia_newParametros(id, desc, calle, recursos, rubroId);
				if(pEmergencia != NULL){
					ll_add(emergencias, pEmergencia);
					returnAux++;
				}
			}
		}
	}
    return returnAux;
}


/*int parser_paisFromBinary(FILE* pFile , LinkedList* pPaises){
	int returnAux = -1;
	if(pFile != NULL && pPaises != NULL) {
		ePais* pPais;
		returnAux = 0;
		while(!feof(pFile)){//hasta el final del archivo
			pPais = pais_new();//reserva espacio en memoria para recibir el dato
			if(pPais != NULL && fread(pPais,sizeof(ePais),1,pFile)) {//si levanta el dato entra
				if(feof(pFile))	{
					break;
				}
				ll_add(pPaises, pPais);//agregar un elemento a la lista
				returnAux++;//lleva la cuenta de los agregados
			}
		}
	}
    return returnAux;
}*/

