#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>   

#define workTime 5
#define workersLimitNr 3
#define List_Size 10
#define NoOfworkers 4

struct dataBlock{
    struct node *root;
    int listSize;
    int forIndex;
};

struct node { // std linked list node
    int value;
    int worker;
    struct node *next;
};

int slots = 0; // only 3 threads are allowed to access the list
int availableCheck(){   // check if thread can acces the list
    if(slots < 3) return 0;
    else return -1;
}

pthread_mutex_t mutp = PTHREAD_MUTEX_INITIALIZER;   //condvar mutex
pthread_cond_t  condvar = PTHREAD_COND_INITIALIZER;   //condvar
pthread_t w_threads[NoOfworkers];

void * worker( void *data ){
    int j;
    struct dataBlock *inData = (struct dataBlock *) data;
    struct node *root = inData->root;
    int listSize =  inData->listSize;
    int forIndex = inData ->forIndex;
    free(data);
    printf( "*    Thread id: %lu    forID:  %d  workerNode: \n",pthread_self(),forIndex); 

    pthread_mutex_lock( &mutp );
    while(availableCheck() < 0){
        printf( " ^^^ List not available yet... \n" ); 
        pthread_cond_wait( &condvar, &mutp );
    } 
    struct node *it = root;

    printf( "_ _ _ _forID_ %d\n", forIndex );
    do{
        if(forIndex == it->worker){
            printf("valid for sqrt  forIndex %d == it->worker %d\n",forIndex, it->worker );
            if(it->value > 2){
                while(it->value != 1)
                it->value = sqrt(it->value);
                // it->value = it->value - 1;
            }
        }
        it = it->next;
        printf("->val: %d   \n", it->value);
    }while(it->next !=  NULL);

    pthread_cond_signal( &condvar ); // 
    pthread_mutex_unlock( &mutp ); 
    return NULL;
}

int main()
{    
    int i;
    struct node *root;
    struct node *iterator;  

//prepare list for task
    int listSize = List_Size;
    int nrWorkers = NoOfworkers;
    root =  (struct node*) malloc(sizeof(struct node));

    root->value = rand() % 100;
    root->worker = 0;
    iterator = root;

    for( i=1; i<listSize; i++ ){
        iterator->next =(struct node*)malloc(sizeof(struct node));
        iterator = iterator->next;
        iterator->value = rand() % 100;
        iterator->worker = i % nrWorkers;
        printf("node #%d worker: %d  value: %d\n", i, iterator->worker,iterator->value);
    }
    iterator->next = NULL;
    printf("? List got populated\n");

// Create all threads to parse the link list
    int ret;    
    printf("workersInput: %d\n",nrWorkers);
    pthread_mutex_init(&mutp,NULL);

  
   // pthread_t* w_threads = malloc(nrWorkers * sizeof(w_thread));


    for( i=0; i < nrWorkers; i++ ){         
        struct dataBlock *data = (struct dataBlock*)malloc(sizeof(struct dataBlock));
        data->root = root;
        data->listSize = listSize;
        data->forIndex = i;
        ret = pthread_create ( &w_threads[i], NULL, worker, (void *) data );
        if( ret ) {
            perror("Thread creation fail");
            exit(2);    
        }   
        printf("in for, ret= %d\n",ret);

    } 

    for ( i = 0; i < nrWorkers; i++){
        pthread_join(w_threads[i],NULL);
    }
    iterator = root;
    for ( i = 0; i < listSize; i++){
        printf("val: %d  worker: %d _  ", iterator->value, iterator->worker);
        iterator = iterator->next;
    }

    free(root);
    free(iterator);
    return 0;
}