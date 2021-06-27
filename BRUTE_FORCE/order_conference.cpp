#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, RES = 0;
pair<int, int> ORDER[100000];

bool  cmp_s(pair<int, int> A, pair<int, int> B)
{
    return A.first < B.first;
}  
bool  cmp_e(pair<int, int> A, pair<int, int> B)
{
    return A.second < B.second;
}

int main()
{
    int idx = 0;
    int before_end = 0;
    int end_time = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, e;

        cin >> s >> e;
        ORDER[i].first = s;
        ORDER[i].second = e;
    }
    sort(ORDER, ORDER + N, cmp_e);
    while (idx < N)
    {
        int skip = 0;

        end_time = ORDER[idx].second;
        while (ORDER[idx + ++skip].second == end_time) {}
        sort(ORDER + idx, ORDER + idx + skip, cmp_s);
        for (int i = 0; i < skip; i++)
        {
            if (before_end <= ORDER[i + idx].first)
            {
                RES++;
                before_end = ORDER[i + idx].second;
            }
        }
        idx += skip;
    }
    cout << RES;
    return (0);
}