#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, RES = 0;;
string NOT_LISTEN[500000];
string NOT_SEE[500000];
string ANS[500000];

int main()
{
    int idx_l = 0, idx_s = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> NOT_LISTEN[i];
    for (int i = 0; i < M; i++)
        cin >> NOT_SEE[i];
    sort(NOT_LISTEN, NOT_LISTEN + N);
    sort(NOT_SEE, NOT_SEE + M);
    while (idx_l < N  && idx_s < M)
    {
        if (NOT_LISTEN[idx_l] > NOT_SEE[idx_s])
            idx_s++;
        else if (NOT_LISTEN[idx_l] < NOT_SEE[idx_s])
            idx_l++;
        else
        {
            ANS[RES++] = NOT_LISTEN[idx_l];
            idx_l++;
            idx_s++;
        }
    }
    sort(ANS, ANS + RES);
    cout << RES << endl;
    for (int i = 0; i < RES; i++)
        cout << ANS[i] << endl;
    return (0);
}