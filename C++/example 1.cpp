#include <iostream>
#include <cmath>
#include <cfloat>

#define MAX_DOUBLE DBL_MAX

using namespace std;

class Coord{
    public:
        int x,y,z;
        bool is_collected=0;
};

bool all(Coord *cor, int n)
{
    for (int i = 0; i < n; i++)
        if (!cor[i].is_collected)
            return 0;
    return 1;
}

double calc(Coord a, Coord b)
{
    int i,j,k;
    i = b.x - a.x;
    j = b.y - a.y;
    k = b.z - a.z;
    return sqrt(i*i + j*j + k*k);
}

void arrange(double *arr, Coord *cor, int last, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (cor[i].is_collected)
            arr[i] = MAX_DOUBLE;
        else
            arr[i] = calc(cor[last], cor[i]);
    }
}

int main()
{
    int n, m, i, last;
    double total_dist, min_dist;
    total_dist = 0;

    cin >>  n>> m;

    Coord *cor = new Coord [n];
    double *dist = new double [n];
    double *temp_dist = new double [n];

    for(i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        cor[i].x = a;
        cor[i].y = b;
        cor[i].z = c;

        dist[i] = sqrt(a*a + b*b + c*c);
        temp_dist[i] = dist[i];
    }

    while (1)
    {
        min_dist = MAX_DOUBLE;
        for (i = 0; i < n; i++)
            if (min_dist > temp_dist[i])
            {
                min_dist = temp_dist[i];
                last = i;
            }

        if (total_dist + min_dist + dist[last] > m)
            break;

        total_dist += min_dist;
        cor[last].is_collected = 1;

        if (all(cor, n))
        {
            cout << n;
            return 0;
        }

        arrange(temp_dist, cor, last, n);
    }

    last = 0;
    for (i = 0; i < n; i++)
        if (cor[i].is_collected)
            last++;
    cout << last;

    return 0;
}
