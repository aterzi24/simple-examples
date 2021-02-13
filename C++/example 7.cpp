#include <iostream>
#include <vector>

#define NUM 501

using namespace std;

vector<int> vc;

int func(int startp, int endp)
{
    if (endp == startp + 1)
        return 0;

    int i, cl[NUM]{0}, max_num, max_cl=0, sum, j;
    for (i = startp; i < endp; i++)
        ++cl[vc[(long unsigned)i]];

    max_num = -1;

    if (vc[startp] == vc[endp-1])
        max_cl = vc[startp];
    else
    {
        for (i = 0; i < NUM; i++)
            if (max_num < cl[i])
            {
                max_num = cl[i];
                max_cl = i;
            }
    }

    sum = 0;
    i = startp;
    while (i < endp)
    {
        if (vc[(long unsigned)i] != max_cl)
        {
            j = i + 1;
            while (j < endp && vc[(long unsigned)j] != max_cl)
                ++j;
            sum += func(i, j) + 1;
            i = j;
        }
        ++i;
    }
    return sum;
}



int main()
{
    int i, n, tmp, cl[NUM]{0}, max_num, max_cl=0, j, sum;
    cin>>n;

    for( i = 0 ; i < n ; i++ )
    {
        cin>>tmp;
        ++cl[tmp];
        vc.push_back(tmp);
    }
    max_num = -1;

    if( vc[0] == vc[vc.size()-1] )
        max_cl = vc[0];

    else
    {
        for( i = 0 ; i < NUM ; i++ )
            if(max_num < cl[i])
            {
                max_num = cl[i];
                max_cl = i;
            }
    }

    sum = 0;
    i = 0;
    while( i < (int)vc.size() )
    {
        if( vc[(long unsigned)i] != max_cl )
        {
            j = i + 1;
            while( j < (int)vc.size() && vc[(long unsigned)j] != max_cl )
                ++j;
            sum += func(i, j) + 1;
            i = j;
        }
        ++i;
    }
    cout<<sum;
}
