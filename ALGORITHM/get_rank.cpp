#include <iostream>
#include <vector>
using namespace std;

int N, SCORE, MAX;
int RANK = 1;
vector<int> VECTOR;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> SCORE >> MAX;
    for(int i = 0; i < N; i++)
    {
        int num;

        cin >> num;
        VECTOR.push_back(num);
    }
    // SOLVE
    if (N >= MAX && VECTOR[N - 1] >= SCORE)
        RANK = -1;
    else
    {
        for (int i = 0; i < N && VECTOR[i] > SCORE; i++)
            RANK++;
    }
    cout << RANK;
    return (0);
}