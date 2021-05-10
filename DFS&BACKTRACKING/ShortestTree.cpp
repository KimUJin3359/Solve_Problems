#include <string>
#include <vector>
#include <iostream>

using namespace std;

int NUM[10000];
int SET[10000];
int BUF[10000];
int SUM[10000];
int MAX;
int K, N;
vector<int> PER;

void set_parent(int i, int j)
{
    if (SET[i] == -1)
        SET[i] = i;
    SET[j] = i;
}

int find_parent(int i)
{
    if (SET[i] == i)
        return (i);
    else
        return (find_parent(SET[i]));
}

void cut_k_trees() 
{
    int max = -1;
    for (int i = 0; i < K - 1; i++)
    {
        BUF[i] = SET[PER[i]];
        SET[PER[i]] = PER[i];
    }
    for (int i = 0; i < N; i++)
        SUM[i] = 0;
    for (int i = 0; i < N; i++)
        SUM[find_parent(i)] += NUM[i]; 
    for (int i = 0; i < N; i++)
    {
        if (max < SUM[i])
            max = SUM[i];
    }
    for (int i = 0; i < K - 1; i++)
        SET[PER[i]] = BUF[i];
    if (max < MAX)
        MAX = max;
}

void get_permutation(int last)
{
    if (PER.size() == K - 1)
    {
        cut_k_trees();
        return;
    }
    for (int i = last + 1; i < N; i++)
    {
        PER.push_back(i);
        get_permutation(i);
        PER.pop_back();
    }
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;

    MAX = 987654321;
    K = k;
    N = num.size();
    for (int i = 0; i < N; i++)
        SET[i] = -1;
    for (int i = 0; i < N; i++)
        NUM[i] = num[i]; 
    // set parent(connect node)
    for (int i = 0; i < N; i++)
    {
        if (links[i][0] != -1)
            set_parent(i, links[i][0]);
        if (links[i][1] != -1)
            set_parent(i, links[i][1]);
    }
    // cut and find max
    get_permutation(-1);
    answer = MAX;
    return answer;
}