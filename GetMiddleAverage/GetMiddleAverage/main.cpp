#include <iostream>

using namespace std;
int main()
{
	int C;
	int num[10];

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		int max = -1;
		int min = 10001;
		int sum = 0;
		int res;

		for (int i = 0; i < 10; i++)
		{
			cin >> num[i];
			if (max < num[i])
				max = num[i];
			if (min > num[i])
				min = num[i];
		}
		for (int i = 0; i < 10; i++)
		{
			if (num[i] != max && num[i] != min)
				sum += num[i];
		}
		if (sum % 8 >= 4)
			res = (sum / 8) + 1;
		else
			res = (sum / 8);
		cout << "#" << N << " " << res << endl;
	}
	return (0);
}