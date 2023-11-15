#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10

struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;

int main(){

	key_t key;
	int msgid;

	key = ftok("Progfile", 65); // ftok to generate unique key
	
	msgid = msgget(key, 0666 | IPC_CREAT); // msgget creates a message queue and return identifier

	message.mesg_type = 1;
	printf("Write Data: ");

	fgets(message.mesg_text,MAX,stdin);

	msgsnd(msgid, &message, sizeof(message), 0); // msgsnd to send the message
	
	printf("Data Send is: %s \n", message.mesg_text); // Display the Message

	return 0;
}
