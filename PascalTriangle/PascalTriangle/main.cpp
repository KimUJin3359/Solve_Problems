#include <iostream>
using namespace std;

int **result;

void print(int input, int cnt)
{
	if (cnt > input)
		return;
	for (int i = 0; i < cnt; i++)
		cout << result[(cnt - 1)][i] << " ";
	cout << endl;
	print(input, cnt + 1);
}

int main()
{
	int C;
	int input;

	cin >> C;
	result = new int*[10];
	for (int i = 0; i < 10; i++)
		result[i] = new int[(i + 1)];
	result[0][0] = 1;
	result[1][0] = 1; result[1][1] = 1;
	for (int i = 2; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				result[i][j] = 1;
			else
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
	}
	for (int N = 1; N <= C; N++)
	{
		cin >> input;
		cout << "#" << N << endl;
		print(input, 1);
	}
	for (int i = 0; i < 10; i++)
		delete result[i];
	delete result;
	return (0);
}