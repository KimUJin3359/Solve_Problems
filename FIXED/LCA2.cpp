#include <iostream>
using namespace std;

int N, M;
int UNION_SET[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        UNION_SET[i] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        int fir, sec;

        cin >> fir >> sec;
        if (fir > sec) {
            int tmp;

            tmp = fir;
            fir = sec;
            sec = tmp;
        }
        // SET PARENT
        UNION_SET[sec] = fir;
    }
    // GET MINIMUM PARENT
    cin >> M;
    for (int i = 0; i < M; i++) {
        int fir, sec;

        cin >> fir >> sec;
        while (fir != sec) {
            if (fir > sec) {
                fir = UNION_SET[fir];
            }
            else {
                sec = UNION_SET[sec];
            }
        }
        cout << fir << endl;
    }
    return (0);
}