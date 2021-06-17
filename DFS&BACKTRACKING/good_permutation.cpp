#include <iostream>
#include <string>
using namespace std;

int N;
int FLAG = 0;

int  find_in(string str)
{
    for (int i = 2; i < N / 2; i++)
    {
        for (int j = 0; j <= N - (2 * i); j++)
        {
            if (str.substr(j, i) == str.substr(j + i, i))
                return (0);
        }
    }
    return (1);
}

void dfs(string ans)
{
    if (FLAG)
        return;
    if (ans.size() == N)
    {
        if (find_in(ans))
        {
            FLAG = 1;
            cout << ans;
        }
    }
    for (char c = '1'; c <= '3'; c++)
    {
        if (find_in(ans) && ans.size() >= 1 && ans[ans.size() - 1] != c)
        {
            ans.push_back(c);
            dfs(ans);
            ans.pop_back();
        }
    }
}

int main()
{
    string ans;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    dfs(ans);
}