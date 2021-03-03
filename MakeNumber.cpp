#include <iostream>
using namespace std;

int num, ind, res_max, res_min;
int sign[12];
bool checked[12];
int number[12];

void dfs(int idx, int cal)
{
	int temp;

	if (idx == num)
	{
		if (res_max < cal)
			res_max = cal;
		if (res_min > cal)
			res_min = cal;
		return;
	}
	for (int i = 0; i < num - 1; i++)
	{
		if (checked[i] == false)
		{
			temp = cal;
			checked[i] = true;
			if (sign[i] == 0)
				temp += number[idx];
			else if (sign[i] == 1)
				temp -= number[idx];
			else if (sign[i] == 2)
				temp *= number[idx];
			else
				temp /= number[idx];
			dfs(idx + 1, temp);
			checked[i] = false;
			while (i < num - 2 && sign[i] == sign[i + 1])
				i++;
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
		ind = 0;
		res_max = -987654321;
		res_min = 987654321;
		cin >> num;
		for (int i = 0; i < 4; i++)
		{
			int s;

			cin >> s;
			for (int j = 0; j < s; j++)
			{
				checked[ind] = false;
				sign[ind++] = i;
			}
		}
		for (int i = 0; i < num; i++)
			cin >> number[i];
		dfs(1, number[0]);
		cout << "#" << N << " " << (res_max - res_min) << endl;
	}
}