#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int M[10][10];
int N;
int RES;
deque<pair<int, int> > PEOPLE;
deque<pair<int, int> > STAIR;

// return absoulte number
int abs(int x)
{
    return (x > 0) ? x : -x;
}

// return distance of two points
int get_distance(pair<int, int> a, pair<int ,int> b)
{
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

// get the least distance for stair
priority_queue<int , vector<int>, greater<int> > P_STAIR1;
priority_queue<int , vector<int>, greater<int> > P_STAIR2;
// for counting 3 people
deque<int> N_STAIR1;
deque<int> N_STAIR2;

void BROUTE_FORCE()
{
    int time;
    int num = PEOPLE.size();
    int size = 1 << num;
    int people_n = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i & (1 << j))
                P_STAIR1.push(get_distance(PEOPLE[j], STAIR[0]));
            else
                P_STAIR2.push(get_distance(PEOPLE[j], STAIR[1]));
        }
        // calculate stair1's time
        for (int j = 0; j < P_STAIR1.size(); j++)
        {
            if (N_STAIR1.size() < 3)
                N_STAIR1.push_back(P_STAIR1.top());
            else 
            {
                int time = (P_STAIR1.top() > N_STAIR1[0] + M[STAIR[0].first][STAIR[0].second]) ? P_STAIR1.top() : N_STAIR1[0] + M[STAIR[0].first][STAIR[0].second];
                N_STAIR1.push_back(time);
                N_STAIR1.pop_front();
            }
            P_STAIR1.pop();
        }    
        if (N_STAIR1.size())
        {
            while (N_STAIR1.size() != 1)
                N_STAIR1.pop_front();
            time = N_STAIR1[0] + M[STAIR[0].first][STAIR[0].second];
        }
        else 
            time = 987654321;

        // calculate stair2's time
        for (int j = 0; j < P_STAIR2.size(); j++)
        {
            if (N_STAIR2.size() < 3)
            {
                N_STAIR2.push_back(P_STAIR2.top());
                P_STAIR2.pop();
            }
            else 
            {
                int time = (P_STAIR2.top() > N_STAIR2[0] + M[STAIR[1].first][STAIR[1].second]) ? P_STAIR2.top() : N_STAIR2[0] + M[STAIR[1].first][STAIR[1].second];
                P_STAIR2.pop();
                N_STAIR2.push_back(time);
                N_STAIR2.pop_front();
            }
        }    
        if (N_STAIR2.size())
        {
            while (N_STAIR2.size() != 1)
                N_STAIR2.pop_front();
            time = (time > N_STAIR2[0] + M[STAIR[1].first][STAIR[1].second]) ? time : N_STAIR2[0] + M[STAIR[1].first][STAIR[1].second];
        }
    }
    if (time < RES)
        RES = time;
    N_STAIR1.clear();
    N_STAIR2.clear();
}

int main()
{
    int T;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        cin >> N;
        RES = 987654321;
        // 계단 및 사람 초기화
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> M[i][j];
                if (M[i][j] == 1)
                    PEOPLE.push_back(make_pair(i, j));
                else if (M[i][j] > 1)
                    STAIR.push_back(make_pair(i, j));
            }
        }
        BROUTE_FORCE();
        STAIR.clear();
        PEOPLE.clear();
        cout << "#" << C << " " << RES << endl;
    }
}