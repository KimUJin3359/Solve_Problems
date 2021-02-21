#include <iostream>

using namespace std;
int main()
{
	int C;
	int m_len, f_len;

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		int **map;
		int max = -1;
		int sum = 0;

		cin >> m_len >> f_len;
		map = new int*[m_len];
		for (int i = 0; i < m_len; i++)
			map[i] = new int[m_len];
		for (int i = 0; i < m_len; i++)
		{
			for (int j = 0; j < m_len; j++)
				cin >> map[i][j];
		}
		for (int i = 0; i <= m_len - f_len; i++)
		{
			for (int j = 0; j <= m_len - f_len; j++)
			{
				sum = 0;
				for (int k = 0; k < f_len; k++)
				{
					for (int t = 0; t < f_len; t++)
						sum += map[i + k][j + t];
				}
				if (sum > max)
					max = sum;
			}
		}
		for (int i = 0; i < m_len; i++)
			delete map[i];
		delete map;
		cout << "#" << N << " " << max << endl;
	}
}