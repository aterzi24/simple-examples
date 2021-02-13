#include <iostream>
#include <fstream>
#include <pthread.h>

#define SIZE 1000
#define NUM_THREAD 10

using namespace std;

ifstream input;
ofstream output;

int matrice[2][SIZE][SIZE];
int result[SIZE][SIZE];

void write(int (*array)[SIZE])
{
    int i, j;

    for( i = 0 ; i < SIZE ; i++ )
    {
        for( j = 0 ; j < SIZE ; j++ )
            output << array[i][j] << ' ';
        output << '\n';
    }
}

void read(int n)
{
    int i, j;

    for( i = 0 ; i < SIZE ; i++ )
        for( j = 0 ; j < SIZE ; j++ )
            input >> matrice[n][i][j];
}

void *compute(void *p)
{
    int i, j, k, sum;

    int num = *(int *)p;
    int limit = SIZE / NUM_THREAD;
    num *= limit;

    for( i = num ; i < num+limit ; i++ )
        for( j = 0 ; j < SIZE ; j++ )
        {
            sum = 0;
            for( k = 0 ; k < SIZE ; k++ )
                sum += matrice[0][i][k] * matrice[1][k][j];
            result[i][j] = sum;
        }
    return 0;
}

int main()
{
    input.open("matrices.txt");
    output.open("result_multi.txt");

    read(0);
    read(1);

    int i;
    int numbers[NUM_THREAD];
    
    for( i = 0 ; i < NUM_THREAD ; i++ )
        numbers[i] = i;

    pthread_t tids[NUM_THREAD];

    for( i = 0 ; i < NUM_THREAD ; i++ )
        pthread_create(tids+i, NULL, compute, (void *)(numbers+i));

    for( int i = 0 ; i < NUM_THREAD ; i++ )
        pthread_join(tids[i], NULL);

    write(result);

    input.close();
    output.close();
    return 0;
}
