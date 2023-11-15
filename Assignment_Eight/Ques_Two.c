#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	int fd[2];
	int n;
	char buffer[100];
	pid_t p;
	pipe(fd); // To create a unidirectional pipe with two end fd[0] & fd[1]
	p = fork();

	if ( p > 0 ) {
		// parent
		printf("Parent Passing Value to Child \n");
		write(fd[1], "hello \n", 6); // fd[1] is the writing end of pipe
		sleep(3);

	}
	else {
		//child
		printf("Child Printing Received Value \n");
		n = read(fd[0], buffer, 100); //fd[0] is the reading end of pipe

		printf("%s", buffer);
		write(1,buffer,n);

	}

	return 0;

}
