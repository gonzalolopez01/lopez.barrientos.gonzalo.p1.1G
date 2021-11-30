/*
 ============================================================================
 Name        : 2PLab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#include "Controller.h"


int main(void) {
	setbuf(stdout,NULL);

	LinkedList* listaEmergencias = ll_newLinkedList();

	controller_Menu(listaEmergencias);

	return EXIT_SUCCESS;
}
