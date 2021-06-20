#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;

int main()
{
    int num;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    num = N;
    if (num == 1)
        num++;
    while (true)
    {
        string str = to_string(num);
        string rev = to_string(num);

        reverse(rev.begin(), rev.end());
        if (str == rev)
        {
            int flag = 0;

            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {   
                cout << num;
                break;
            }
        }
        num++;
    }    
    return (0);
}