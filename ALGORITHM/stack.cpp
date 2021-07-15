#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string ORDER;
vector<int> RES;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ORDER;
        if (ORDER == "push")
        {
            int num;

            cin >> num;
            RES.push_back(num);
        }
        else if (ORDER == "pop")
        {
            if (RES.size())
            {
                cout << RES[RES.size() - 1] << endl;
                RES.pop_back();
            }
            else
                cout << -1 << endl;
        }
        else if (ORDER == "size")
            cout << RES.size() << endl;
        else if (ORDER == "empty")
        {
            if (RES.size())
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else if (ORDER == "top")
        {
            if (RES.size())
                cout << RES[RES.size() - 1] << endl;
            else
                cout << -1 << endl;
        }
    }
    return (0);
}