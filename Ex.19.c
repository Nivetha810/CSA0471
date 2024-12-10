#include <stdio.h>
 #include <pthread.h>

*threadFunction(void *arg) {
 
int i;
for (i = 0; i < 1000000; ++i) {	}
return NULL;
}


int main() {
 
pthread_mutex_init(&mutex, NULL); 
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, threadFunction, NULL); 
pthread_create(&thread2, NULL, threadFunction, NULL);
return 0;
}
