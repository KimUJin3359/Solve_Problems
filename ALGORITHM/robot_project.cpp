#include <iostream>
#include <algorithm>
using namespace std;

int X, N;
int MAX, MIN;
int FLAG;
int SIZE[1000000];
// 1cm = 10000000nm

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    while (cin >> X)
    {
        FLAG = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> SIZE[i];
        sort(SIZE, SIZE + N);
        MIN = 0;
        MAX = N - 1;
        while (MIN < MAX)
        {
            int sum = SIZE[MIN] + SIZE[MAX];

            if (sum > 10000000 * X)
                MAX--;
            else if (sum < 10000000 * X)
                MIN++;
            else
            {
                FLAG = 1;
                break;
            }
        }
        if (FLAG)
            cout << "yes " << SIZE[MIN] << " " << SIZE[MAX] << endl;
        else
            cout << "danger" << endl;
    }
    return (0);
}