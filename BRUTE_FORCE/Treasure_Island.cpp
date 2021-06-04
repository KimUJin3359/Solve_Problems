#include <iostream>
#include <queue>
using namespace std;

int R, C, ANS = -1;
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
bool VISIT[50][50];
int MAP[50][50];
int COPY[50][50];

void solve(int i, int j)
{
    queue<pair<int, int> > FIND;
    FIND.push(make_pair(i, j));
    VISIT[i][j] = true;
    while (FIND.size())
    {
        int r = FIND.front().first, c = FIND.front().second;

        FIND.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int n_r = r + DR[dir], n_c = c + DC[dir];

            if (n_r >= 0 && n_r < R && n_c >= 0 && n_c < C && !VISIT[n_r][n_c] && 
            (COPY[n_r][n_c] == 1 || COPY[n_r][n_c] < COPY[r][c] + 1)
            && MAP[n_r][n_c] != 0)
            {
                VISIT[n_r][n_c] = true;
                COPY[n_r][n_c] = COPY[r][c] + 1;
                FIND.push(make_pair(n_r, n_c));
            }
        }
    }
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (COPY[r][c] > ANS)
                ANS = COPY[r][c];
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
        {
            char c;
            
            cin >> c;
            if (c == 'W')
                MAP[i][j] = 0;
            else if (c == 'L')
                MAP[i][j] = 1;
            
        }
    }
    // Solve
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (MAP[i][j] == 1)
            {
                for (int r = 0; r < R; r++)
                {
                    for (int c = 0; c < C; c++)
                    {
                        VISIT[r][c] = false;
                        COPY[r][c] = MAP[r][c];
                    }
                }
                solve(i, j);
            }
        }
    }
    cout << ANS - 1;
    return (0);
}