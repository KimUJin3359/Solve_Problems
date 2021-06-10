#include <iostream>
#include <queue>
using namespace std;

int N, M;
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
bool VISITED[1001];
bool MAP[1001][1001];

int BFS()
{
    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        if (!VISITED[i])
        {
            queue<int> CONNECT;

            VISITED[i] = true;
            ans++;
            CONNECT.push(i);
            while (CONNECT.size())
            {
                int from = CONNECT.front();

                CONNECT.pop();
                for (int to = 1; to <= N; to++)
                {
                    if (!VISITED[to] && MAP[from][to])
                    {
                        VISITED[to] = true;
                        CONNECT.push(to);
                    }
                }
            }
        }
    }
    return (ans);
}

int main()
{
    int ans;

    // Init
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            MAP[i][j] = false;
        VISITED[i] = false;
    }
    for (int i = 0; i < M; i++)
    {
        int po1, po2;

        cin >> po1 >> po2;
        MAP[po1][po2] = true;
        MAP[po2][po1] = true;
    }
    // Solve
    ans = BFS();
    cout << ans;
    return (0);
}