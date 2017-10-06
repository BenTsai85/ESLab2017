#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
/* prototype for thread routine */
void print_message_function(void *ptr);
/* struct to hold data to be passed to a thread
this shows how multiple data items can be passed to a thread */
typedef struct str_thdata {
  int thread_no;
  char message[ 100 ];
} thdata;
pthread_t tid;

int main() {
  pthread_t thread1, thread2;
  thdata data1, data2;        /* structs to be passed to threads */
  /* initialize data to pass to thread 1 */
  data1.thread_no = 1;
  strcpy(data1.message, "Hello!");
  /* initialize data to pass to thread 2 */
  data2.thread_no = 2;
  strcpy(data2.message, "Hi!");
  /* create threads 1 and 2 */
  pthread_create(&thread1, NULL, (void*) &print_message_function, (void*) &data1);
  tid = thread1;
  pthread_create(&thread2, NULL, (void*) &print_message_function, (void*) &data2);
  tid = thread2;
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  exit(0);
}

/**
* print_message_function is used as the start routine for the threads used
* it accepts a void pointer
**/
void print_message_function(void* ptr) {
  thdata* data;
  data = (thdata*) ptr;
  /* do the work */
  printf("Thread %d (thread_id: %lu) says %s \n", data -> thread_no, tid, data -> message);
  printf("PID: %u\n", getpid());
  sleep(30);
  pthread_exit(0);
}