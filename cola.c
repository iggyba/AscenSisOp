#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "estruc.h"

void
insertar_final (perso_ts *perso, perso_ts **ptper)
{

perso_ts a;

a.sig = *ptper;

	
	perso_ts *pun;
	pun = (perso_ts*)malloc(sizeof(perso_ts));
	if (pun == NULL){
	printf("no hay espacio para cabe");
	exit (EXIT_SUCCESS);
	
	}
	
	if(*ptper == 0){	
	
	pun->sig = *ptper; 	
	*ptper = pun;
	}
	
	
	else if((*ptper)->sig == NULL){
	
	
	(*ptper)->sig = pun;
	pun->sig = NULL;

 	}
 	else{
	while(1){

	
	(*ptper) = (*ptper)->sig;
	
	if((*ptper)->sig == NULL){

 	
	
	(*ptper)->sig = pun;
	pun->sig = NULL;
	break;
			}
	
		}
	*ptper = a.sig;
	}
	


}




void
recorrer (perso_ts **ptper ,perso_ts *per)
{ 
perso_ts a;

a.sig = *ptper;
 	//printf("dir cab de rec. : %u\n", cab);
 	//printf("en a: %p\n", a.sig);
 	
 	if( (*ptper) == NULL){
 	
 	printf("--No hay puntos\n");

 	
 	}
 	else{
	while(1){

	printf("(%d, %d)\n", (per)->id , (per)->p_act);
	
	
	if((*ptper)->sig == NULL){

 	//printf("(%d, %d)\n", (*cab)->x , (*cab)->y);
 	break;	}
 	
 	(*ptper) = (*ptper)->sig;
	
		}
	}
*ptper = a.sig;	
}
