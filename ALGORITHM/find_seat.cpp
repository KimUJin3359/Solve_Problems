#include <iostream>
using namespace std;

int N;
bool MAP[100][100];

int main()
{
    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;

            cin >> c;
            if (c == '.')
                MAP[i][j] = true;
            else if (c == 'X')
                MAP[i][j] = false;
        }
    }
    // row
    for (int i = 0; i < N; i++)
    {
        int flag = 0;

        for (int j = 0; j < N; j++)
        {
            if (flag == 1 && MAP[i][j])
            {
                res++;
                flag = 2;
            }
            if (MAP[i][j])
                flag = (flag == 2) ? 2 : 1;
            else
                flag = 0;
        }
    }
    cout << res << " ";
    // col
    res = 0;
    for (int i = 0; i < N; i++)
    {
        int flag = 0;

        for (int j = 0; j < N; j++)
        {
            if (flag == 1 && MAP[j][i])
            {
                res++;
                flag = 2;
            }
            if (MAP[j][i])
                flag = (flag == 2) ? 2 : 1;
            else
                flag = 0;
        }
    }
    cout << res;
    return (0);
}