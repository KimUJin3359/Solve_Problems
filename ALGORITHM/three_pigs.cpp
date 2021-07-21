#include <string>
#include <vector>

using namespace std;

int solution(vector<int> foods) {
    int answer = 0;
    int total = 0;
    int aver = 0;
    vector<int> sum;
    
    // INITIALIZE
    for (int i = 0; i < foods.size(); i++) {
        if (i == 0)
            sum.push_back(foods[i]);
        else {
            sum.push_back(foods[i] + sum[i - 1]);
        }
    }
    // SOLVE
    total = sum[foods.size() - 1];
    if ((total % 3) != 0)
        return (0);
    aver = total / 3;
    // SOLVE
    for (int i = 0; i < foods.size() - 2; i++) {
        if (sum[i] != aver)
            continue;
        for (int j = i + 1; j < foods.size() - 1; j++) {
            int sum2 = sum[j] - sum[i];

            if (sum2 == aver)
                answer++;
        }
    }
    return answer;
}