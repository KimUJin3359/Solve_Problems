#include <iostream>
using namespace std;

int N, K, T;

int main()
{
    int res = 1;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    if (K == 0 || K == N)
    {
        cout << 1;
        return (0);
    }
    T = N - K;
    if (T > K)
    {
        int tmp = T;

        T = K;
        K = tmp;
    }
    for (int i = K + 1; i <= N; i++)
        res *= i;
    for (int i = 1; i <= T; i++)
        res /= i;
    cout << res;
    return (0);
}