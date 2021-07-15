#include <iostream>
#include <deque>
#include <string>
using namespace std;

int N;
string ORDER;
deque<int> RES;

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
            RES.push_front(num);
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
        else if (ORDER == "front")
        {
            if (RES.size())
                cout << RES[RES.size() - 1] << endl;
            else
                cout << -1 << endl;
        }
        else if (ORDER == "back")
        {
            if (RES.size())
                cout << RES[0] << endl;
            else
                cout << -1 << endl;
        }
    }
}