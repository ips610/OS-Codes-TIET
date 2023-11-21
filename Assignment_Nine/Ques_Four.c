#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_Client 5

int account[9] = {550,450,300,700,500,600,400,800,350};
pthread_mutex_t lock;

// Thread Function to deposit

void* Deposit(void* arg){
    int* client_id = (int*)arg;
    int amount;
    int x;
    int k;

    k = rand() % (10);
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    pthread_mutex_lock(&lock);

    x = account[k];
    x = x+amount;
    // sleep(3);
    account[k]=x;
    pthread_mutex_unlock(&lock);
    printf("Client %d deposited: %d, Amount after deposit: %d\n", *client_id, amount, account[k]);

    pthread_exit(NULL);
}

void* Withdraw(void* arg){
    int* client_id = (int*)arg;
    int amount;
    int x;
    int k;

    k=rand() % (10);

    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    pthread_mutex_lock(&lock);

    x = account[k]; 
    x = x-amount;

    account[k] = x;
    pthread_mutex_unlock(&lock);

    printf("Client %d withdraw: %d, Amount after withdraw: %d\n", *client_id, amount, account[k]);

    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_Client];
    pthread_mutex_init(&lock, NULL);
    int client_ids[NUM_Client];

    for (int i = 0; i < NUM_Client; i++){
        client_ids[i] = i;
        
    }

    // Create threads to perform different tasks

    for (int i=0;i<NUM_Client;i++){
        if(i%2==0){
            pthread_create(&threads[i],NULL,Deposit,&client_ids[i]);
        }
        else{
            pthread_create(&threads[i],NULL,Withdraw,&client_ids[i]);
        }
    }

    // Main Thread waits for these threads to finish

    for (int i = 0;i<3;i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}