#include <iostream>
#define SIZE 1001
using namespace std;

int RES = 0;
int N;
int ROME[4] = { 1, 5, 10, 50 };
bool NUM[SIZE];

void DFS(int cnt, int res, int bef_s)
{
	if (!NUM[res] && cnt == N)
	{
		NUM[res] = true;
		RES++;
		return;
	}
	else if (cnt == N)
		return;
	for (int i = bef_s; i < 4; i++)
		DFS(cnt + 1, res + ROME[i], i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < SIZE; i++)
		NUM[i] = false;
	DFS(0, 0, 0);
	cout << RES;
	return (0);
}