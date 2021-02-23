#include <iostream>
using namespace std;

int x[10];
int y[10];
bool visited[10];
int visit;
int res;
int now_x, now_y;
int des_x, des_y;

void initialize()
{
	for (int i = 0; i < 10; i++)
	{
		x[i] = -1;
		y[i] = -1;
		visited[i] = false;
	}
}

void find_map(int c_x, int c_y, int len, int cnt)
{
	if (cnt == visit)
	{
		len += (des_x > c_x) ? des_x - c_x : c_x - des_x;
		len += (des_y > c_y) ? des_y - c_y : c_y - des_y;
		if (len < res)
			res = len;
		return;
	}
	if (len > res)
		return;
	for (int i = 0; i < visit; i++)
	{
		int len_b = len;

		if (visited[i] == false)
		{
			len_b += (c_x > x[i]) ? c_x - x[i] : x[i] - c_x;
			len_b += (c_y > y[i]) ? c_y - y[i] : y[i] - c_y;
			visited[i] = true;
			find_map(x[i], y[i], len_b, cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	int C;

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		initialize();
		res = 2147483647;
		cin >> visit;
		cin >> now_x >> now_y;
		cin >> des_x >> des_y;
		for (int i = 0; i < visit; i++)
			cin >> x[i] >> y[i];
		find_map(now_x, now_y, 0, 0);
		cout << "#" << N << " " << res << endl;
	}
}