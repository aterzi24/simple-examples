#include <iostream>
#include <fstream>

#define SIZE 1000

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

void compute()
{
    int i, j, k, sum;
    for( i = 0 ; i < SIZE ; i++ )
        for( j = 0 ; j < SIZE ; j++ )
        {
            sum = 0;
            for( k = 0 ; k < SIZE ; k++ )
                sum += matrice[0][i][k] * matrice[1][k][j];
            result[i][j] = sum;
        }
}

int main()
{
    input.open("matrices.txt");
    output.open("result_one.txt");

    read(0);
    read(1);

    compute();

    write(result);

    input.close();
    output.close();
    return 0;
}
