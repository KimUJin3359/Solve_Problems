#include <iostream>
using namespace std;

int N, INPUT;
int MAP[101][101];
bool VISIT[101];
int RES = 0;

void dfs(int cnt, int res)
{
    RES++;
    for (int i = 1; i <= N; i++)
    {
        if (MAP[cnt][i] && !VISIT[i])
        {
            VISIT[i] = true;
            dfs(i, res + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> INPUT;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            MAP[i][j] = 0;
        VISIT[i] = false;
    }
    for (int i = 0; i < INPUT; i++)
    {
        int com1, com2;

        cin >> com1 >> com2;
        MAP[com1][com2] = 1;
        MAP[com2][com1] = 1;
    }
    VISIT[1] = true;
    dfs(1, 0);
    cout << RES - 1 << endl;
    return (0);
}