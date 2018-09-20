/* --- Arquivo : tarefa1.c --- */

/* --- inicializacao () --- */
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
typedef struct {pthread_mutex_t sem; int ativado;} Event;
#define Semaph sem_t
#include "type_tarefa1.h"  /* typedef's */
#include "vgp_tarefa1.h"   /* global privada*/
#include "vsl_tarefa1.h"   /* shared local  */
#include "partask_tarefa1.h"
#define _MAX_THREADS_ 100
#define get_mi_id() get_mi_id(_cpar_id_thread_)
pthread_t **_cpar_tid_;
int *_cpar_task_nthreads_;
extern int *_cpar_sec_parbegin_ ;
extern int *_cpar_count_bar_ ;
extern int *_cpar_count_end_bar_ ;
extern int *_cpar_end_barrier_;
int _cpar_id_task_;
extern int _cpar_num_tasks_;

extern int *_cpar_task_wait_flag_;

extern pthread_mutex_t *_cpar_create_task_flag_;

extern pthread_mutex_t _cpar_mutex_create_thread_ ;

extern pthread_mutex_t *_cpar_mutex_task_flag_ ;

extern pthread_mutex_t *_cpar_mutex_parbegin_ ;

extern pthread_mutex_t *_cpar_mutex_ ;

extern pthread_mutex_t *_cpar_mutex2_ ;

extern pthread_mutex_t *_cpar_mutex3_ ;

extern pthread_mutex_t *_cpar_mutex_bar_ ;

gl_priv *glbpriv;

extern int id_thread_global_next;

typedef struct {unsigned long int tid;int id_thread;struct type_next_id_thread *next;} type_next_id_thread;

typedef struct {unsigned long int tid;int id_thread;type_next_id_thread *next_id_thread;}type_list_id_thread;

extern type_list_id_thread list_thread[1000];

#include "cob_tarefa1.h"
#include <stdio.h>
void tarefa1()
{

int _id_thread_=get_id_thread_gl();

   printf("Tarefa1\n");
}

void tarefa2()
{

int _id_thread_=get_id_thread_gl();

   printf("Tarefa2\n");
}

void tarefa3()
{

int _id_thread_=get_id_thread_gl();

   printf("Tarefa3\n");
}

void tarefa4()
{

int _id_thread_=get_id_thread_gl();

   printf("Tarefa4\n");
}

void tarefa5()
{

int _id_thread_=get_id_thread_gl();

   printf("Tarefa5\n");
}

void tarefa6()
{

int _id_thread_=get_id_thread_gl();

   printf("Tarefa6\n");
}

int main()
{

int _id_thread_,_i_;

int _cpar_id_thread_;
for (_i_=0;_i_<1000;_i_++)

   list_thread[_i_].id_thread = -1;

insert_id_thread();

_id_thread_=get_id_thread_gl();

  _cpar_num_tasks_=0;

  glbpriv=calloc(_MAX_THREADS_,sizeof(gl_priv));

  initial_main(_cpar_num_tasks_);


   printf("Inicio\n");
    
pthread_t  _cpar_tid_1;

pthread_mutex_lock(&_cpar_mutex_create_thread_);
pthread_create(&_cpar_tid_1,NULL,ROT1,(void *) NULL);

pthread_mutex_unlock(&_cpar_mutex_create_thread_);

pthread_t  _cpar_tid_4;
pthread_create(&_cpar_tid_4,NULL,ROT4,(void *) NULL);

pthread_join(_cpar_tid_1,NULL);

pthread_join(_cpar_tid_4,NULL);

    wait_all();
    
pthread_t  _cpar_tid_7;

pthread_mutex_lock(&_cpar_mutex_create_thread_);
pthread_create(&_cpar_tid_7,NULL,ROT7,(void *) NULL);

pthread_mutex_unlock(&_cpar_mutex_create_thread_);

pthread_t  _cpar_tid_8;
pthread_create(&_cpar_tid_8,NULL,ROT8,(void *) NULL);

pthread_join(_cpar_tid_7,NULL);

pthread_join(_cpar_tid_8,NULL);

    return 0;
   wait_all();      /* --- rs307()  */
}

#include "cob_tarefa1"
