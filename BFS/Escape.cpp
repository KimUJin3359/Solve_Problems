#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int> > WATER[2];
queue<pair<int, int> > MOVE;

int VISITED[50][50];
char MAP[50][50];
int DR[4] = { -1, 1, 0, 0 };
int DC[4] = { 0, 0, -1, 1 };
int R, C;
int NOW_R, NOW_C;
int END_R, END_C;

int main()
{
	int time = -1;
	int wat_r, wat_c;
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			cin >> MAP[i][j];
			VISITED[i][j] = -1;
			if (MAP[i][j] == 'S')
			{
				NOW_R = i;
				NOW_C = j;
			}
			else if (MAP[i][j] == 'D')
			{
				END_R = i;
				END_C = j;
			}
			else if (MAP[i][j] == '*')
				WATER[0].push({ i, j });
		}
	}
	// 비버를 BFS로 찾아갈 때
	// 물이 시간이 증가할 때 만 옆으로 번짐
	VISITED[NOW_R][NOW_C] = 0;
	MOVE.push({ NOW_R, NOW_C });
	while (MOVE.size())
	{
		NOW_R = MOVE.front().first;
		NOW_C = MOVE.front().second;
		MOVE.pop();
		if (VISITED[NOW_R][NOW_C] > time)
		{
			time = VISITED[NOW_R][NOW_C];
			// 물이 먼저 번지고, 물이 번진 곳으로 가지 못함
			// time 값을 둬서 time이 증가할 때만 물이 번지게 설정
			while (WATER[time % 2].size())
			{
				wat_r = WATER[time % 2].front().first;
				wat_c = WATER[time % 2].front().second;
				WATER[time % 2].pop();
				for (i = 0; i < 4; i++)
				{
					if (wat_r + DR[i] >= 0 && wat_r + DR[i] < R
						&& wat_c + DC[i] >= 0 && wat_c + DC[i] < C
						&& MAP[wat_r + DR[i]][wat_c + DC[i]] != 'X'
						&& MAP[wat_r + DR[i]][wat_c + DC[i]] != 'D'
						&& MAP[wat_r + DR[i]][wat_c + DC[i]] != '*')
					{
						MAP[wat_r + DR[i]][wat_c + DC[i]] = '*';
						WATER[1 - (time % 2)].push({ wat_r + DR[i], wat_c + DC[i] });
					}
				}
			}
		}
		// 고슴도치의 이동
		for (i = 0; i < 4; i++)
		{
			if (NOW_R + DR[i] >= 0 && NOW_R + DR[i] < R
				&& NOW_C + DC[i] >= 0 && NOW_C + DC[i] < C
				&& MAP[NOW_R + DR[i]][NOW_C + DC[i]] != 'X'
				&& MAP[NOW_R + DR[i]][NOW_C + DC[i]] != '*'
				&& VISITED[NOW_R + DR[i]][NOW_C + DC[i]] == -1)
			{
				VISITED[NOW_R + DR[i]][NOW_C + DC[i]] = VISITED[NOW_R][NOW_C] + 1;
				if (NOW_R + DR[i] == END_R && NOW_C + DC[i] == END_C)
					break;
				MOVE.push({ NOW_R + DR[i], NOW_C + DC[i] });
			}
		}
		if (i != 4)
			break;
	}
	while (MOVE.size())
		MOVE.pop();
	while (WATER[0].size())
		WATER[0].pop();
	while (WATER[1].size())
		WATER[1].pop();
	if (VISITED[END_R][END_C] == -1)
		cout << "KAKTUS";
	else
		cout << VISITED[END_R][END_C];
}