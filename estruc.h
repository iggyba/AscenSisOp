#define PERSONS 10
#define PISOS 5

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

typedef struct persona perso_ts;

struct persona
{
  int id;
  int p_act;
  int p_des;  
  int estado;
  int remTime;
  int cola;
  pthread_mutex_t *p_mutex;
  pthread_cond_t *p_cond;
  int *cond;
  perso_ts **pca;
  perso_ts **pcac;
  perso_ts *sig;
  
  pthread_t sched;
  
} ;

typedef struct
{  
  pthread_mutex_t *p_mutex;
  pthread_cond_t *p_cond;
  int *cond;
} sched_ts;

unsigned long idthread;

void init (perso_ts perso[],perso_ts *ptper[],perso_ts **pcac[],perso_ts **pca[],pthread_mutex_t p_mutex[], pthread_cond_t p_cond[], int cond[], pthread_t sched_t);
void *elevFun (void *);
void *perFun (void *);
void *schedFun (void *);
void *process_hnd (void *);
void insertar_final (perso_ts *perso, perso_ts **ptper);
void extraer_med(perso_ts **ptper, int cn);
void recorrer (perso_ts **cab );



