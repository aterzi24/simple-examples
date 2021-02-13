#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define SIZE 1000

using namespace std;

ofstream myfile;

void write()
{
    int i, j;

    for( i = 0 ; i < SIZE ; i++ )
    {
        for( j = 0 ; j < SIZE ; j++ )
            myfile << rand() % 10 << ' ';
        myfile << '\n';
    }
}

int main()
{
    srand (time(NULL));

    myfile.open("matrices.txt");

    write();
    myfile << '\n';
    write();

    myfile.close();
    return 0;
}
