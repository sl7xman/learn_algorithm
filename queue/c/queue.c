#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

typedef struct queue_s {
    int siz;
    int inpos;
    int outpos;
    int* q;    
}queue_t;

queue_t* create_queue( int siz ){
    queue_t* q = (queue_t*) malloc(sizeof(queue_t));
    q->siz = siz;
    q->inpos = 0;
    q->outpos = 0;
    q->q = (int*) malloc( sizeof(int) * siz );
    return q;
}

int adjust_queue(queue_t* q){
    if ( q->outpos == 0 ){
        return -1;    
    }    
    int i = 0;
    int j = 0;
    for ( j = q->outpos; j < q->inpos; j++){
        q->q[i++]= q->q[j];    
    } 
    q->inpos -=q->outpos;
    q->outpos =0;
}

int get_size(queue_t* q) {
    return q->inpos + 1;
}

int isfull(queue_t* q) {
    if( (q->inpos+1)%q->siz == q->outpos ) {
        return 1;    
    }
    /*
    if( q->inpos == q->siz-1 ) {
        return 1;    
    }
    */
    return 0;
}

int isempty(queue_t* q) {
    return q->inpos == q->outpos;    
}

int enqueue(int n, queue_t* q){
    pthread_mutex_lock(&mtx);
    if( isfull(q) ){
//        printf("queue is full\n");
        pthread_mutex_unlock(&mtx);
        return -1;    
        /*
        if ( adjust_queue(q) == -1 ){
            printf("queue is full\n");
            pthread_mutex_unlock(&mtx);
            return -1;    
        }
        */
    }

    printf("inpos=%d outpos=%d\n", q->inpos, q->outpos);

    q->q[q->inpos] = n;
    q->inpos = (q->inpos+1)%q->siz;
    pthread_mutex_unlock(&mtx);
}

int dequeue(queue_t* q){
    pthread_mutex_lock(&mtx);
    if( isempty(q) ){
        printf("queue is empty\n");
        pthread_mutex_unlock(&mtx);
        return -1;
    }
    
    printf("outpos=%d inpos=%d\n", q->outpos, q->inpos);
    int res = q->q[q->outpos];
    q->outpos = (q->outpos+1)%q->siz;
    pthread_mutex_unlock(&mtx);
    return res;
}

void freeall(queue_t* q) {
    free(q->q);
    free(q);
}

void* inq_thread(void* args) {
    queue_t* inq = (queue_t*) args;
    int i = 0;
    while(1) {
        enqueue(i++, inq);
        usleep(100*6);    
    }    
}

void* outq_thread(void* args) {
    queue_t* outq = (queue_t*) args;    
    while(1){
        printf("dequeue:%d\n",dequeue(outq)); 
        sleep(1);   
    }
}

int main() {
    queue_t* q = create_queue(4);

    pthread_t p,c;
    pthread_create(&p, NULL, inq_thread, q);
    pthread_create(&c, NULL, outq_thread, q);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
    freeall(q);    
    return 0;    
}
