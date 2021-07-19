#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N, M;
int RANK[32001] = { 0, };

struct compare 
{
    bool operator()(int a, int b)
    {
        return RANK[a] > RANK[b];
    }
};

map<int, vector<int> > COMPARE;
priority_queue<int, vector<int>, compare> SORT;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int fir, sec;

        cin >> fir >> sec;
       
        COMPARE[fir].push_back(sec);
        if (RANK[fir] >= RANK[sec])
        {
            RANK[sec] = RANK[fir] + 1;
            for (int i = 0; i < COMPARE[sec].size(); i++)
                RANK[COMPARE[sec][i]] += 1;
        }
    }
    for (int i = 1; i <= N; i++)
        SORT.push(i);
    while (SORT.size())
    {
        cout << SORT.top() << " ";
        SORT.pop();
    }

    return (0);
}