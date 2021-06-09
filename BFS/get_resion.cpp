#include <iostream>
#include <queue>
using namespace std;

int MAP[100][100];
bool VISIT[100][100];
priority_queue<int, vector<int>, greater<int> > ANS;
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
int M, N, K;

void get_group()
{
    int ans = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!VISIT[i][j] && !MAP[i][j])
            {
                ans = 0;
                queue<pair<int, int> > CHECK;

                CHECK.push(make_pair(i, j));
                VISIT[i][j] = true;
                while (CHECK.size())
                {
                    int r = CHECK.front().first;
                    int c = CHECK.front().second;

                    ans++;
                    CHECK.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int n_r = DR[i] + r;
                        int n_c = DC[i] + c;

                        if (n_r >= 0 && n_r < M && n_c >= 0 && n_c < N && 
                        !MAP[n_r][n_c] && !VISIT[n_r][n_c])
                        {
                            VISIT[n_r][n_c] = true;
                            CHECK.push(make_pair(n_r, n_c));
                        }
                    }
                }
                ANS.push(ans);
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N >> K;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MAP[i][j] = 0;
            VISIT[i][j] = false;
        }
    }
    for (int i = 0; i < K; i++)
    {
        int l_x, l_y, r_x, r_y;

        cin >> l_x >> l_y >> r_x >> r_y;
        for (int c = 0; c < r_x - l_x; c++)
        {
            for (int r = 0; r < r_y - l_y; r++)
                MAP[l_y + r][l_x + c] = 1;
        }
    }
    get_group();
    cout << ANS.size() << endl;
    while (ANS.size())
    {
        cout << ANS.top() << " ";
        ANS.pop();
    }
    return (0);
}