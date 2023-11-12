#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 4

int data[] = { 45, 56, 78, 32, 9, 5 };

// Thread Function To Find Sum Of Data

void* calculate_sum(void* arg){
	int* thread_id = (int*)arg;
	int sum = 0;
	int i;
	for ( i = 0; i < 6; i++ ){
		sum += data[i];
	}
	sleep(2);
	printf("Thread %d: Sum of data is %d \n", *thread_id, sum);
	pthread_exit(NULL);
}

// Thread Function To Find Max Value in Data

void* find_max(void* arg){
	int* thread_id = (int*)arg;
	int max = data[0];
	int i;
	for ( i = 1; i < 6; i++){
		if ( data[i] > max ){
			max = data[i];
		}
	}
	printf("Thread %d: Maximum Value in data is %d \n", *thread_id, max);
	pthread_exit(NULL);
}

// Thread Function To Find Min Value in Data

void* find_min(void* arg){
	int* thread_id = (int*)arg;
	int min = data[0];
	int i;
	for ( i = 1; i < 6; i++){
		if ( data[i] < min ){
			min = data[i];
		}
	}
	printf("Thread %d: Minimum Value in data is %d \n", *thread_id, min);
	pthread_exit(NULL);
}

int main(){

	pthread_t threads[NUM_THREADS];

	int thread_ids[NUM_THREADS];
	int i;

	for ( i = 0; i < NUM_THREADS; i++){
		thread_ids[i] = i;
	}
	
	// Creating Threads To Perform Different Tasks

	pthread_create(&threads[0], NULL, calculate_sum, &thread_ids[0]);
	pthread_create(&threads[1], NULL, find_max, &thread_ids[1]);
	pthread_create(&threads[2], NULL, find_min, &thread_ids[2]);

	for ( i = 0; i < 3; i++){
		pthread_join(threads[i], NULL);
	}

	return 0;

}

