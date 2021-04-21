#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string solution(int n, int p[], size_t p_len, int c[], size_t c_len)
{
	int money[3] = { 100, 50, 25 };
	string answer;
	int sum = 0;
	int res = 0;
	int flag = 0; // 0 -> 100, 1 -> 50(one late), 2 -> 25(two late)
	double avg;

	for (int i = 0; i < n; i++)
	{
		sum += p[i];
		if (sum >= c[i])
		{
			sum -= c[i];
			res += c[i] * money[flag];
			flag = 0;
		}
		else
		{
			flag++;
			if (flag == 3)
				break;
		}
	}
	avg = res / n;
	avg = round(avg * 100) / 100;
	answer = to_string(avg);
	for (int i = 0; i < 4; i++)
		answer.pop_back();
	return (answer);
}

int main()
{
	int p[] = { 5, 4, 7, 2, 0, 6 };
	int c[] = { 4, 6, 4, 9, 2, 3 };
	cout << solution(6, p, 6, c, 6);
	return (0);
}