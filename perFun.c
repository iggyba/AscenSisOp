#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "estruc.h"

#include <errno.h>                                                              
#include <signal.h>   



void *
perFun (void * arg)
{

	perso_ts *perso = (perso_ts *)arg;
	
	//struct pthread *pd = (struct pthread *) perso->sched;
	
	/*
	printf("\n");
	
	printf("Thread persona %d creado\n", perso->id);
	printf("Persona en piso: %d\n" , perso->p_act);
	printf("Persona ira a: %d\n" , perso->p_des);
	printf("Persona estado: %d\n" , perso->estado);
	printf("Persona tiempo en piso: %d\n" , perso->remTime);
	
	printf("\n");*/
	
	//printf("ched? en fun: %u\n" , perso->sched);
	//printf("ched?en fun : %u\n" , &(perso->sched));
	//printf("ched? en fun: %s\n" , perso->sched);
	
	int mipos(perso_ts **ptper)
	{
	  int c = 0;
	  perso_ts a;
	a.sig = *ptper;
 	
	 	if( (*ptper) == NULL){ 	
	 	//printf("--No hay puntos\n"); 	
	 			}
 		else{
		while(1){
		//printf("INSIDE\n"); 
		//printf("IDDD %d\n", (*ptper)->id); 
		if((*ptper)->id == perso->id){
		
		 
		return c;
 		//printf("(%d, %d)\n", (*cab)->x , (*cab)->y);
 		break;			}
 		
 		c++;
 		(*ptper) = (*ptper)->sig;
 		
			}
		}
	*ptper = a.sig;	   
	}
	
	
	//-----------------
	while(TRUE){
	
	//generando nuevo piso rand.
	int r = rand()%PISOS;
	//generando nuevo tiempo rand.
	int s = rand()%15 + 1;
	
	//mientras no se acabe el tiempo bajar tiempo		
	usleep(1000000);
		//printf("--bajando T de: %d\n" , perso->remTime);
	perso->remTime = perso->remTime - 1;
		//printf("--A: %d\n" , perso->remTime);
		//printf("--");
		
		//si tiempo acaba moverse y elegir otro piso
		//llamar sched
	if(perso->remTime == 0){
		
		
		
		pthread_mutex_lock(&(perso->p_mutex)[perso->id]);
		//*(perso->cond) = TRUE;
		//printf("Per quiere mover\n");
		insertar_final(perso , perso->pcac);
		extraer_med(perso->pca, mipos(perso->pca));
		printf("Per: %d en cola\n", perso->id);
		pthread_kill( idthread , SIGUSR1);
		perso->remTime = s;
		//printf("--Tiempo ahora: %d\n" , (perso->remTime) ) ;
		pthread_mutex_unlock(&(perso->p_mutex)[perso->id]);
		
		perso->estado = MOVIENDOSE;
		/*
		printf("T EN 0: \n");
		printf("Per %d en: %d\n" ,perso->id, perso->p_act);
		while(r == perso->p_act){
			r = rand()%PISOS;
		}
		
		perso->p_des = r;
		printf("Per %d red a: %d\n" ,perso->id, perso->p_des);
		
		
		VOLVER A PENSAR
		perso->estado = PENSANDO;*/
		
		
		
	
		}
	//------------------
	}
	

	return NULL;
}
