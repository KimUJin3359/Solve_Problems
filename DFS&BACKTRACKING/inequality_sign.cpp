#include <iostream>
#include <vector>
using namespace std;

int K, FLAG = 0;
char INPUT[9];
bool VISIT[10];
vector<int> ANS;

void dfs_MAX(int cnt)
{
    if (FLAG)
        return;
    if (cnt == K + 1)
    {
        int flag = 1;

        for (int i = 0; i < K; i++)
        {
            if (INPUT[i] == '<' && ANS[i] > ANS[i + 1])
                flag = 0;
            else if (INPUT[i] == '>' && ANS[i] < ANS[i + 1])
                flag = 0;
            if (!flag)
                break;
        }
        if (flag)
        {
            FLAG = flag;
            for (int i = 0; i < ANS.size(); i++)
                cout << ANS[i];
            cout << endl;
        }
        return ;
    }
    for (int i = 9; i >= 0; i--)
    {
        if (!VISIT[i])
        {
            ANS.push_back(i);
            VISIT[i] = true;
            dfs_MAX(cnt + 1);
            VISIT[i] = false;
            ANS.pop_back();
        }
    }
}

void dfs_MIN(int cnt)
{
    if (FLAG)
        return;
    if (cnt == K + 1)
    {
        int flag = 1;

        for (int i = 0; i < K; i++)
        {
            if (INPUT[i] == '<' && ANS[i] > ANS[i + 1])
                flag = 0;
            else if (INPUT[i] == '>' && ANS[i] < ANS[i + 1])
                flag = 0;
            if (!flag)
                break;
        }
        if (flag)
        {
            FLAG = flag;
            for (int i = 0; i < ANS.size(); i++)
                cout << ANS[i];
            cout << endl;
        }
        return ;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!VISIT[i])
        {
            ANS.push_back(i);
            VISIT[i] = true;
            dfs_MIN(cnt + 1);
            VISIT[i] = false;
            ANS.pop_back();
        }
    }
}

int main()
{
    // Init
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> K;
    for (int i = 0; i < K; i++)
        cin >> INPUT[i];
    for (int i = 0; i < 10; i++)
        VISIT[i] = 0;
    // Solve
    dfs_MAX(0);
    FLAG = 0;
    for (int i = 0; i < 10; i++)
        VISIT[i] = 0;
    while (ANS.size())
        ANS.pop_back();
    dfs_MIN(0);
    return (0);
}