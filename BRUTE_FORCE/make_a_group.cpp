#include <string>
#include <map>
#include <vector>

using namespace std;
map<int, vector<int> > MAP;

int solution(vector<int> stats) {
    int answer = 0;
    int idx = 0;
    
    for (int i = 0; i < stats.size(); i++) {
        int flag = 0;
        int s_idx = 0;
        int s_max = 0;
        
        for (auto iter = MAP.begin(); iter != MAP.end(); iter++) {
            int v_max = (iter->second)[(iter->second).size() - 1];
            
            if ((iter->second)[(iter->second).size() - 1] < stats[i]) {
                if (s_max < v_max) {
                    s_max = v_max;
                    s_idx = iter->first;
                    flag = 1;
                }
            }
        }
        if (flag) {
            MAP[s_idx].push_back(stats[i]);
        }
        else {
            MAP[++idx].push_back(stats[i]);
        }
    }
    return idx;
}