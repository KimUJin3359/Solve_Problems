#include <iostream>
using namespace std;

bool map[15][15];

int main()
{
	int m_len, f_len;
	int C;

	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		int res = 0;

		cin >> m_len >> f_len;
		for (int i = 0; i < m_len; i++)
		{
			for (int j = 0; j < m_len; j++)
				cin >> map[i][j];
		}
		//find row
		for (int i = 0; i < m_len; i++)
		{
			for (int j = 0; j < m_len; j++)
			{
				int size = 0;

				while (map[i][j] == true && j < m_len)
				{
					j++;
					size++;
				}
				if (size == f_len)
					res++;
			}
		}
		//find col
		for (int i = 0; i < m_len; i++)
		{
			for (int j = 0; j < m_len; j++)
			{
				int size = 0;

				while (map[j][i] == true && j < m_len)
				{
					j++;
					size++;
				}
				if (size == f_len)
					res++;
			}
		}
		cout << "#" << N << " " << res << endl;
	}
	return (0);
}