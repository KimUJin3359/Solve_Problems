#include <iostream>
#include <deque>
using namespace std;

int N;

int main()
{
    int rep = 1;
    int sum = 0;
    int num = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    num = ((N % 10) * 10) + (((N / 10) + (N % 10)) % 10); 
    while (num != N)
    {
        num = ((num % 10) * 10) + (((num / 10) + (num % 10)) % 10);
        rep++;
    }
    cout << rep;
    return (0);
}