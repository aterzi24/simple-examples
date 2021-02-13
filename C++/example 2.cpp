#include <iostream>
#define NUM 1000000007

using namespace std;

int comb(int n, int k)
{
    int mini = (n / 2 >= k) ? k : (n - k);
    int mult = 1;
    int div = 1;
    for (int i = 0; i < mini; i++)
    {
        mult *= n - i;
        div *= i + 1;
    }
    return mult / div;
}

int func(int n, int k)
{
    if (k < 10)
        return comb(n + k - 1, k);
    if (9 * n < k)
        return 0;
    if (9 * n == k)
        return 1;
    if (9 * n == k + 1)
        return n;
    if (9 * n == k + 2)
        return (n * (n + 1)) / 2;

    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += func(n - 1, k - i) % NUM;
    return sum % NUM;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << func(n, k);
    return 0;
}
