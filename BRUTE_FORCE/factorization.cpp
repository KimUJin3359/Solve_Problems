#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> ANS;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (N != 1)
    {
        for (int i = 2; i <= N; i++) 
        {
            if (!(N % i))
            {
                N /= i;
                ANS.push_back(i);
                break;
            }
        }
    }
    sort(ANS.begin(), ANS.end());
    for (int i = 0; i < ANS.size(); i++)
        cout << ANS[i] << endl;
    return (0);
}