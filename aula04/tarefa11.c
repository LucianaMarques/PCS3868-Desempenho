/* --- Arquivo : tarefa11.c --- */

/* --- inicializacao () --- */
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
typedef struct {pthread_mutex_t sem; int ativado;} Event;
#define Semaph sem_t
#include "type_tarefa11.h"  /* typedef's */
#include "vgp_tarefa11.h"   /* global privada*/
#include "vsl_tarefa11.h"   /* shared local  */
#include "partask_tarefa11.h"
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

#include "cob_tarefa11.h"
#include <stdio.h>
void *tarefa1 (void * arg);   /* --- spec () */
void *tarefa2 (void * arg);   /* --- spec () */
void *tarefa3 (void * arg);   /* --- spec () */
void *tarefa4 (void * arg);   /* --- spec () */
void *tarefa5 (void * arg);   /* --- spec () */
void *tarefa6 (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *tarefa1 (void * arg) 
{
   _cpar_arg_task_0_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=0;
   _cpar_arg_t_= (_cpar_arg_task_0_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   printf("Tarefa1\n");

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tarefa2 (void * arg) 
{
   _cpar_arg_task_1_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=1;
   _cpar_arg_t_= (_cpar_arg_task_1_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   printf("Tarefa2\n");

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tarefa3 (void * arg) 
{
   _cpar_arg_task_2_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=2;
   _cpar_arg_t_= (_cpar_arg_task_2_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   printf("Tarefa3\n");

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tarefa4 (void * arg) 
{
   _cpar_arg_task_3_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=3;
   _cpar_arg_t_= (_cpar_arg_task_3_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   printf("Tarefa4\n");

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tarefa5 (void * arg) 
{
   _cpar_arg_task_4_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=4;
   _cpar_arg_t_= (_cpar_arg_task_4_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   printf("Tarefa5\n");

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tarefa6 (void * arg) 
{
   _cpar_arg_task_5_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=5;
   _cpar_arg_t_= (_cpar_arg_task_5_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   printf("Tarefa6\n");

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

int main()
{

int _id_thread_,_i_;

int _cpar_id_thread_;
for (_i_=0;_i_<1000;_i_++)

   list_thread[_i_].id_thread = -1;

insert_id_thread();

_id_thread_=get_id_thread_gl();

  _cpar_arg_task_0_ *_cpar_arg_0_;

  _cpar_arg_task_1_ *_cpar_arg_1_;

  _cpar_arg_task_2_ *_cpar_arg_2_;

  _cpar_arg_task_3_ *_cpar_arg_3_;

  _cpar_arg_task_4_ *_cpar_arg_4_;

  _cpar_arg_task_5_ *_cpar_arg_5_;

  _cpar_num_tasks_=6;

  glbpriv=calloc(_MAX_THREADS_,sizeof(gl_priv));

  initial_main(_cpar_num_tasks_);


   printf("Inicio\n");
    // 
   init_create_task(0,1);

   sh_0=(shared_local_0 *) calloc(1,sizeof(shared_local_0));

   _cpar_arg_0_=(_cpar_arg_task_0_ *) calloc(1,sizeof(_cpar_arg_task_0_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_0_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_0_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[0][_cpar_id_thread_],NULL,tarefa1,(void *)&_cpar_arg_0_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[0]);

      _cpar_task_wait_flag_[0]=0;

    // 
   init_create_task(1,1);

   sh_1=(shared_local_1 *) calloc(1,sizeof(shared_local_1));

   _cpar_arg_1_=(_cpar_arg_task_1_ *) calloc(1,sizeof(_cpar_arg_task_1_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_1_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_1_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[1][_cpar_id_thread_],NULL,tarefa2,(void *)&_cpar_arg_1_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[1]);

      _cpar_task_wait_flag_[1]=0;

    // 
   init_create_task(2,1);

   sh_2=(shared_local_2 *) calloc(1,sizeof(shared_local_2));

   _cpar_arg_2_=(_cpar_arg_task_2_ *) calloc(1,sizeof(_cpar_arg_task_2_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_2_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_2_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[2][_cpar_id_thread_],NULL,tarefa3,(void *)&_cpar_arg_2_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[2]);

      _cpar_task_wait_flag_[2]=0;

    // 
   init_create_task(3,1);

   sh_3=(shared_local_3 *) calloc(1,sizeof(shared_local_3));

   _cpar_arg_3_=(_cpar_arg_task_3_ *) calloc(1,sizeof(_cpar_arg_task_3_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_3_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_3_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[3][_cpar_id_thread_],NULL,tarefa4,(void *)&_cpar_arg_3_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[3]);

      _cpar_task_wait_flag_[3]=0;

    // 
   init_create_task(4,1);

   sh_4=(shared_local_4 *) calloc(1,sizeof(shared_local_4));

   _cpar_arg_4_=(_cpar_arg_task_4_ *) calloc(1,sizeof(_cpar_arg_task_4_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_4_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_4_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[4][_cpar_id_thread_],NULL,tarefa5,(void *)&_cpar_arg_4_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[4]);

      _cpar_task_wait_flag_[4]=0;

    // 
   init_create_task(5,1);

   sh_5=(shared_local_5 *) calloc(1,sizeof(shared_local_5));

   _cpar_arg_5_=(_cpar_arg_task_5_ *) calloc(1,sizeof(_cpar_arg_task_5_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_5_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_5_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[5][_cpar_id_thread_],NULL,tarefa6,(void *)&_cpar_arg_5_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[5]);

      _cpar_task_wait_flag_[5]=0;

    
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

#include "cob_tarefa11"
