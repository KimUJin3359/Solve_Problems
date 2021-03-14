#include <iostream>
using namespace std;

int **INPUT;
int DP[500];

int main()
{
    int size;
    int left, right;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> size;
    // make a triangle form
    INPUT = new int*[size];
    for (int i = 0; i < size; i++)
        INPUT[i] = new int[i + 1];
    // user inpt
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> INPUT[i][j];
            if (i == size - 1)
                DP[j] = INPUT[i][j];
        }
    }
    // DP
    for (int i = size - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            left = DP[j];
            if (j <= i + 1)
                right = DP[j + 1];
            else
                right = 0;
            DP[j] = left > right ? left + INPUT[i][j] : right + INPUT[i][j];
        }
        // for (int j = 0; j < i + 1; j++)
        //     cout << DP[j] << " ";
        // cout << endl;
    }
    cout << DP[0];
    for (int i = 0; i < size; i++)
        delete INPUT[i];
    delete INPUT;
    return (0);
}