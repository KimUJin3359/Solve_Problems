#include <iostream>

using namespace std;
int main()
{
	int C;

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		char str[5][15] = { 0, };
		char res[75] = { 0, };
		int index = 0;

		for (int i = 0; i < 5; i++)
			cin >> str[i];
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (str[j][i] != 0)
					res[index++] = str[j][i];
			}
		}
		cout << "#" << N << " " << res << endl;
	}
}