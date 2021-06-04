#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, S;
int FIND = 0;
bool MAP[1001][1001];
bool VISIT[1001];
queue<int> BFS;
queue<int> BFS_ans;

int MAX = 0;

// DFS는 기본적으로 완전 탐색
// DFS 탐색이 가능한 모든 경우를 볼 때에만 이 전의 값을 새로 초기화 해주고 다음 경우를 봄
// 이러한 문제 처럼 하나의 DFS만 볼 경우 보이는 대로 접근만 해주면 됨
void DFS(int now)
{
	if (FIND)
		return ;
	for (int i = 1; i <= N; i++)
	{
		if (MAP[now][i] && !VISIT[i])
		{
			VISIT[i] = true;
			printf("%d ", i);
			DFS(i);
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &S);
	// Init
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			MAP[i][j] = 0;
		VISIT[i] = 0;
	}
	// Input Node
	for (int i = 0; i < M; i++)
	{
		int n1, n2;

		scanf("%d %d", &n1, &n2);
		MAP[n1][n2] = 1;
		MAP[n2][n1] = 1;
	}
	// VISIT - BFS
	BFS.push(S);
	BFS_ans.push(S);
	VISIT[S] = 1;
	MAX++;
	while (BFS.size())
	{
		int now = BFS.front();

		BFS.pop();
		for (int i = 1; i <= N; i++)
		{
			if (MAP[i][now] && !VISIT[i])
			{
				MAX++;
				VISIT[i] = 1;
				BFS.push(i);
				BFS_ans.push(i);	
			}
		}
	}	
	// VISIT - DFS
	for (int i = 1; i <= N; i++)
		VISIT[i] = 0;
	VISIT[S] = 1;
	printf("%d ", S);
	DFS(S);
	printf("\n");
	// BFS PRINT
	while (BFS_ans.size())
	{
		printf("%d ", BFS_ans.front());
		BFS_ans.pop();
	}
	return (0);
}
