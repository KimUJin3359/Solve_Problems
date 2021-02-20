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
		int **sum;

		cin >> m_len >> f_len;
		map = new int*[m_len];
		for (int i = 0; i < m_len; i++)
			map[i] = new int[m_len];
		sum = new int*[(m_len - f_len + 1)];
		for (int i = 0; i < m_len - f_len + 1; i++)
			sum[i] = new int[m_len - f_len + 1];

		for (int i = 0; i < m_len; i++)
		{
			for (int j = 0; j < m_len; j++)
			{
				cin >> map[i][j];
				if (0 <= j && j <=  )
			}
		}

		for (int i = 0; i < m_len; i++)
			delete map[i];
		delete map;

	
	}
}