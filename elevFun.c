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
	
	while(TRUE){
	
	printf("");
	usleep(100000);
	
	}

	return NULL;
}
