#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "emergencia.h"

int controller_loadFromText(char* path , LinkedList* pEmergencias);
int controller_listarEmergencias(LinkedList* listaEmergencias);
int controller_menu_option();
void controller_Menu(LinkedList* listaEmergencias);
int controller_saveTxt(LinkedList* listaEmergencias, char* path);

#endif //CONTROLLER_H_INCLUDED
