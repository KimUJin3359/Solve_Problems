#include <iostream>
using namespace std;

int N;
//[0] for days
//[1] for values
int INPUT[16][2];
int DP[16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> INPUT[i][0] >> INPUT[i][1];
		DP[i] = 0;
	}
	for (int i = 0; i <= N; i++)
	{
		//이전에 나왔던 결과값을 받아옴
		if (i >= 1)
		{
			if (DP[i] < DP[i - 1])
				DP[i] = DP[i - 1];
		}
		//오늘 일을 했을 때, 결과값 비교
		if (i + INPUT[i][0] <= N)
		{
			if (DP[i + INPUT[i][0]] < DP[i] + INPUT[i][1])
				DP[i + INPUT[i][0]] = DP[i] + INPUT[i][1];
		}

	}
	cout << DP[N];
	return (0);
}