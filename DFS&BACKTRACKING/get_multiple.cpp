#include <iostream>
#include <vector>
using namespace std;

bool VISIT[10];
int K, M, ANS;

void dfs(int cnt, int now, int res)
{
    if (cnt == K)
    {
        if (!(res % M))
            ANS++;
        return ;
    }
    for (int i = 1; i <= K; i++)
    {
        if (!VISIT[i])
        {
            VISIT[i] = true;
            dfs(cnt + 1, i, res * 10 + i);
            VISIT[i] = false;
        }
    }
}

int get_multiple(int k, int m)
{
    int answer = -1;
    
    K = k;
    M = m;
    ANS = 0;
    for (int i = 1; i <= k; i++)
        VISIT[i] = false;
    for (int i = 1; i <= k; i++)
    {
        VISIT[i] = true;
        dfs(1, i, i);
        VISIT[i] = false;
    }
    answer = ANS;
    return (answer);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << get_multiple(5, 3);
}