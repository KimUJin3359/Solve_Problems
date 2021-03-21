#include <iostream>
#include <queue>
#define MAX 200001
using namespace std;

int N, K;
int MAP[MAX] = { -1, };
queue<int> VISITED;

int main()
{
	int now;

	cin >> N >> K;
	if (N >= K)
	{
		cout << (N - K);
		return (0);
	}
	for (int i = 0; i < MAX; i++)
		MAP[i] = -1;
	MAP[N] = 0;
	VISITED.push(N);
	while (VISITED.size())
	{
		now = VISITED.front();
		VISITED.pop();
		if (now * 2 < MAX && MAP[now * 2] == -1)
		{
			MAP[now * 2] = MAP[now] + 1;
			if (now * 2 == K)
				break;
			VISITED.push(now * 2);
		}
		if (now - 1 >= 0 && MAP[now - 1] == -1)
		{
			MAP[now - 1] = MAP[now] + 1;
			if (now - 1 == K)
				break;
			VISITED.push(now - 1);
		}
		if (now + 1 < MAX && MAP[now + 1] == -1)
		{
			MAP[now + 1] = MAP[now] + 1;
			if (now + 1 == K)
				break;
			VISITED.push(now + 1);
		}
	}
	cout << MAP[K];
	return (0);
}