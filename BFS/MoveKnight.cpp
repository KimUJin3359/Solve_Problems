#include <iostream>
#include <queue>
using namespace std;

int VISITED[300][300];
queue<pair<int, int> > NOW;
int SIZE;
int DES_R, DES_C;
int NOW_R, NOW_C;

int main()
{
	int T;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int C = 0; C < T; C++)
	{
		cin >> SIZE;
		cin >> NOW_R >> NOW_C;
		cin >> DES_R >> DES_C;
		
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				VISITED[i][j] = -1;
		}
		if (NOW_R == DES_R && NOW_C == DES_C)
		{
			cout << 0 << endl;
			continue;
		}
		NOW.push({ NOW_R, NOW_C });
		VISITED[NOW_R][NOW_C] = 0;
		while (NOW.size())
		{
			int now_r = NOW.front().first;
			int now_c = NOW.front().second;
			NOW.pop();
			// 대각선 좌상 상
			if (now_r - 2 >= 0 && now_c - 1 >= 0 && VISITED[now_r - 2][now_c - 1] == -1)
			{
				VISITED[now_r - 2][now_c - 1] = VISITED[now_r][now_c] + 1;
				if (now_r - 2 == DES_R && now_c - 1 == DES_C)
					break;
				NOW.push({ now_r - 2, now_c - 1 });
			}
			// 대각선 좌상 하
			if (now_r - 1 >= 0 && now_c - 2 >= 0 && VISITED[now_r - 1][now_c - 2] == -1)
			{
				VISITED[now_r - 1][now_c - 2] = VISITED[now_r][now_c] + 1;
				if (now_r - 1 == DES_R && now_c - 2 == DES_C)
					break;
				NOW.push({ now_r - 1, now_c - 2 });
			}
			// 대각선 우상 상
			if (now_r - 2 >= 0 && now_c + 1 < SIZE && VISITED[now_r - 2][now_c + 1] == -1)
			{
				VISITED[now_r - 2][now_c + 1] = VISITED[now_r][now_c] + 1;
				if (now_r - 2 == DES_R && now_c + 1 == DES_C)
					break;
				NOW.push({ now_r - 2, now_c + 1 });
			}
			// 대각선 우상 하
			if (now_r - 1 >= 0 && now_c + 2 < SIZE && VISITED[now_r - 1][now_c + 2] == -1)
			{
				VISITED[now_r - 1][now_c + 2] = VISITED[now_r][now_c] + 1;
				if (now_r - 1 == DES_R && now_c + 2 == DES_C)
					break;
				NOW.push({ now_r - 1, now_c + 2 });
			}
			// 대각선 좌하 상
			if (now_r + 1 < SIZE && now_c - 2 >= 0 && VISITED[now_r + 1][now_c - 2] == -1)
			{
				VISITED[now_r + 1][now_c - 2] = VISITED[now_r][now_c] + 1;
				if (now_r + 1 == DES_R && now_c - 2 == DES_C)
					break;
				NOW.push({ now_r + 1, now_c - 2 });
			}
			// 대각선 좌하 하
			if (now_r + 2 < SIZE && now_c - 1 >= 0 && VISITED[now_r + 2][now_c - 1] == -1)
			{
				VISITED[now_r + 2][now_c - 1] = VISITED[now_r][now_c] + 1;
				if (now_r + 2 == DES_R && now_c - 1 == DES_C)
					break;
				NOW.push({ now_r + 2, now_c - 1 });
			}
			// 대각선 우하 상
			if (now_r + 1 < SIZE && now_c + 2 < SIZE && VISITED[now_r + 1][now_c + 2] == -1)
			{
				VISITED[now_r + 1][now_c + 2] = VISITED[now_r][now_c] + 1;
				if (now_r + 1 == DES_R && now_c + 2 == DES_C)
					break;
				NOW.push({ now_r + 1, now_c + 2 });
			}
			// 대각선 우하 하
			if (now_r + 2 < SIZE && now_c + 1 < SIZE && VISITED[now_r + 2][now_c + 1] == -1)
			{
				VISITED[now_r + 2][now_c + 1] = VISITED[now_r][now_c] + 1;
				if (now_r + 2 == DES_R && now_c + 1 == DES_C)
					break;
				NOW.push({ now_r + 2, now_c + 1 });
			}
		}
		while (NOW.size())
			NOW.pop();
		cout << VISITED[DES_R][DES_C] << endl;
	}
	return (0);
}