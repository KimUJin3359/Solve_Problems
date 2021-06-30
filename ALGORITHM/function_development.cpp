#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    
    while (cnt < progresses.size())
    {
        int i;
        
        // + one speed 
        for (i = cnt; i < speeds.size(); i++)
            progresses[i] += speeds[i];
        i = cnt;
        while (cnt < progresses.size() && progresses[cnt] >= 100)
            cnt++;
        if (cnt - i != 0)
            answer.push_back(cnt - i);
    }
    return answer;
}