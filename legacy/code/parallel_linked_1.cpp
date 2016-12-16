/*  for later */

#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void addToQ(int x, void *arg){
    printf("ADD ATTEMPT\n");
    struct shiftInfo *info = (struct shiftInfo *) arg;
    if (head -> ID == -1){ //No clients in line
        head -> ID = x;
        head -> next = dummy;
        tail = head;
    }

    else{ //clients already in line
        tail -> next = (NODE *)malloc(sizeof(NODE));
        tail = tail -> next;
        tail -> ID = x;
        tail -> next = dummy;
        info -> inQ++;
    }
    printf("ADD SUCCESS\n");
}
//Removes node closest to root
//Assumes: root != end
void removeFromQ(void *arg){
    printf("REMOVE ATTEMPT\n");
    struct shiftInfo *info = (struct shiftInfo *) arg;
    if (head -> next == dummy){ //only one element
        printf("SCENARIO 1\n");
        head -> ID = -1;
    }
    else{
        printf("SCENARIO 2\n");
        curr = head -> next;
        head = curr -> next;
        printf("Halfway\n");
        if ((head -> next == NULL) || (head -> next == dummy))
            tail = head;
    }
    info -> inQ--;
    printf("REMOVE SUCCESS\n");
}

/*  thread functions */

void *customerT(void *arg){
    int custID = 100;
    float newCust = 0;
    struct shiftInfo *info = (struct shiftInfo *) arg;
    float aRate = info -> arrivalRate;
    pthread_mutex_lock (&start); //Ensures Customers don't start before Tellers get to work
    pthread_mutex_unlock (&start);
    while(0<info -> simTime){
        newCust = (double)rand() / (double)RAND_MAX;
        if (newCust <= aRate){
            pthread_mutex_lock (&start);
            addToQ(custID,(void *)info);
            pthread_mutex_unlock (&start);
            custID++;
            }
        sleep(1/60);
    }
    pthread_exit(NULL);
 }


void *teller(void *arg){
    struct shiftInfo *info = (struct shiftInfo *) arg;
    int clientID;
    int clients = info -> inQ;
    pthread_mutex_lock (&start); //Ensures tellers dont start before customers arrive
    pthread_mutex_unlock (&start);
    while(0<info -> simTime){
        pthread_mutex_lock (&accessQ);
        clients = info -> inQ;
        if(head -> ID > 0){
            pthread_mutex_lock (&start);
            removeFromQ((void *)info);
            pthread_mutex_unlock (&start);
            printf("CLIENT OBTAINED\n");
        }
        printf("In Q %d\n", clients);
        pthread_mutex_unlock (&accessQ);
        sleep((info -> serviceTime)/60);
        }
    pthread_exit(NULL);
}

//Creates Customer thread, Teller threads, and timer thread
void *mainThread(void *info){
    head = (NODE *)malloc(sizeof(NODE));
    head -> ID = -1;
    head -> next = dummy;
    tail = head;
    int status;
    struct shiftInfo *I = info; 
    pthread_mutex_init(&start, NULL);
    pthread_mutex_init(&removeID, NULL);
    pthread_mutex_init(&accessQ, NULL);
    pthread_mutex_lock (&start);

    printf("Scheduling Tellers\n");
    pthread_t threads[(I -> tellers)];
    for (int i = 0; i < (I -> tellers); i++){
        I -> threadID = i;
        status = pthread_create(&threads[i], NULL, teller, (void *)info);
        if (status){
            printf("ERROR CODE: %d\n", status);
            exit(-1);
        }
    }

    printf("Preparing Customers\n");
    pthread_t customer;
    status = pthread_create(&customer, NULL, customerT, (void *)info);
        if (status){
            printf("ERROR CODE: %d\n", status);
            exit(-1);
        }

    printf("Making Timer\n");
    pthread_t time;
        status = pthread_create(&time, NULL, timer, (void *)info);
        if (status){
            printf("ERROR CODE: %d\n", status);
            exit(-1);
        }

    pthread_mutex_unlock (&start);
}

void main()
{

}