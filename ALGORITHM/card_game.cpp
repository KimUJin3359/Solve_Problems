#include <iostream>
#include <algorithm>
using namespace std;

int CARD[5][2];
int NUM[5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 5; i++)
    {
        char c;

        cin >> c >> CARD[i][1];
        if (c == 'R')
            CARD[i][0] = 0;
        else if (c == 'B')
            CARD[i][0] = 1;
        else if (c == 'Y')
            CARD[i][0] = 2;
        else
            CARD[i][0] = 3;
        NUM[i] = CARD[i][1];
    }
    sort(NUM, NUM + 5);
    // 1.
    if (CARD[0][0] == CARD[1][0] && CARD[1][0] == CARD[2][0] && CARD[2][0] == CARD[3][0] && CARD[3][0] == CARD[4][0]
    && NUM[0] == NUM[1] - 1 && NUM[1] == NUM[2] - 1 &&
    NUM[2] == NUM[3] - 1 && NUM[3] == NUM[4] - 1)
        cout << (900 + NUM[4]);
    // 2.
    else if (NUM[0] == NUM[3] || NUM[1] == NUM[4])
        cout << (800 + NUM[2]);
    // 3.
    else if (NUM[0] == NUM[1] && NUM[1] == NUM[2] && NUM[3] == NUM[4])
        cout << (700 + (NUM[1] * 10) + NUM[3]);
    else if (NUM[0] == NUM[1] && NUM[2] == NUM[3] && NUM[3] == NUM[4])
        cout << (700 + (NUM[2] * 10) + NUM[0]);
    // 4.
    else if (CARD[0][0] == CARD[1][0] && CARD[1][0] == CARD[2][0] &&
    CARD[2][0] == CARD[3][0] && CARD[3][0] == CARD[4][0])
        cout << (600 + NUM[4]);
    // 5.
    else if (NUM[0] == NUM[1] - 1 && NUM[1] == NUM[2] - 1 && NUM[2] == NUM[3] - 1
    && NUM[3] == NUM[4] - 1)
        cout << (500 + NUM[4]);
    // 6.
    else if ((NUM[0] == NUM[1] && NUM[1] == NUM[2]) ||
    (NUM[1] == NUM[2] && NUM[2] == NUM[3]))
        cout << (400 + NUM[1]);
    else if (NUM[2] == NUM[3] && NUM[3] == NUM[4])
        cout << (400 + NUM[3]);
    // 7.
    else if (((NUM[0] == NUM[1] || NUM[1] == NUM[2]) && NUM[3] == NUM[4])
    || (NUM[0] == NUM[1] && NUM[2] == NUM[3]))
        cout << (300 + NUM[3] * 10 + NUM[1]);
    // 8.
    else if (NUM[0] == NUM[1] || NUM[1] == NUM[2])
        cout << (200 + NUM[1]);
    else if (NUM[2] == NUM[3] || NUM[3] == NUM[4])
        cout << (200 + NUM[3]);
    else
        cout << 100 + NUM[4];
    return (0);
}