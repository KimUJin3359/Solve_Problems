#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int NUM[1000];
int RES = 987654321;

void find(int cnt, int num)
{
    int idx = 0;

    if (RES < num)
        return;
    if (cnt >= N)
    {
        if (RES > num)
            RES = num;
        return;
    }
    while (cnt + ++idx < N && NUM[idx + cnt] <= (L - 1) + NUM[cnt]) {}
    find(cnt + idx, num + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        cin >> NUM[i];
    sort(NUM, NUM + N);
    find(0, 0);
    cout << RES;
    return (0);
}