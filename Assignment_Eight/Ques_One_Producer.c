#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(){
	
	const int SIZE = 4096; // Size of Shared Memory Object
	const char* name = "OS"; // Name of Shared Object
	
	// Strings Written to Shared Memory

	const char* message_0 = "Hello";
	const char* message_1 = "World";

	int shm_fd; // Shared Memory File Descriptor

	void* ptr; // Pointer To Shared Memory Object

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); // Shared Memory Object Created

	ftruncate(shm_fd, SIZE); // Size of Shared Memory Object Configured

	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); // Memory is Mapped to Shared Object
	
	sprintf(ptr, "%s", message_0);
	ptr += strlen(message_0);
	sprintf(ptr, "%s", message_1);
	ptr += strlen(message_1);
	
	return 0;

}
