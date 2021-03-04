#include <stdio.h>
#pragma warning (disable : 4996)

int map[1000][1000];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int size;
int res;
int res_n = 987654321;

void dfs(int cnt, int index_r, int index_c, int index_r_origin, int index_c_origin)
{
	if (res < cnt)
	{
		res = cnt;
		res_n = map[index_r_origin][index_c_origin];
	}
	else if (res == cnt)
	{
		if (res_n > map[index_r_origin][index_c_origin])
			res_n = map[index_r_origin][index_c_origin];
	}
	for (int i = 0; i < 4; i++)
	{
		if (index_r + dr[i] >= 0 && index_r + dr[i] < size && index_c + dc[i] >= 0 && index_c + dc[i] < size)
		{
			if (map[index_r + dr[i]][index_c + dc[i]] == map[index_r][index_c] + 1)
				bfs(cnt + 1, index_r + dr[i], index_c + dc[i], index_r_origin, index_c_origin);
		}
	}
}

int main()
{
	int test_c;

	scanf("%d", &test_c);
	for (int test_n = 1; test_n <= test_c; test_n++)
	{
		res = 0;
		scanf("%d", &size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				scanf("%d", &map[i][j]);
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				dfs(1, i, j, i, j);
		}
		printf("#%d %d %d\n", test_c, res, res_n);
	}


	return (0);
}