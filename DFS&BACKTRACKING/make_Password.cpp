#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
vector<char> INPUT;
vector<char> OUTPUT;

void dfs(int cnt, int now)
{
    if (cnt == L)
    {
        int moeum = 0, jaeum = 0;
        for (int i = 0; i < OUTPUT.size(); i++)
        {
            if (OUTPUT[i] == 'a' || OUTPUT[i] == 'e' || OUTPUT[i] == 'i' 
            || OUTPUT[i] == 'o' || OUTPUT[i] == 'u')
                moeum++;
            else
                jaeum++;
        }
        if (moeum >= 1 && jaeum >= 2)
        {
            for (int i = 0; i < OUTPUT.size(); i++)
                cout << OUTPUT[i];
            cout << endl;
        }
        return ;
    }
    for (int i = now + 1; i < C; i++)
    {
        OUTPUT.push_back(INPUT[i]);
        dfs(cnt + 1, i);
        OUTPUT.pop_back();
    }
}

int main()
{
    // Init
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        char c;

        cin >> c;
        INPUT.push_back(c);
    }
    sort(INPUT.begin(), INPUT.end());
    // Make Pair
    dfs(0, -1);
    return (0);
}