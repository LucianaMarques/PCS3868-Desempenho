/* --- Arquivo : exercico2.c --- */

/* --- inicializacao () --- */
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
typedef struct {pthread_mutex_t sem; int ativado;} Event;
#define Semaph sem_t
#include "type_exercico2.h"  /* typedef's */
#include "vgp_exercico2.h"   /* global privada*/
#include "vsl_exercico2.h"   /* shared local  */
#include "partask_exercico2.h"
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

#include "cob_exercico2.h"
/* #define IMPRIME 1 */
/*multiplicacao de matrizes: outer-product*/
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "mede_time.h"
#include <unistd.h>
   int SIZE;

   int nprocs;

   double a[2000];

   double b[2000];

   double c[2000];

   double x[2000];

   double y[2000];

/*inicia matriz*/
void *init_matrix (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *init_matrix (void * arg) 
{
int i;

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
             };

      end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);

{
   int i_, n_;
   n_ = ((SIZE-1) - 0 + 1) / _cpar_numthreads_;
   if ((((SIZE-1) - 0 + 1) % _cpar_numthreads_) != 0)
      n_++;
   i_ = 0 + _cpar_id_thread_ * n_;

   for (i = i_; ((i < (i_ + n_)) && (i <= (SIZE-1))); i++) {
         a[i] = 0;
         b[i] = (double)0.0;
         c[i] = (double)0.0;
         x[i] = i;
         y[i] = i+1;


      }
}
     if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))  /* --- forall () */
  {

  
   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/*imprime matriz */
print_mat(a)
double a[2000];
{
int i;


int _id_thread_=get_id_thread_gl();

   for (i=0;i<10;i++){
         printf("%f ", a[i]);
      }
      puts("\n");
   }

/*imprime resultado*/
print_mats(a, b, c, x, y)
double a[2000], b[2000], c[2000], x[2000], y[2000];
{

int _id_thread_=get_id_thread_gl();

   puts ("Matriz A");
      print_mat (a);
      puts("...");

      puts ("Matriz B");
      print_mat (b);
      puts("...");

      puts ("Matriz C");
      print_mat (c);
      puts("...");

      puts ("Matriz X");
      print_mat (x);
      puts("...");

      puts ("Matriz Y");
      print_mat (y);
      puts("...");
   }

void *tar1 (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *tar1 (void * arg) 
{
int i;

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
             };

      end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);

{
   int i_, n_;
   n_ = ((SIZE-2) - 0 + 1) / _cpar_numthreads_;
   if ((((SIZE-2) - 0 + 1) % _cpar_numthreads_) != 0)
      n_++;
   i_ = 0 + _cpar_id_thread_ * n_;

   for (i = i_; ((i < (i_ + n_)) && (i <= (SIZE-2))); i++) {
    a[i] = x[i]*3.0;


}
}
     if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))  /* --- forall () */
  {

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *tar2 (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *tar2 (void * arg) 
{
int i;

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
   b[0]=1;
           };

      end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);

{
   int i_, n_;
   n_ = ((SIZE-1) - 1 + 1) / _cpar_numthreads_;
   if ((((SIZE-1) - 1 + 1) % _cpar_numthreads_) != 0)
      n_++;
   i_ = 1 + _cpar_id_thread_ * n_;

   for (i = i_; ((i < (i_ + n_)) && (i <= (SIZE-1))); i++) {
    b[i] = y[i] + a[i-1];
}
}
     if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))  /* --- forall () */
  {

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *tar3 (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *tar3 (void * arg) 
{
int i;

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
   c[0]=1;
           };

      end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);

{
   int i_, n_;
   n_ = ((SIZE-1) - 1 + 1) / _cpar_numthreads_;
   if ((((SIZE-1) - 1 + 1) % _cpar_numthreads_) != 0)
      n_++;
   i_ = 1 + _cpar_id_thread_ * n_;

   for (i = i_; ((i < (i_ + n_)) && (i <= (SIZE-1))); i++) {
    c[i] = a[i-1]*2;
}
}
     if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))  /* --- forall () */
  {

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

main(argc, argv)
int argc;
char **argv;
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

  _cpar_num_tasks_=4;

  glbpriv=calloc(_MAX_THREADS_,sizeof(gl_priv));

  initial_main(_cpar_num_tasks_);


   SIZE=2000;

  if (argc>1) {
    nprocs = atoi(argv[1]);
    printf("Usando %d processadores\n",nprocs);
  }
  else {
    printf ("Numero de processadores: ");
    scanf("%d",&nprocs);
  }

    
   init_create_task(0,nprocs);

   sh_0=(shared_local_0 *) calloc(1,sizeof(shared_local_0));

   _cpar_arg_0_=(_cpar_arg_task_0_ *) calloc(nprocs,sizeof(_cpar_arg_task_0_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<nprocs;_cpar_id_thread_++) {

      _cpar_arg_0_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_0_[_cpar_id_thread_].numthreads=nprocs;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[0][_cpar_id_thread_],NULL,init_matrix,(void *)&_cpar_arg_0_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[0]);

      _cpar_task_wait_flag_[0]=0;

  wait_all();
  TIMER_CLEAR;
  TIMER_START;

    
   init_create_task(1,nprocs);

   sh_1=(shared_local_1 *) calloc(1,sizeof(shared_local_1));

   _cpar_arg_1_=(_cpar_arg_task_1_ *) calloc(nprocs,sizeof(_cpar_arg_task_1_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<nprocs;_cpar_id_thread_++) {

      _cpar_arg_1_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_1_[_cpar_id_thread_].numthreads=nprocs;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[1][_cpar_id_thread_],NULL,tar1,(void *)&_cpar_arg_1_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[1]);

      _cpar_task_wait_flag_[1]=0;

  wait_all();
  
pthread_t  _cpar_tid_1;

pthread_mutex_lock(&_cpar_mutex_create_thread_);
pthread_create(&_cpar_tid_1,NULL,ROT1,(void *) NULL);

pthread_mutex_unlock(&_cpar_mutex_create_thread_);

pthread_t  _cpar_tid_2;
pthread_create(&_cpar_tid_2,NULL,ROT2,(void *) NULL);

pthread_join(_cpar_tid_1,NULL);

pthread_join(_cpar_tid_2,NULL);


  print_mats(a,b,c,x,y);

  TIMER_STOP;
  printf ("TEMPO [%d]: %12.7f\n",SIZE,TIMER_ELAPSED );
   wait_all();      /* --- rs307()  */
}

#include "cob_exercico2"
