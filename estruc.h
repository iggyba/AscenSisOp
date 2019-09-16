#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define PERSONS 1

#define TRUE 1
#define FALSE 0

#define NADA 0
#define SUBIENDO 1
#define BAJANDO 2

#define PENSANDO 0
#define MOVIENDOSE 1

typedef struct
{
  int p_act;
  int p_des;
  int estado;
  pthread_mutex_t *p_mutex;
  pthread_cond_t *p_cond;
  int *cond;
} elevador_t;

typedef struct
{
  int id;
  int p_act;
  int p_des;  
  int estado;
  int remTime;
} perso_ts;



void init (perso_ts []);
void *elevFun (void *);
void *perFun (void *);
void *process_hnd (void *);
