#include <iostream>
using namespace std;

int N, M;
int MAP[20][20];
int MAX_SIZE;
int RES;

bool check_range(int r_i, int c_i)
{
    if ((r_i >= 0 && r_i < N) && (c_i >= 0 && c_i < N) && MAP[r_i][c_i] == 1)
        return (true);
    else
        return (false);
}

bool check_result(int sum, int req)
{
    if (sum * M >= req)
    {
        if (RES < sum)
        {
            RES = sum;
            return (true);
        }
    }
    return (false);
}

void check_profit(int size)
{
    int req = (size * size) + (size - 1) * (size - 1);
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            int sum = 0;

            for (int i = 0; i < 2 * size - 1; i++)
            {
                if (check_range(r, c - (size - 1) + i))
                    sum++;
            }
            for (int i = 1; i <= (size - 1); i++)
            {
                for (int j = 0; j < 2 * (size - i) - 1; j++)
                {
                    if (check_range(r - i, c - (size - (1 + i)) + j))
                        sum++;
                    if (check_range(r + i, c - (size - (1 + i)) + j))
                        sum++;
                }
            }
            check_result(sum, req);
        }
    }
}

int main()
{
    int T;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        RES = 1;
        cin >> N >> M;
        MAX_SIZE = N + (N / 2);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cin >> MAP[i][j];
        }
        for (int i = MAX_SIZE; i > 1; i--)
            check_profit(i);
        cout << "#" << C << " " << RES << endl;
    }

    return (0);
}