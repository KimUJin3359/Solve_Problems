#include <iostream>
#include <vector>
using namespace std;

int N, K, RES = 987654321;
int INPUT[100];
vector<int> NUM;

void dfs(int cnt, int res)
{
    int len = NUM.size();
    int flag = 0;

    if (res >= RES)
        return ;
    if (cnt == K)
    {
        if (RES > res)
            RES = res;
        return ;
    }
    for (int i = 0; i < len; i++)
        if (NUM[i] == INPUT[cnt])
            flag = 1;
    if (flag)
        dfs(cnt + 1, res);
    else
    {
        if (len < N)
        {
            NUM.push_back(INPUT[cnt]);
            dfs(cnt + 1, res);
        }
        else
        {
            int tmp;

            for (int i = 0; i < len; i++)
            {
                tmp = NUM[i];
                NUM[i] = INPUT[cnt];
                dfs(cnt + 1, res + 1);
                NUM[i] = tmp;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < K; i++)
        cin >> INPUT[i];
    dfs(0, 0);
    cout << RES;
    return (0);
}