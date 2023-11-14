#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){
	const int SIZE = 4096; // Size of Shared Memory Object

	const char* name = "OS"; // Name of Shared Memory Object

	int shm_fd; // Shared Memory File Descriptor
	
	void* ptr; // Pointer to Shared Memory Object

	shm_fd = shm_open(name, O_RDONLY, 0666); // Shared Memory Object Opened

	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); // Memory is Mapped to Shared Memory Object

	printf("%s", (char*)ptr); // Reading is Done from Shared Memory Object

	shm_unlink(name); // Shared Memory Object is removed

	return 0;

}
