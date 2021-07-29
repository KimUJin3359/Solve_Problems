#include <iostream>
using namespace std;

int N;
int MAP[14][14];
int RES;

void DFS(int r, int c)
{
    // ROW
    for (int i = 0; i < c; i++)
    {
        if (MAP[r][i])
            return;
    }
    // UPPER CROSS
    for (int i = 0; i < c; i++)
    {
        if (r - (c - i) < 0)
            continue;
        if (MAP[r - (c - i)][i])
            return;
    }
    // DOWN CROSS
    for (int i = 0; i < c; i++)
    {
        if (r + (c - i) >= N)
            continue;
        if (MAP[r + (c - i)][i])
            return;
    }
    // NEXT ONE
    if (c == N - 1)
    {
        RES++;
        return ;
    }
    else
    {
        MAP[r][c] = 1;
        for (int i = 0; i < N; i++)
            DFS(i, c + 1);
        MAP[r][c] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            MAP[i][j] = 0;
    }
    for (int i = 0; i < N; i++)
        DFS(i, 0);
    cout << RES;
    return (0);
}