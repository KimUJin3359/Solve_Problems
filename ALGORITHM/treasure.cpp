#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[50];
int B[50];

int main()
{
    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    sort(A, A + N);
    sort(B, B + N);
    // solve
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
    for (int i = 0; i < N; i++)
        cout << B[i] << " ";
    cout << endl;
    for (int i = 0; i < N; i++)
        res += (A[i] * B[(N - 1) - i]);
    cout << res;
    return (0);
}