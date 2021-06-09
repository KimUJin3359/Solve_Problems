#include <iostream>
#include <queue>
using namespace std;

int N;
int MAP[100][100];
int B_MAP[100][100];

bool VISIT[100][100];
bool B_VISIT[100][100];

int ANS;
int B_ANS;

int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };

int get_group(int map[100][100], bool visit[100][100])
{
    int res = 0;
    int num;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[i][j])
            {
                res++;
                num = map[i][j];
                queue<pair<int, int> > CHECK;

                CHECK.push(make_pair(i, j));
                visit[i][j] = true;
                while (CHECK.size())
                {
                    int r = CHECK.front().first;
                    int c = CHECK.front().second;

                    CHECK.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int n_r = DR[i] + r;
                        int n_c = DC[i] + c;

                        if (n_r >= 0 && n_r < N && n_c >= 0 && n_c < N && 
                        map[n_r][n_c] == num && !visit[n_r][n_c])
                        {
                            visit[n_r][n_c] = true;
                            CHECK.push(make_pair(n_r, n_c));
                        }
                    }
                }
            }
        }
    }
    return (res);
}

int main()
{
    char c;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> c;
            if (c == 'R')
            {
                MAP[i][j] = 0;
                B_MAP[i][j] = 0;
            }
            else if (c == 'G')
            {
                MAP[i][j] = 1;
                B_MAP[i][j] = 0;
            }
            else
            {
                MAP[i][j] = 2;
                B_MAP[i][j] = 1;
            }
            VISIT[i][j] = false;
            B_VISIT[i][j] = false;
        }
    }
    ANS = get_group(MAP, VISIT);
    B_ANS = get_group(B_MAP, B_VISIT);
    cout << ANS << " " << B_ANS;
    return (0);
}