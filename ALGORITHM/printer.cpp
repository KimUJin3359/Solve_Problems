#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > PRIOR;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int idx = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        PRIOR.push(priorities[i]);
    }
    while (PRIOR.size()) {
        int val = PRIOR.top();
        
        PRIOR.pop();
        while (val != priorities[idx]) {
            idx++;
            if (idx >= priorities.size())
                idx = 0;
        }
        priorities[idx] = -1;
        answer++;
        if (idx == location)
            break;
    }
    return answer;
}