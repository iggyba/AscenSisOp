#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "estruc.h"

#include <errno.h>                                                              
#include <signal.h>
#include <string.h>  

int
main()
{
	pthread_t elevad_t;
	pthread_t sched_t;
	pthread_t perso_t[PERSONS];
	
	
	
	//printf("ched?: %u\n" , sched_t);
	//printf("ched?: %u\n" , &sched_t);
	
	
	
	perso_ts perso[PERSONS];
	
	//puntero personas
	perso_ts *ptper[PERSONS];
	for (int i = 0; i < PERSONS; i++)
	{	
	ptper[i] = &(perso[i]);
	}
	
	
	//cabezas pisos
	perso_ts *cabp[PISOS];
	perso_ts **pca[PISOS];	
	
	//cabezas colas
	perso_ts *cabc[PISOS];
	perso_ts **pcac[PISOS];	
	
	//cabeza elevador
	perso_ts *cabe;
	perso_ts **pcae;
	cabe = NULL;	
	pcae = &cabe;
		
	int status;
	
	
	for (int i = 0; i < PISOS; i++)
	{
	cabp[i] = NULL;	
	pca[i]  = &(cabp[i]);
	cabc[i] = NULL;	
	pcac[i] = &(cabc[i]);
	
	}
	
	//printf("cab en main: %u", pca[0]);
	
	
	
	srand(time(NULL));
	

	int cond[PERSONS];
	
	int cond1 = FALSE;

	pthread_mutex_t p_mutex[PERSONS];
	pthread_cond_t p_cond[PERSONS];
	
	pthread_mutex_t  p_mutex1 = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t p_cond1 = PTHREAD_COND_INITIALIZER;
	
	
	//pthread_mutex_t p_mutexP[PERSONS];
	//pthread_cond_t  p_condP[PERSONS];
	
	//init sched
	sched_ts sched = { .p_cond = &(p_cond1) , .p_mutex = &(p_mutex1) 
	, .cond = &(cond1)};
	
	
	//init elevator
	elevador_t elev = { .p_act = 1 , .p_des = 1 , 
	.estado = NADA , .p_cond = &(p_cond1) , .p_mutex = &(p_mutex1) 
	, .cond = &(cond1)};
	
	
	
	//INITIALIZE
	init(perso , ptper , pcac, pca, p_mutex, p_cond, cond, sched_t);
	
	usleep(100000);
	for (int i = 0; i < PERSONS; i++)
	{
		printf("persona: %d en piso: %d\n" ,perso[i].id , perso[i].p_act );
		
	}
	
	
	usleep(2000000);
	
	for (int i = 0; i < PISOS; i++)
	{
		printf("Piso: %d\n", i);
		recorrer(pca[i]);
		
	}
	
	usleep(1000000);
	
	pthread_create (&sched_t, NULL, schedFun, (void *)(&sched));
	
	pthread_create (&elevad_t, NULL, elevFun, (void *)(&elev));

	

	for (int i = 0; i < PERSONS; i++){
		status = pthread_create ( &(perso_t[i]), NULL, perFun , (void *)(&perso[i]));
		if ( status <  0) { 
		 perror("pthread_create failed!!!!");    
		} 
		usleep(100000);
		}
		
		
	usleep(4000000);	
	for (int i = 0; i < PISOS; i++)
	{
		printf("Cola: %d\n", i);
		recorrer(pcac[i]);
		
	}
	for (int i = 0; i < PISOS; i++)
	{
		printf("Piso: %d\n", i);
		recorrer(pca[i]);
		
	}
	
	//usleep(5000000);
	//pthread_kill(sched_t , SIGUSR1);


	pthread_join (elevad_t, NULL);
	pthread_join (perso_t[0], NULL);
	
	
	
	
	

	exit(EXIT_SUCCESS);
}

void
init (perso_ts perso[],perso_ts *ptper[],perso_ts **pcac[], perso_ts **pca[], pthread_mutex_t p_mutex[], pthread_cond_t p_cond[], int cond[], pthread_t sched_t)
{

		
	for (int i = 0; i < PERSONS; i++)
	{
	 
	 int r = rand()%PISOS;
	 int s = rand()%PISOS;
	
		perso[i].id = i;
		perso[i].p_act = r;
		perso[i].p_des = r;		
		perso[i].estado = PENSANDO ;
		perso[i].remTime = s;
		perso[i].pcac = pcac[r];
		perso[i].pca = pca[r];
		perso[i].p_mutex = p_mutex;
		perso[i].p_cond = p_cond;
		perso[i].cond = cond;
		perso[i].sched = sched_t;

		cond[i] = FALSE;
		
		
		insertar_final(ptper[i] , pca[r]);
		
		p_mutex[i] = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
		p_cond[i] = (pthread_cond_t)  PTHREAD_COND_INITIALIZER;
		
		

	}
}
