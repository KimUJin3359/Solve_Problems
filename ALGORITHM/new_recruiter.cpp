#include <iostream>
#include <queue>
using namespace std;

int T, N;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return (a.second > b.second);
        else 
            return (a.first > b.first);
    }
};

priority_queue<pair<int, int>, vector<pair<int, int> >, compare> PQ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int C = 0; C < T; C++)
    {
        int res = 0;
        int min = 987654321;

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int fir, sec;

            cin >> fir >> sec;
            PQ.push(make_pair(fir, sec));
        }
        while (PQ.size())
        {
            if (PQ.top().second < min)
            {
                res++;
                min = PQ.top().second;
            }
            PQ.pop();
        }
        cout << res << endl;
    }
    return (0);
}