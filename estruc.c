#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "estruc.h"

int
main()
{
	pthread_t elevad_t;
	pthread_t perso_t[PERSONS];
	
	perso_ts perso[PERSONS];
	
	perso_ts *ptper[PERSONS];
	
	ptper = &perso;
	
	//cabezas pisos
	perso_ts *cabp[PISOS];
	perso_ts **pca[PISOS];	
	cabp = NULL;	
	pca = &cabp;
	//cabezas colas
	perso_ts *cabc[PISOS];
	perso_ts **pcac[PISOS];	
	cabc = NULL;	
	pcac = &cabc;
	//cabeza elevador
	perso_ts *cabe;
	perso_ts **pcae;	
	cabp = NULL;	
	pcae = &cabe;
		
	
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
	
	
	pthread_create (&elevad_t, NULL, elevFun, (void *)(&elev));

	init(perso);
	

	for (int i = 0; i < PERSONS; i++){
		pthread_create ( &(perso_t[i]), NULL, perFun , (void *)(&perso[i]));
		usleep(100000);
		}


	pthread_join (elevad_t, NULL);
	
	

	exit(EXIT_SUCCESS);
}

void
init (perso_ts perso[])
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

		

	}
}
