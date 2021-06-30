#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> ARR;
int CLOTHES[30] = { 0, };

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // GET 
    for (int i = 0; i < clothes.size(); i++)
    {
        int flag = 0;
        
        for (int j = 0; j < ARR.size(); j++)
        {  
            if (ARR[j] == clothes[i][1])
            {
                CLOTHES[j]++;
                flag = 1;
                break;
            }
        }    
        if (!flag)
        {
            ARR.push_back(clothes[i][1]);
            CLOTHES[ARR.size() - 1]++;
        }
    }
    // CALC
    // 머리부분 3개고, 눈부분 2개
    // ([머리] 입을 수 있는 경우 3가지 + 아무것도 안 입는 경우 1가지) * ([눈] 입을 수 있는 경우 2가지 + 아무것도 안 입는 경우 1가지) 
    // 아무것도 안 입는 경우 1
    for (int i = 0; i < ARR.size(); i++)
        answer *= (CLOTHES[i] + 1);
    answer -= 1;
    return answer;
}