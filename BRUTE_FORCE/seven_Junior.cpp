#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H[9];
vector<int> ANS;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 9; i++)
        cin >> H[i];
    for (int i = 0b001111111; i < (1 << 10); i++)
    {
        int sum = 0;
        int cnt = 0;

        for (int j = 0; j < 9; j++)
        {
            if (i & (1 << j))
            {
                sum += H[j];
                cnt++;
            }
        }
        if (cnt == 7 && sum == 100)
        {
            for (int j = 0; j < 9; j++)
            {
                if (i & (1 << j))
                    ANS.push_back(H[j]);
            }
            sort(ANS.begin(), ANS.end());
            for (int j = 0; j < ANS.size(); j++)
                cout << ANS[j] << endl;
            return (0);
        }
    }

}