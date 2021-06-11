#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct  s_prize
{
    int gold;
    int silver;
    int bronze;
}               t_prize;

int N, FIND;
t_prize PRIZE[1001];

struct compare
{
    bool operator()(int a, int b)
    {
        if (PRIZE[a].gold == PRIZE[b].gold)
        {
            if (PRIZE[a].silver == PRIZE[b].silver)
                return PRIZE[a].bronze < PRIZE[b].bronze;
            return PRIZE[a].silver < PRIZE[b].silver;
        }
        return (PRIZE[a].gold < PRIZE[b].gold);
    }
};

priority_queue<int, vector<int>, compare> PQ;

int main()
{
    int rank = 1;
    // Init
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> FIND;
    for (int i = 0; i < N; i++)
    {
        int num, gold, silver, bronze;

        cin >> num >> gold >> silver >> bronze;
        PRIZE[num].gold = gold;
        PRIZE[num].silver = silver;
        PRIZE[num].bronze = bronze;
        PQ.push(num);
    }
    // Solve
    while (PQ.top() != FIND)
    {
        if (PRIZE[PQ.top()].gold == PRIZE[FIND].gold && 
            PRIZE[PQ.top()].silver == PRIZE[FIND].silver &&
            PRIZE[PQ.top()].bronze == PRIZE[FIND].bronze)
            break;
        PQ.pop();
        rank++;
    }
    cout << rank;
    return (0);
}