#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "cadena.h"


void
insertar_inicio (punto_t *p, punto_t **cab)
{
	punto_t *pun;
	pun = (punto_t*)malloc(sizeof(punto_t));
	if (pun == NULL){
	printf("no hay espacio para cabe");
	exit (EXIT_SUCCESS);
	
	}	
	
	//printf("dir p:    %u\n", cabeza);
	//printf("2 in cabeza: %u\n", cabeza);
	//printf("x creado,desde cabeza: %u\n", **cabeza);
	
	pun->x = p->x;
	pun->y = p->y;
	
	//printf("new p antes a: %u\n", pun->sig);
	
	pun->sig = *cab; 
	
	//printf("new p des. a: %u\n", pun->sig);
	
	//printf("pun dir : %u\n", pun);
	
	*cab = pun;
	
	
	
	//printf("x new p: %d\n", pun->x);
	//printf("y new p: %d\n", pun->y);
	
	
	//printf("dir new alloc:  %u  \n" , p);
	//printf("dir cab:  %u  \n" , *cab);
}

void
insertar_final (punto_t *p, punto_t **cab)
{
punto_t a;

a.sig = *cab;
//printf("cab es: %u\n" , cab);
//printf("*cab es: %u\n" , *cab);


	punto_t *pun;
	pun = (punto_t*)malloc(sizeof(punto_t));
	if (pun == NULL){
	printf("no hay espacio para cabe\n");
	exit (EXIT_SUCCESS);
	}
	
	
	if(*cab == 0){	
	pun->x = p->x;
	pun->y = p->y;
	pun->sig = *cab; 	
	*cab = pun;
	}
	
	else if((*cab)->sig == NULL){
	
	printf("hay un punto\n");
	
	pun->x = p->x;
	pun->y = p->y;
	
	(*cab)->sig = pun;
	pun->sig = NULL;

 	}
 	else{
	while(1){
	
	printf("dentro while\n");
	(*cab) = (*cab)->sig;
	
	if((*cab)->sig == NULL){

 	pun->x = p->x;
	pun->y = p->y;
	
	(*cab)->sig = pun;
	pun->sig = NULL;
	break;
			}
		}
	*cab = a.sig;
	}
	



}

void
recorrer (punto_t **cab)
{ 
//printf("Cab en rec. %u\n" , cab);
punto_t a;

a.sig = *cab;
 	//printf("dir cab de rec. : %u\n", cab);
 	//printf("en a: %p\n", a.sig);
 	
 	if( (*cab) == NULL){
 	
 	printf("--No hay puntos\n");

 	
 	}
 	else{
	while(1){

	printf("(%d, %d)\n", (*cab)->x , (*cab)->y);
	
	
	if((*cab)->sig == NULL){

 	//printf("(%d, %d)\n", (*cab)->x , (*cab)->y);
 	break;	}
 	
 	(*cab) = (*cab)->sig;
	
		}
	}
*cab = a.sig;	
}

void
extraer_inicio ( punto_t **cab)
{
	if( (*cab) == NULL){
 	printf("--No hay que elim...\n");}
 	else{
 	
 		if((*cab)->sig != NULL){
 		//printf("hay mas de uno\n" );
 		//printf("cambiando de %u\n" , *cab);
 		*cab = (*cab)->sig;
 		//printf("a: %u\n" , *cab);
 		}else{
 		//printf("hay uno\n" );
 		*cab = NULL;
 		
 		}
 	
 	}
 	
	
}

void
extraer_final ( punto_t **cab)
{
//comenzar contador
int c = 0;
int i;
punto_t a;
//remember cabeza begining
a.sig = *cab;
 	
 	if( (*cab) == NULL){
 	printf("--No hay puntos\n"); 	
 	}else if((*cab)->sig == NULL){

 	*cab = NULL;
 	}else{
	while(1){
	
	if((*cab)->sig == NULL){
	*cab = a.sig;
		  
  		for (i = 0; i < (c-1); ++i)
  		{
  		  (*cab) = (*cab)->sig;
  		}	
  		
  		(*cab)->sig = NULL;
  		
	
 	break;	}
 	//avanzar a siguiente y contar
 	printf("avanzando\n"); 
 	(*cab) = (*cab)->sig;
 	printf("c +1\n"); 
 	c++;
	
		}
		*cab = a.sig;	
	}



	
}


void
extraer_med(punto_t **cab){

//comenzar contador

int i;
//int j;

punto_t a;
//remember cabeza begining
a.sig = *cab;
//remember one after selected.
punto_t b;
int cn = 0;	
  		

 	if( (*cab) == NULL)
 	{
 	printf("--No hay puntos\n"); 	
 	}else 
 	if((*cab)->sig == NULL)
 	{
 	*cab = NULL;
 	printf("solo un ELEM\n"); 
 	}else
 	{
 	
 	printf("elegir pos. a elim. : \n");
	scanf("%d" ,&cn);

	printf("eligio pos. : %d\n" ,cn);

	//pasar uno mas de deseado y guardar pos
	for (i = 0; i < (cn+1); ++i)
  		{
  		  (*cab) = (*cab)->sig;
  		}
  	b.sig = (*cab);
  	//set head back
  	*cab = a.sig;
  		for (i = 0; i < (cn-1); ++i)
  		{
  		  (*cab) = (*cab)->sig;
  		}	
  		(*cab)->sig = b.sig; 
  		
  		*cab = a.sig;	
 		
	}	
		

}











