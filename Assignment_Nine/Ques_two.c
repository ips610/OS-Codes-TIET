#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Global Variable That is Gonna Shared Between Two Threads

int common_variable = 10;

sem_t semaphore;

void *Incre(void *arg){
	
	int thread_id = (*(int*) arg);

	// Semaphore Wait
	sem_wait(&semaphore);

	// Critical Section: Updating the common variable
	int i = common_variable;
	i += 1;
	

	common_variable = i;
	sleep(2);

	printf("Thread %d updated common_variable to %d \n", thread_id, common_variable);
	
	// Signal To Indicate that Critical Section is Finished
	
	sem_post(&semaphore);
	pthread_exit(NULL);

}
void *Decr(void *arg){
	
	int thread_id = (*(int*) arg);

	// Semaphore Wait
	sem_wait(&semaphore);

	// Critical Section: Updating the common variable
	int i = common_variable;
	i -= 1;
	
	sleep(2);

	common_variable = i;

	printf("Thread %d decremented common_variable to %d \n", thread_id, common_variable);
	
	// Signal To Indicate that Critical Section is Finished
	
	sem_post(&semaphore);
	pthread_exit(NULL);

}

int main(){

	// Semaphore Initialized with value of 1

	sem_init(&semaphore, 0, 1);
	pthread_t thread1, thread2;

	int thread_id1 = 1, thread_id2 = 2;

	// Creating Two Threads

	pthread_create(&thread1, NULL, Incre, &thread_id1);
	pthread_create(&thread2, NULL, Decr, &thread_id2);

	// Waiting for Threads to Finish

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	// Destroying Semaphore

	sem_destroy(&semaphore);
	printf("Final Value of common_variable is %d \n", common_variable);

	return 0;
}