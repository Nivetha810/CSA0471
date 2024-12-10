#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key = 1234;
    char *str;

    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    str = (char*) shmat(shmid, NULL, 0);

    // Write to shared memory
    printf("Write Data: ");
    fgets(str, SHM_SIZE, stdin);

    // Detach from shared memory
    shmdt(str);

    // Wait for a moment before reading
    sleep(5);

    // Read from shared memory
    str = (char*) shmat(shmid, NULL, 0);
    printf("Read Data: %s\n", str);

    // Detach and destroy the shared memory segment
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
