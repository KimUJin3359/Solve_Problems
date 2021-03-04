#include <stdio.h>
#pragma warning(disable :4996)

double map[100][100];
bool visited[100];
int size;
double res = 0.0;

void print_map()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf( "%.3lf ", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void initialize()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			map[i][j] = 0.0;
		visited[i] = false;
	}
}

void dfs_greedy(int cnt, double result)
{
	if (cnt == size)
	{
		if (res < result)
			res = result;
		return;
	}
	double max_v = 0;
	int max_i = 0;
	for (int i = 0; i < size; i++)
	{
		if (visited[i] == false)
		{
			if (map[cnt][i] >= max_v)
			{
				max_v = map[cnt][i];
				max_i = i;
			}
		}
	}
	visited[max_i] = true;
	dfs_greedy(cnt + 1, result * map[cnt][max_i]);
	visited[max_i] = false;
}

void dfs(int cnt, double result)
{
	if (cnt == size)
	{
		if (res < result)
			res = result;
		return;
	}
	if (result < res)
		return;
	for (int i = 0; i < size; i++)
	{	
		if (visited[i] == false)
		{
			visited[i] = true;
			dfs(cnt + 1, result * map[cnt][i]);
			visited[i] = false;
		}
	}
}

int main()
{
	int test_c;
	int num;

	scanf("%d", &test_c);
	for (int test_n = 1; test_n <= test_c; test_n++)
	{
		res = 0.0;
		initialize();
		scanf("%d", &size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				scanf("%d", &num);
				map[i][j] = (0.01 * num);
			}
		}
		dfs_greedy(0, 1.0);
		dfs(0, 1.0);
		res *= 100;
		printf("#%d %.6lf\n", test_n, res);
	}
}