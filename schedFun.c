#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include "estruc.h"



void sig_handler(int signo)
{
    if (signo == SIGUSR1){
        printf("RECEIVED SIGUSR1\n");
        
        
        
        }
   
}

void *
schedFun (void * arg)
{
	sched_ts *sched = (sched_ts *)arg;
			
	for(;;){
		
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGUSR1\n");
	
	/*pthread_mutex_lock(sched->p_mutex);
   	*(sched->cond) = TRUE;
        pthread_cond_wait(&cond, &mutex);
        pthread_cond_wait(&(sched->p_cond)[control->id], &(control->p_mutex)[control->id]);
   
    	pthread_mutex_unlock(sched->p_mutex);*/
	idthread = pthread_self(); 
	//printf("");
	usleep(1000000);
	}

	return NULL;
}
