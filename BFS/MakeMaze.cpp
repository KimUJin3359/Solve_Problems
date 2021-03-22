#include <iostream>
#include <string>
#include <queue>
#define MAX 987654321
using namespace std;

queue<pair<int, int> > SEARCH;
int VISITED[50][50];
bool MAP[50][50];
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
int N;

int main()
{
	int now_r, now_c;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;

		cin >> input;
		for (int j = 0; j < N; j++)
		{
			MAP[i][j] = input[j] - '0';
			VISITED[i][j] = MAX;
		}
	}
	VISITED[0][0] = 0;
	SEARCH.push({ 0, 0 });
	while (SEARCH.size())
	{
		now_r = SEARCH.front().first;
		now_c = SEARCH.front().second;
		SEARCH.pop();
		for (int i = 0; i < 4; i++)
		{
			if (now_r + DR[i] >= 0 && now_r + DR[i] < N
				&& now_c + DC[i] >= 0 && now_c + DC[i] < N)
			{
				if (MAP[now_r + DR[i]][now_c + DC[i]])
				{
					if (VISITED[now_r][now_c] < VISITED[now_r + DR[i]][now_c + DC[i]])
					{
						VISITED[now_r + DR[i]][now_c + DC[i]] = VISITED[now_r][now_c];
						SEARCH.push({ now_r + DR[i], now_c + DC[i] });
					}
				}
				else
				{
					if (VISITED[now_r][now_c] + 1 < VISITED[now_r + DR[i]][now_c + DC[i]])
					{
						VISITED[now_r + DR[i]][now_c + DC[i]] = VISITED[now_r][now_c] + 1;
						SEARCH.push({ now_r + DR[i], now_c + DC[i] });
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << VISITED[i][j] << " ";
		cout << endl;
	}
	cout << VISITED[N - 1][N - 1];
}