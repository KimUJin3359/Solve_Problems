#include <iostream>
using namespace std;

int R, C, MAX = 0;
char MAP[20][20];
bool VISIT[128];
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };

void dfs(int cnt, int r, int c)
{
    if (cnt > MAX)
        MAX = cnt;
    for (int i = 0; i < 4; i++)
    {
        int n_r = r + DR[i];
        int n_c = c + DC[i];

        if (n_r >= 0 && n_r < R && n_c >= 0 && n_c < C && !VISIT[MAP[n_r][n_c]])
        {
            VISIT[MAP[n_r][n_c]] = true;
            dfs(cnt + 1, n_r, n_c);
            VISIT[MAP[n_r][n_c]] = false;
        }
    }
}

int main()
{
    // Init
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cin >> MAP[i][j];
    }
    for (int i = 0; i < 128; i++)
        VISIT[i] = false;
    // Solve
    VISIT[MAP[0][0]] = true;
    dfs(1, 0, 0);
    cout << MAX;
    return (0);
}