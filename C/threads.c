#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int cnt = 0;

void *up(void *ptr)
{
    char *message;
    message = (char *) ptr;
    cnt++;
    printf("%s cnt=%d\n", message, cnt);
     /* do whatever you want */
}

void *down(void *ptr)
{
    char *message;
    message = (char *) ptr;
    cnt--;
    printf("%s cnt=%d\n", message, cnt);
}

int main() {
    pthread_t thread1, thread2;
    char *msg1 = "Thread 1"; char *msg2 = "Thread 2";
    int  iret1, iret2;

    /* Create independent threads each of which will execute function */
    iret1 = pthread_create( &thread1, NULL, up, (void*) msg1);
    iret2 = pthread_create( &thread2, NULL, down, (void*) msg2);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */
    pthread_join( thread1, NULL); pthread_join( thread2, NULL);
    printf("Thread 1 returns: %d, Thread 2 returns: %d\n",iret1,iret2);
    exit(0);
}
