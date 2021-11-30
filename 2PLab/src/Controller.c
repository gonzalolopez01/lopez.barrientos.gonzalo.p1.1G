#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#include "emergencia.h"

#include "inputs.h"


int controller_loadFromText(char* path , LinkedList* pEmergencias)
{
	int returnAux = -1;
	if(path != NULL && pEmergencias != NULL){
		returnAux = 0;
		FILE* pFile;
		pFile = fopen(path,"r");
		if(pFile != NULL) {
			returnAux = parser_emergenciasFromText(pFile, pEmergencias);
			fclose(pFile);
		}
	}
    return returnAux;
}
int controller_listarEmergencias(LinkedList* listaEmergencias)
{
	int returnAux = -1;
	int len;
	eEmergencia* pEmergencia;
	if (listaEmergencias != NULL) {
		len = ll_len(listaEmergencias);
		for (int i = 0; i < len; i++) {
			pEmergencia = ll_get(listaEmergencias, i);

			emergencia_mostrarEmergencia(pEmergencia);
		}
		returnAux = 0;
	}
    return returnAux;
}
LinkedList* controller_mapBajas(LinkedList* listaEmergencias){
	LinkedList* listaMapeada = NULL;
	if(listaEmergencias != NULL){
		listaMapeada = ll_map(listaEmergencias, emergencia_mapBajas);
	}
	return listaMapeada;
}
int controller_saveTxt(LinkedList* listaEmergencias, char* path)
{
	int returnAux = -1;
	int len;
	int i;

	int auxId;
	char auxDesc[50];
	char auxcalle[50];
	int auxRecursos;
	int auxRubro;

	eEmergencia* pAux;
	len = ll_len(listaEmergencias);
	FILE* pFile;
	if(listaEmergencias!=NULL && path!=NULL && pFile!=NULL && len>0)
	{
		pFile = fopen(path,"w");
		if(pFile!=NULL)
		{
			fprintf(pFile,"id,descripcion,domicilio,recursos,rubroId\n");
			for(i=0; i<len; i++)
			{
				pAux = ll_get(listaEmergencias,i);
				if(pAux!=NULL)
				{
					emergencia_getId(pAux, &auxId);
					emergencia_getDesc(pAux, auxDesc);
					emergencia_getCalle(pAux, auxcalle);
					emergencia_getRecursos(pAux, &auxRecursos);
					emergencia_getRubroId(pAux, &auxRubro);
					fprintf(pFile,"%d,%s,%d,%d,%d,\n",auxId, auxDesc, auxcalle, auxRecursos, auxRubro);
				}
			}
			fclose(pFile);
			returnAux = 0;
		}
	}
	return returnAux;
}
int controller_menu_option() {
	int option;
	printf("****************************************************************************\n");
	printf("Emergencias\n");
	printf("****************************************************************************\n");
	printf("Menu:\n");
	printf("1. Cargar lista.\n");
	printf("2. Ordenar\n");
	printf("3. Imprimir por Pantalla\n");
	printf("4. opccion mapeado 4\n");
	printf("5. opcion guardar 5\n");
	printf("6. \n");
	printf("7. \n");
	printf("8. \n");
	printf("9. \n");
	printf("10. Salir\n");
	printf("*****************************************************************************\n");
	input_IntegerNumber(&option, "Ingrese la opcion deseada: ", "Error, valor incorrecto \n");
	return option;
}

void controller_Menu(LinkedList* listaEmergencias) {
	int option;
	char path[50];
	int format;
	char q;
	LinkedList* listaMapeada = NULL;

	do {
		option = controller_menu_option();
		switch (option) {
		case 1:
			input_strFileFormat(path, 50, "Nombre archivo: ", "nombre invalido, ingrese nuevamente: ");
			if(isThereFileTxt(path)){
				if(controller_loadFromText(path, listaEmergencias) > 0){
					printf("el archivo se cargo con exito.\n");
				}else{
					printf("el archivo no se cargo.\n");
				}
			}else{
				printf("el archivo %s no existe.\n", path);
			}
			break;
		case 2:
			ll_sort(listaEmergencias, emergencias_compareDescripcion, 1);
			break;
		case 3:
			printf("|| Id  ||      descripcion        ||          Direccion      ||recursos||rubroId||\n");
			controller_listarEmergencias(listaEmergencias);
			break;
		case 4:
			listaMapeada = controller_mapBajas(listaEmergencias);
			printf("listo.\n");
			break;
		case 5:
			input_strFileFormat(path, 50, "Nombre archivo: ",
					"nombre invalido, ingrese nuevamente: ");
			format = isStrFileFormat(path);
			if (format == 1) {
				if (isThereFileTxt(path)) {
					q = input_ClosedQuestion(
							"El archivo existe, desea sobreescribir? [s/n]: ","error, reingrese [s/n]: ");
					if (q == 's') {
						controller_saveTxt(listaMapeada,path);
						printf("El archivo se guardo con exito\n");
					}
				} else {
					controller_saveTxt(listaMapeada, path);
					printf("El archivo se guardo con exito\n");
				}
			} else {
				printf("Esta opcion guarda txt o csv.\n");
			}
			break;
		case 6:

			break;
		case 7:
			break;
		case 8:
			break;
		case 9:

		case 10:
			printf("fin del programa");
			option = 11;
			break;

		default:
			printf("---opcion invalida---\n");
			break;
		}
	} while (option != 11);
}

