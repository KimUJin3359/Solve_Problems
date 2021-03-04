#include <iostream>
using namespace std;

int price[4];
int date[12];
int min_v;

void dfs(int month, int res)
{
	if (month >= 12)
	{
		if (min_v > res)
			min_v = res;
		return;
	}
	if (date[month] == 0)
		dfs(month + 1, res);
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
				dfs(month + 1, res + (date[month] * price[i]));
			else if (i == 1)
			{
				if (date[month] * price[0] > price[i])
					dfs(month + 1, res + price[i]);
			}
			else if (i == 2)
				dfs(month + 3, res + price[i]);
			else
			{
				if (month == 0)
					dfs(month + 12, res + price[i]);
			}
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
		min_v = 987654321;
		for (int i = 0; i < 4; i++)
			cin >> price[i];
		for (int i = 0; i < 12; i++)
			cin >> date[i];
		dfs(0, 0);
		cout << "#" << N << " " << min_v << endl;
	}
}