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
	pun->id      = perso->id;
  	pun->p_act   = perso->p_act;
  	pun->p_des   = perso->p_des;  
  	pun->estado  = perso->estado;
  	pun->remTime = perso->remTime;
  	pun->cola    = perso->cola;	
	pun->sig = *ptper; 	
	*ptper = pun;
	}	
	else if((*ptper)->sig == NULL){	
	pun->id      = perso->id;
  	pun->p_act   = perso->p_act;
  	pun->p_des   = perso->p_des;  
  	pun->estado  = perso->estado;
  	pun->remTime = perso->remTime;
  	pun->cola    = perso->cola;	
	(*ptper)->sig = pun;
	pun->sig = NULL;
 	}
 	else{
	while(1){	
	(*ptper) = (*ptper)->sig;	
	if((*ptper)->sig == NULL){	
	pun->id      = perso->id;
  	pun->p_act   = perso->p_act;
  	pun->p_des   = perso->p_des;  
  	pun->estado  = perso->estado;
  	pun->remTime = perso->remTime;
  	pun->cola    = perso->cola;	
	(*ptper)->sig = pun;
	pun->sig = NULL;
	break;
			}
	
		}
	*ptper = a.sig;
	}
	


}

void
extraer_med(perso_ts **ptper, int cn){

//comenzar contador

int i;

perso_ts a;
//remember cabeza begining
a.sig = *ptper;
//remember one after selected.
perso_ts b;
//int cn = 0;  		

 	if( (*ptper) == NULL)
 	{
 	printf("--No hay puntos\n"); 	
 	}else 
 	if((*ptper)->sig == NULL)
 	{
 	*ptper = NULL;
 	}else
 	{
 	
 	//printf("elegir pos. a elim. : \n");
	//scanf("%d" ,&cn);

	printf("Alguien a:%d\n" ,cn);

	//pasar uno mas de deseado y guardar pos
	for (i = 0; i < (cn+1); ++i)
  		{
  		  (*ptper) = (*ptper)->sig;
  		}
  	b.sig = (*ptper);
  	//set head back
  	*ptper = a.sig;
  		for (i = 0; i < (cn-1); ++i)
  		{
  		  (*ptper) = (*ptper)->sig;
  		}	
  		(*ptper)->sig = b.sig;	
  		
  		*ptper = a.sig;	 	
 		
	}	
		

}



void
recorrer (perso_ts **ptper )
{ 
perso_ts a;

a.sig = *ptper;
//printf("cab en fun: %u", ptper);



 	//printf("dir cab de rec. : %u\n", cab);
 	//printf("en a: %p\n", a.sig);
 	
 	if( (*ptper) == NULL){
 	
 	printf("--No hay puntos\n");

 	
 	}
 	else{
	while(1){
	
	printf("(id: %d)\n", (*ptper)->id /*, (*ptper)->p_act*/);
	usleep(10000);
	
	
	if((*ptper)->sig == NULL){

 	//printf("(%d, %d)\n", (*cab)->x , (*cab)->y);
 	break;	}
 	
 	(*ptper) = (*ptper)->sig;
	
		}
	}
*ptper = a.sig;	
}
