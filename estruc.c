#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "estruc.h"

int
main()
{
	pthread_t elevad_t;
	pthread_t perso_t[PERSONS];
	
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
		
	
	
	for (int i = 0; i < PISOS; i++)
	{
	cabp[i] = NULL;	
	pca[i]  = &(cabp[i]);
	cabc[i] = NULL;	
	pcac[i] = &(cabc[i]);
	
	}
	
	
	
	srand(time(NULL));
	

	int cond = FALSE;

	pthread_mutex_t p_mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t  p_cond  = PTHREAD_COND_INITIALIZER;
	
	//pthread_mutex_t p_mutexP[PERSONS];
	//pthread_cond_t  p_condP[PERSONS];
	
	
	//init elevator
	elevador_t elev = { .p_act = 1 , .p_des = 1 , 
	.estado = NADA , .p_cond = &p_cond , .p_mutex = &p_mutex 
	, .cond = &cond};
	
	
	
	
	init(perso , ptper , pca);
	usleep(1000000);
	
	for (int i = 0; i < PISOS; i++)
	{
		printf("Piso: %d\n", i);
		recorrer(pca[i],&perso[i]);
		
	}
	usleep(1000000);
	
	
	pthread_create (&elevad_t, NULL, elevFun, (void *)(&elev));

	

	for (int i = 0; i < PERSONS; i++){
		pthread_create ( &(perso_t[i]), NULL, perFun , (void *)(&perso[i]));
		usleep(100000);
		}


	pthread_join (elevad_t, NULL);
	pthread_join (perso_t[0], NULL);
	
	

	exit(EXIT_SUCCESS);
}

void
init (perso_ts perso[],perso_ts *ptper[],perso_ts **pca[])
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
		
		
		insertar_final(ptper[r] , pca[r]);
		printf("Persona: %d ira a: %d\n", i, r);
		

	}
}
