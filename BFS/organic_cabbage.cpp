#include <iostream>
#include <queue>
using namespace std;

int MAP[50][50];
bool VISIT[50][50];
int T, M, N, K;

int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };

void get_group()
{
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!VISIT[i][j] && MAP[i][j])
            {
                queue<pair<int, int> > CHECK;

                ans++;
                CHECK.push(make_pair(i, j));
                VISIT[i][j] = true;
                while (CHECK.size())
                {
                    int r = CHECK.front().first;
                    int c = CHECK.front().second;

                    CHECK.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int n_r = DR[i] + r;
                        int n_c = DC[i] + c;

                        if (n_r >= 0 && n_r < N && n_c >= 0 && n_c < M && 
                        MAP[n_r][n_c] && !VISIT[n_r][n_c])
                        {
                            VISIT[n_r][n_c] = true;
                            CHECK.push(make_pair(n_r, n_c));
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int C = 0; C < T; C++)
    {
        cin >> M >> N >> K;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                MAP[i][j] = 0;
                VISIT[i][j] = false;
            }
        }
        for (int i = 0; i < K; i++)
        {
            int r, c;
            
            cin >> c >> r;
            MAP[r][c] = 1;
        }
        get_group();
    }
    return (0);
}