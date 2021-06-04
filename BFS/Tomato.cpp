#include <iostream>
#include <queue>
using namespace std;

int M, N;
bool VISIT[1000][1000];
int MAP[1000][1000];
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
queue<pair<int, int> > ANS;
int RES = -1;

int main()
{
    // Init
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            VISIT[i][j] = 0;
            if (MAP[i][j] == 1)
            {
                ANS.push(make_pair(i, j));
                VISIT[i][j] = 1;
            }
        }
    }
    // Solve
    while (ANS.size())
    {
        int r = ANS.front().first, c = ANS.front().second;

        ANS.pop();
        for (int i = 0; i < 4; i++)
        {
            if (r + DR[i] >= 0 && r + DR[i] < N && c + DC[i] >= 0 && c + DC[i] < M && !VISIT[r + DR[i]][c + DC[i]] && MAP[r + DR[i]][c + DC[i]] != -1)
            {
                VISIT[r + DR[i]][c + DC[i]] = 1;
                ANS.push(make_pair(r + DR[i], c + DC[i]));
                MAP[r + DR[i]][c + DC[i]] = MAP[r][c] + 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (MAP[i][j] == 0)
            {
                cout << -1;
                return (0);
            }
            if (RES < MAP[i][j])
                RES = MAP[i][j];
        }
    }
    cout << RES - 1;
    return (0);
}
