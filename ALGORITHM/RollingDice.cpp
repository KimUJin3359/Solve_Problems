#include <iostream>
#include <deque>
using namespace std;

int MAP[20][20];
int N, M;
int now_r, now_c;

int INS[1000];
int K;

//top is index 1
deque<int> NS;
//top is index 1
deque<int> EW;
int now_t = 0, now_b = 0;
// 1 : east, 2 : west, 3 : north, 4 : south
int dr[5] = { 0, 0, 0, -1, 1 };
int dc[5] = { 0, 1, -1, 0, 0 };

void roll_dice(int dir)
{
	int temp;

	if (dir == 1) 
	{
		temp = EW[0];
		EW.pop_front();
		EW.push_back(NS[3]);
		NS[1] = EW[1];
		NS[3] = temp;
	}
	else if (dir == 2) 
	{
		temp = EW[2];
		EW.pop_back();
		EW.push_front(NS[3]);
		NS[1] = EW[1];
		NS[3] = temp;
	}
	else if (dir == 3)
	{
		temp = NS[3];
		NS.pop_back();
		NS.push_front(temp);
		EW[1] = NS[1];
	}
	else if (dir == 4)
	{
		temp = NS[0];
		NS.pop_front();
		NS.push_back(temp);
		EW[1] = NS[1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> now_r >> now_c >> K;
	//initialize MAP, INSTRUCTION, DICE
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];
	}
	for (int i = 0; i < K; i++)
		cin >> INS[i];
	for (int i = 0; i < 4; i++)
		NS.push_back(0);
	for (int i = 0; i < 3; i++)
		EW.push_back(0);
	for (int i = 0; i < K; i++)
	{
		int next_r = now_r + dr[INS[i]];
		int next_c = now_c + dc[INS[i]];

		if ((next_r >= 0 && next_r < N) &&
			(next_c >= 0 && next_c < M))
		{
			roll_dice(INS[i]);
			if (MAP[next_r][next_c] == 0)
				MAP[next_r][next_c] = NS[3];
			else
			{
				NS[3] = MAP[next_r][next_c];
				MAP[next_r][next_c] = 0;
			}
			cout << NS[1] << endl;
			now_r = next_r;
			now_c = next_c;
		}
	}
	return (0);
}