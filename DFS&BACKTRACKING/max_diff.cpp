#include <iostream>
#include <algorithm>
using namespace std;

int N, RES = -1;
bool VISIT[8];
int NUM[8];

void dfs(int cnt, int bef, int sum)
{
    if (cnt == N)
    {
        if (RES < sum)
            RES = sum;
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        if (!VISIT[i])
        {
            VISIT[i] = true;
            if (cnt != 0)
                dfs(cnt + 1, i, sum + ((NUM[bef] > NUM[i]) ? NUM[bef] - NUM[i] : NUM[i] - NUM[bef]));
            else
                dfs(cnt + 1, i, sum);
            VISIT[i] = false;
        }
    }
}

int main()
{
    int cnt = 0;
    int ans = 0;

    // Init
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> NUM[i];
        VISIT[i] = 0;
    }
    sort(NUM, NUM + N);
    // Solve
    dfs(0, 0, 0);
    cout << RES;
    return (0);
}