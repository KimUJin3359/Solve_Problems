#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<string> GENRE;
vector<pair<int, int> > LIST[100];
bool VISITED[100];
pair<int, int> PLAY[100];

bool sort_a(pair<int, int> a, pair<int, int> b) { return a.second < b.second; } 
bool sort_b(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // INIT
    for (int i = 0; i < 100; i++)
        PLAY[i].second = 0;
    for (int i = 0; i < genres.size(); i++)
    {
        int flag = 0;
        int list;
        
        for (int j = 0; j < GENRE.size(); j++)
        {
            if (GENRE[j] == genres[i])
            {
                flag = 1;
                LIST[j].push_back(make_pair(plays[i], i));
                list = j;
            }
        }
        if (!flag)
        {
            GENRE.push_back(genres[i]);
            LIST[GENRE.size() - 1].push_back(make_pair(plays[i], i));
            list = GENRE.size() - 1;
        }
        PLAY[list].first = list;
        PLAY[list].second += plays[i];
    }
    // COMPARE
    int cnt = 0;
    sort(PLAY, PLAY + GENRE.size(), sort_b);
    for (int i = 0; i < GENRE.size(); i++)
    {
        // cout << PQ.top().first << " ";
        int max = -1;
        int idx = -1;
        int prev_idx;
        int flag = 0;

        sort(LIST[PLAY[i].first].begin(), LIST[PLAY[i].first].end(), sort_a);
        //for (int j = 0; j < LIST[i].size(); j++)
        //    cout << LIST[i][j].second << " ";
        for (int j = 0; j < LIST[PLAY[i].first].size(); j++)
        {
            // LIST : first = plays, second = idx
            if (max < LIST[PLAY[i].first][j].first)
            {
                max = LIST[PLAY[i].first][j].first;
                idx = LIST[PLAY[i].first][j].second;
            }
        }
        answer.push_back(idx);
        prev_idx = idx;
        max = -1;
        idx = -1;
        if (LIST[PLAY[i].first].size() < 2)
            continue;
        for (int j = 0; j < LIST[PLAY[i].first].size(); j++)
        {
            if (max < LIST[PLAY[i].first][j].first && LIST[PLAY[i].first][j].second != prev_idx)
            {
                max = LIST[PLAY[i].first][j].first;
                idx = LIST[PLAY[i].first][j].second;
            }
        }
        answer.push_back(idx);
    }
    return answer;
}