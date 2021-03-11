#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int> > MAX_POINT;
int M[8][8];	//map
bool V[8][8];	//visited
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int MAX;		//max value in map
int N, K;		//map size, max cutting
bool CUT;	

void DFS(int now_r, int now_c, int res)
{
	int next_r, next_c;

	res++;
	if (res > MAX)
		MAX = res;
	for (int i = 0; i < 4; i++)
	{
		next_r = now_r + dr[i];
		next_c = now_c + dc[i];
		//construction direct
		if ((next_r < 0 || next_r >= N) || (next_c < 0 || next_c >= N) || V[next_r][next_c] == true)
			continue;
		if (M[now_r][now_c] > M[next_r][next_c])
		{
			V[next_r][next_c] = true;
			DFS(next_r, next_c, res);
			V[next_r][next_c] = false;
		}
		else {
			if (M[next_r][next_c] - M[now_r][now_c] < K && !CUT)
			{
				int temp = M[next_r][next_c];

				CUT = true;
				V[next_r][next_c] = true;
				M[next_r][next_c] = M[now_r][now_c] - 1;
				DFS(next_r, next_c, res);
				CUT = false;
				V[next_r][next_c] = false;
				M[next_r][next_c] = temp;
			}
		}
	}
}

int main()
{
	int T;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		CUT = false;
		MAX = -1;
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> M[i][j];
				V[i][j] = false;
				if (MAX < M[i][j])
					MAX = M[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				if (M[i][j] == MAX)
					MAX_POINT.push_back({ i, j });
		}
		MAX = -1;
		for (int i = 0; i < MAX_POINT.size(); i++)
		{
			V[MAX_POINT[i].first][MAX_POINT[i].second] = true;
			DFS(MAX_POINT[i].first, MAX_POINT[i].second, 0);
			V[MAX_POINT[i].first][MAX_POINT[i].second] = false;
		}
		MAX_POINT.clear();
		cout << "#" << C << " " << MAX << endl;
	}
}