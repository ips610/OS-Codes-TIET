#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#define MSGSIZE 16

int VAR = 10;
sem_t semaphore;

int main(){
	char inbuf[MSGSIZE];
	int fd[2];
	sem_init(&semaphore, 0, 0);
	pipe(fd);
	pid_t pid = fork();
	if ( pid == -1 ){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if ( pid == 0 ){
	
		// Child Process

		sleep(2);
		VAR = VAR - 2;
		printf("Child Process: Shared Variable = %d \n", VAR);
		sem_post(&semaphore);
		write(fd[1],"1",2);

	}

	else {
		
		// Parent Process

		read(fd[0], inbuf, MSGSIZE);
		sem_init(&semaphore, 0, atoi(inbuf));
		sem_wait(&semaphore);
		VAR = VAR + 2;
		printf("Parent Process: Shared Variable = %d\n", VAR);

	}

	sem_destroy(&semaphore);
	return 0;
}

