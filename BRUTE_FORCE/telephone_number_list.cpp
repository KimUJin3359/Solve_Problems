#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int FLAG;
int T, N;
string CASE[10000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int C = 0; C < T; C++)
    {
        FLAG = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> CASE[i];
        sort(CASE, CASE + N);
        for (int i = 0; i < N - 1; i++)
        {
            int len1 = strlen(CASE[i].c_str()), len2 = strlen(CASE[i - 1].c_str());

            if (i > 0)
            {
                if (strncmp(CASE[i - 1].c_str(), CASE[i].c_str(), ((len1 < len2) ? len1 : len2)) == 0)
                    FLAG = 1;
            }
            len2 = strlen(CASE[i + 1].c_str());
            if (strncmp(CASE[i].c_str(), CASE[i + 1].c_str(), (len1 < len2) ? len1 : len2) == 0)
                FLAG = 1;
            if (FLAG)
                break;
        }
        if (FLAG)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return (0);
}