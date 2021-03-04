#include <iostream>
#include <deque>
#define MAX 987654321
using namespace std;

int res;
int len;
int whole;
bool visited[16];
int M[16][16];

void DFS(int cnt, int index_f)
{
	if (cnt == len / 2)
	{
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (visited[i] == false && visited[j] == false)
					sum1 += M[i][j];
				if (visited[i] == true && visited[j] == true)
					sum2 += M[i][j];
			}
		}
		sum1 = (sum1 > sum2) ? (sum1 - sum2) : (sum2 - sum1);
		if (sum1 < res)
			res = sum1;
		return;
	}
	for (int i = 0; i < len; i++)
	{
		if (visited[i] == false && index_f < i)
		{
			visited[i] = true;
			DFS(cnt + 1, i);
			visited[i] = false;
		}
	}
}

int main()
{
	int C;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		cin >> len;
		res = MAX;
		for (int i = 0; i < len; i++)
		{
			visited[i] = false;
			for (int j = 0; j < len; j++)
				cin >> M[i][j];
		}
		DFS(0);
		cout << "#" << N << " " << res << endl;
	}
	return (0);
}