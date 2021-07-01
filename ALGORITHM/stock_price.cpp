#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<int, int> MAP;
int PRICE[10000] = { 0, };

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    // INIT
    for (int i = 0; i < prices.size(); i++)
        PRICE[prices[i]]++;
    for (int i = 0; i < prices.size(); i++) {
        int sum = 0;
        
        for (int j = i + 1; j < prices.size(); j++) {
            if (++sum && prices[i] > prices[j])
                break;
        }
        answer.push_back(sum);
    }
    return answer;
}