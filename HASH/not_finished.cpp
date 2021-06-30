#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> HASH_P[21];
vector<string> HASH_C[21];

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    if (participant.size() == completion.size())
        return (answer);
    // make HASH (participant)
    for (int i = 0; i < participant.size(); i++)
    {
        int size = participant[i].size();

        HASH_P[size].push_back(participant[i]);
    }
    // make HASH (completion)
    for (int i = 0; i < completion.size(); i++)
    {
        int size = completion[i].size();

        HASH_C[size].push_back(completion[i]);
    }
    // compare
    for (int i = 1; i < 21; i++)
    {
        int flag = 0;

        if (HASH_P[i].size() != HASH_C[i].size())
        {
            sort(HASH_P[i].begin(), HASH_P[i].end());
            sort(HASH_C[i].begin(), HASH_C[i].end());

            for (int j = 0; j < HASH_C[i].size(); j++)
            {
                if (HASH_P[i][j] != HASH_C[i][j])
                {
                    flag = 1;
                    answer = HASH_P[i][j];
                    break;
                }
            }
            if (!flag)
                answer = HASH_P[i][HASH_P[i].size() - 1];
        }
        if (flag)
            break;
    }
    return answer;
}