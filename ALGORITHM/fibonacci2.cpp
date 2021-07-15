#include <iostream>
using namespace std;

int N;
long long FIBO[91];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    FIBO[0] = 0;
    FIBO[1] = 1;
    for (int i = 2; i <= N; i++)
        FIBO[i] = FIBO[i - 1] + FIBO[i - 2];
    cout << FIBO[N];
    return (0);
}