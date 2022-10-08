#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define THREADS 5

typedef struct
{
    int* arr;
    int tid;
} paramListType;

void* threadSum(void* p){
    paramListType* ptr = (paramListType*)p;
    int n = ptr->tid;
    int end = (ptr->tid+1)*(SIZE/THREADS);
    int start= end-(SIZE/THREADS);
    
    int* thread_sum = (int*) calloc(1, sizeof(int));
    
    
    for (int i = start; i < end; i++) {
        thread_sum[0] += ptr->arr[i];
    }
 
    // printf("\nThread id: %i\nSum: %i\n\n", ptr->tid, thread_sum[0]);
    pthread_exit(thread_sum);
}

int main()
{
    int check = 0;
    pthread_t threads[THREADS];
    int* arr = (int*) calloc(SIZE, sizeof(int));
    
    srand(time(0));
    // creating random array number list
    for(int i = 0;i < SIZE; i++) {
       arr[i] = rand()%100 + 1;
       check += arr[i];
    }
    
    // printing array list
    for(int i = 0;i < SIZE; i++) {
       printf("%d ", arr[i]);
    }


    // Declare arguments for threads:
    paramListType thread_params[THREADS];
    for(int i=0;i<THREADS;i++){
        thread_params[i].tid = i;
        thread_params[i].arr = arr;
    }
    
    // Declare thread IDs:
    pthread_t tids[THREADS];
    
    // create threads:
    for(int i=0;i<THREADS;i++){
        pthread_create(&tids[i], NULL, threadSum, &thread_params[i]);
    }
    
    // sum array of THREADS size to keep up the threads 
    int* sum[THREADS];
    
    // joining it to one.
    for(int i=0;i<THREADS;i++)
        pthread_join(tids[i], (void**)&sum[i]);
    
    int sumArr = 0;
    // sum up every thread's result
    for(int i=0;i<THREADS;i++){
        sumArr += *sum[i];
    }
    
    // if(check == sumArr)
    //     printf("Got it!!");
    
    
    printf("\n\nSum of whole array = %i\n", sumArr);

    return 0;
}

