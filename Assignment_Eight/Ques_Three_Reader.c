#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer { 
	long mesg_type;
	char mesg_text[100];
} message;

int main(){

	key_t key;
	int msgid;

	key = ftok("progfile", 65); // ftok to generate unique key

	msgid = msgget(key, 0666 | IPC_CREAT); // msgget creates a message queue and returns an identifier

	msgrcv(msgid, &message, sizeof(message), 1, 0); // msgrcv to receive message

	printf("Data Received is: %s \n", message.mesg_text); // Display the Message

	msgctl(msgid, IPC_RMID, NULL); // To Destroy the Message Queue

	return 0;

}
