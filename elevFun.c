#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "estruc.h"

void *
elevFun (void * arg)
{
	elevador_t *elev = (elevador_t *)arg;
	
	printf("Elevador creado\n");
	printf("Elevador en: %d\n" , elev->p_act);
	printf("Elevador ira a: %d\n" , elev->p_des);
	
	pthread_mutex_lock(elev->p_mutex);

	while (!*(elev->cond))
	{
		printf ("Thread %d sleeping.\n", elev->id);
		pthread_cond_wait(elev->p_cond, elev->p_mutex);
	}

	printf ("Thread %d working.\n", elev->id);

	pthread_mutex_unlock(elev->p_mutex);

	
	/*for(;;){	
	printf("");
	usleep(1000000);}*/

	return NULL;
}
