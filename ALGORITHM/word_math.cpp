#include <iostream>
#include <string>
#include <queue>
using namespace std;


int N;
string NUM[10];
int ALPHA[128] = { 0, };
priority_queue<int, vector<int>, less<int> > PRIOR;

int main()
{
    int res = 0;
    int max = 9;

    ios::sync_with_stdio(false);
    cin.tie(0);
    // INIT
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> NUM[i];
        for (int j = 0; j < NUM[i].size(); j++)
        {
            int num = 1;

            for (int k = 0; k < (NUM[i].size() - (j + 1)); k++)
                num *= 10;
            ALPHA[(int)NUM[i][j]] += num;
        }
    }
    for (int i = (int)'A'; i <= (int)'Z'; i++)
    {
        if (ALPHA[i])
            PRIOR.push(ALPHA[i]);
    }
    while (PRIOR.size())
    {
        int num = PRIOR.top();

        PRIOR.pop();
        res += num * max;
        max--;
    }
    cout << res;
    return (0);
}