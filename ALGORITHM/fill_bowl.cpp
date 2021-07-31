#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool VISITED[1001];

vector<int> fill_bowl(int l1, int l2)
{
    vector<int> answer;
    int max;

    if (l1 > l2)
    {
        int tmp = l1;

        l1 = l2;
        l2 = tmp;
    }
    for (int i = 1; i <= l2; i++)
        VISITED[i] = false;
    // l1의 배수
    for (int i = 1; i * l1 <= l2; i++)
    {
        max = i * l1;
        if (!VISITED[i * l1])
        {
            VISITED[i * l1] = true;
            answer.push_back(i * l1);
        }
    }
    // l2
    if (!VISITED[l2])
    {
        VISITED[l2] = true;
        answer.push_back(l2);
    }
    // l1의 l2에 최고 근접한 배수 - l2
    if (!VISITED[(max + l1) - l2])
    {
        VISITED[(max + l1) - l2] = true;
        answer.push_back((max + l1) - l2);
    }
    sort(answer.begin(), answer.end());
    return (answer);
}

int main()
{
    vector<int> answer;

    ios::sync_with_stdio(false);
    cin.tie(0);
    answer = fill_bowl(2, 7);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}