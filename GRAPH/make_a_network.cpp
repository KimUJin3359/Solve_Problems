#include <iostream>
#include <queue>
using namespace std;

int N, M;
int MAP[1001][1001];
int SET[1001];

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return (MAP[a.first][a.second] > MAP[b.first][b.second]);
    }
};

int get_parent(int n)
{
    if (SET[n] == -1)
        return (-1);
    if (SET[n] == n)
        return (n);
    return (get_parent(SET[n]));
}

priority_queue<pair<int, int>, vector<pair<int, int> >, compare> PQ;
int main()
{
    int cnt = 0;
    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
        SET[i] = -1;
    for (int i = 0; i < M; i++)
    {
        int node1, node2, cost;

        cin >> node1 >> node2 >> cost;
        if (node1 != node2)
        {
            MAP[node1][node2] = cost;
            MAP[node2][node1] = cost;
            PQ.push(make_pair(node1, node2));
        }
    }
    while (PQ.size())
    {
        if (cnt == N - 1)
            break;
        if (get_parent(PQ.top().first) == -1 ||
            get_parent(PQ.top().second) == -1 ||
            get_parent(PQ.top().first) != get_parent(PQ.top().second))
        {
            cnt++;
            res += MAP[PQ.top().first][PQ.top().second];
            if (SET[PQ.top().first] == -1) 
            {
                if (SET[PQ.top().second] == -1)
                {
                    SET[PQ.top().first] = PQ.top().first;
                    SET[PQ.top().second] = PQ.top().first;
                }
                else
                    SET[PQ.top().first] = get_parent(PQ.top().second);
            }
            else
            {
                if (SET[PQ.top().second] == -1)
                    SET[PQ.top().second] = get_parent(PQ.top().first);
                else
                    SET[get_parent(PQ.top().second)] = get_parent(PQ.top().first);
            }
        }
        PQ.pop();
    }
    cout << res;
    return (0);
}