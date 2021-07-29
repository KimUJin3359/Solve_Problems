#include <iostream>
#include <vector>
using namespace std;

int N;
bool CHECK[4000001] = { 0, };
vector<int> PRIME;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // INITIALIZE
    cin >> N;
    for (int i = 2; i <= N; i += 2) {
        CHECK[i] = true;
    }
    PRIME.push_back(2);
    for (int i = 3; i <= N; i += 2) {
        if (!CHECK[i]) {
            for (int j = 3; j * i <= N; j += 2)
                CHECK[j * i] = true;
            PRIME.push_back(i);
        }
    }

    // FIND SUM
    int cnt = 0;
    int s_idx = 0;
    int e_idx = 0;
    int sum = 0;

    while (e_idx <= PRIME.size()) {
        if (sum < N) {
            sum += PRIME[e_idx++]; 
        }
        else {
            if (sum == N)
                cnt++;
            sum -= PRIME[s_idx++];
        }
    }
    cout << cnt;
    return (0);
}