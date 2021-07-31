#include <iostream>
#include <vector>
using namespace std;

int COLOR[128][2];

int buy_clothes(vector<string> color, vector<int> prices)
{
    int answer =0;
    int same_color = 0;

    for (int i = (int)'A'; i <= (int)'Z'; i++)
    {
        COLOR[i][0] = 0;
        COLOR[i][1] = 0;
    }
    for (int i = 0; i < color.size(); i++)
    {
        COLOR[color[i][0]][0]++;
        COLOR[color[i][1]][1]++;
    }
    for (int i = (int)'A'; i <= (int)'Z'; i++)
    {
        while (COLOR[i][0] > 0 && COLOR[i][1] > 0)
        {
            COLOR[i][0]--;
            COLOR[i][1]--;
            same_color++;
        }
    }
    answer = (same_color * prices[0]);
    answer += (prices[1] > prices[0] * 2) ? 
    ((color.size() - same_color) * 2 * prices[0]) : (color.size() - same_color) * prices[1];
    return (answer);
}

int main()
{
    vector<string> color;
    vector<int> prices;

    ios::sync_with_stdio(false);
    cin.tie(0);
    color.push_back("RW");
    color.push_back("WR");
    prices.push_back(3500);
    prices.push_back(6000);
    cout << buy_clothes(color, prices);
    return (0);
}