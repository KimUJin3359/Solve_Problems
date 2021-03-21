#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<pair<int, int> > SEARCH;
int VISITED[100][100];
bool MAP[100][100];
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
int N, M;

int main()
{
	string input;
	int now_r, now_c, i;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			MAP[i][j] = input[j] - '0';
			VISITED[i][j] = 0;
		}
	}
	VISITED[0][0] = 1;
	SEARCH.push({ 0, 0 });
	while (SEARCH.size())
	{
		now_r = SEARCH.front().first;
		now_c = SEARCH.front().second;
		SEARCH.pop();
		for (i = 0; i < 4; i++)
		{
			if (now_r + DR[i] >= 0 && now_r + DR[i] < N
				&& now_c + DC[i] >= 0 && now_c + DC[i] < M
				&& VISITED[now_r + DR[i]][now_c + DC[i]] == 0
				&& MAP[now_r + DR[i]][now_c + DC[i]] == 1)
			{
				VISITED[now_r + DR[i]][now_c + DC[i]] = VISITED[now_r][now_c] + 1;
				if (now_r + DR[i] == N - 1 && now_c + DC[i] == M - 1)
					break;
				SEARCH.push({ now_r + DR[i], now_c + DC[i] });
			}
		}
		if (i != 4)
			break;
	}
	while (SEARCH.size())
		SEARCH.pop();
	cout << VISITED[N - 1][M - 1] << endl;
	return (0);
}