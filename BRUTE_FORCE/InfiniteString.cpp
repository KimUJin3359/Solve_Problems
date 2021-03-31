#include <string>
#include <iostream>
using namespace std;

void swap_s(string &s, string &t)
{
	string temp = s;
	s = t;
	t = temp;
}

int main()
{
	string s, t;
	int i, j;
	int s_size, t_size;

	cin >> s >> t;
	s_size = s.size();
	t_size = t.size();

	// S is longer than T
	if (s_size < t_size)
	{
		swap_s(s, t);
		s_size = s.size();
		t_size = t.size();
	}
	// find common patter in T
	// abab -> ab, abab
	for (i = 1; i <= t_size; i++)
	{
		string temp;

		j = 0;
		temp = t.substr(0, i);
		while (t.find(temp, j) != string::npos)
		{
			// if a -> 'a'bab 0 == 0, a -> ab'a'b 2 != 1 -> non-pass
			// if ab -> 'ab'ab 0 == 0, ab'ab' 2 == 2 -> pass
			if (t.find(temp, j) != j)
				break;
			else
				j += i;
		}
		// all pass, repeat it to s
		if (j == t.size())
		{
			j = 0;
			while (s.find(temp, j) != string::npos)
			{
				if (s.find(temp, j) != j)
					break;
				else
					j += i;
			}
			if (j == s.size())
			{
				cout << 1;
				return (0);
			}
		}
	}
	cout << 0;
	return (0);
}