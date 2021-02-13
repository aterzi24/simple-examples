#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>

#include "monitor.h"


#define WAIT 100000

class Barrier : public Monitor {
    Condition allhere;
    int nthreads;
    int count;

    void myprint()
    {
        printf("count: %d ", count);
        for(int i = 0;i < 100000;i++) ;
        printf("-------\n");
    }
public:
    Barrier(int n):allhere(this) { nthreads = n;}

    void wait()
    {
        __synchronized__ ; // this is a synchronized method
        printf("1. func\n");
        count++;
        myprint();

        if (count == nthreads) {
            allhere.notify();
            printf("let the games begin\n");
        } else {
            allhere.wait();
            // wake up another
            allhere.notify();
        }
    }

    void wait2()
    {
        __synchronized__ ; // this is a synchronized method
        printf("2. func\n");
        count++;
        myprint();

        if (count == nthreads) {
            allhere.notify();
            printf("let the games begin\n");
        } else {
            allhere.wait();
            // wake up another
            allhere.notify();
        }
    }
};

Barrier *barrier;


void *barriertest(void *p)
{
    int i;
    char *name = (char *) p;

    /* wait for a while */
    usleep((rand() % 15+1) * WAIT );
//    printf("%s ready for barrier\n", name);
    if(rand()%2)
        barrier->wait();
    else
        barrier->wait2();
    printf("%s starts\n", name);
    usleep(5*WAIT);
    return 0;

}



int main() {
    pthread_t ptr,ctr;
    const char *names[] = { "A", "B", "C", "D","E","F","G","H"};
    pthread_t tids[8];

    int i;

    int nthreads = sizeof(names)/sizeof(names[0]);

    srand(time(NULL));

    // shared barrier pointer
    barrier = new Barrier(nthreads);

    for (i = 0 ; i < nthreads; i++)
        pthread_create(tids+i, NULL, barriertest, (void *) names[i]);

    for (i = 0 ; i < nthreads; i++)
        pthread_join(tids[i], NULL);

    return 0;
}
