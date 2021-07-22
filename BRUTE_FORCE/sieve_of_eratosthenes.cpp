#include <iostream>
using namespace std;

int N, K;
bool VISITED[1001];

int main()
{
    int cnt = 0;
    int now = 2;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 2; i <= N; i++) 
        VISITED[i] = false;
    while (true) {
        int flag = 0;

        if (!VISITED[now]) {
            for (int i = 1; now * i <= N; i++) {
                    if (!VISITED[i * now]) {
                    VISITED[i * now] = true;
                    cnt++;
                    if (cnt == K)
                    {
                        cout << now * i;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag)
            break;
        now++;
    }
    return (0);
}