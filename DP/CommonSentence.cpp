#include <iostream>
#include <string>
using namespace std;

string N, M;
int COM[4000][4000];
int MAX;

int main()
{
	int size_n, size_m;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	// Initialize
	size_n = N.size();
	size_m = M.size();
	MAX = 0;
	for (int i = 0; i < size_n; i++)
	{
		for (int j = 0; j < size_m; j++)
			COM[i][j] = 0;
	}
	for (int i = 0; i < size_n; i++)
	{
		for (int j = 0; j < size_m; j++)
		{
			// first character of string
			if (i == 0 || j == 0)
			{
				if (N[i] == M[j])
				{
					COM[i][j] = 1;
					if (MAX < COM[i][j])
						MAX = COM[i][j];
				}
			}
			// else
			else
			{
				if (N[i] == M[j])
				{
					COM[i][j] = COM[i - 1][j - 1] + 1;
					if (MAX < COM[i][j])
						MAX = COM[i][j];
				}
			}
		}
	}
	cout << MAX;
	return(0);
}