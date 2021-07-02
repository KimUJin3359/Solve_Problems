#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MAP[101][101];
int N;

void fill_map(int n) {
    for (int i = 1; i <= N; i++) {
        if (n == i)
            continue;
        if (MAP[n][i] != 0) {
            for (int j = 1; j <= N; j++) {
                if (MAP[n][i] == MAP[i][j] && MAP[n][j] == 0)
                {
                    MAP[n][j] = MAP[n][i];
                    MAP[j][n] = -MAP[n][i];
                    fill_map(j);
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    N = n;
    for (int i = 1; i <= n; i++) {
        for (int j= 1; j<= n; j++)
            MAP[i][j] = 0;
    }
    // 1 : WIN, -1 : LOSE
    for (int i = 0; i < results.size(); i++) {
        MAP[results[i][0]][results[i][1]] = 1;
        MAP[results[i][1]][results[i][0]] = -1;
    }
    // 1 < 2, 2 < 3 => 1 < 3
    // 1 < 2, 3 < 2 => ?
    // 1 > 2, 2 < 3 => ?
    // 1 > 2, 2 > 3 => 1 > 3
    for (int i = 1; i <= N; i++)
        fill_map(i);
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        
        for (int j = 1; j <= N; j++)
        {
            if (MAP[i][j])
                sum++;
        }
        if (sum == n - 1)
            answer++;
    }
    return answer;
}