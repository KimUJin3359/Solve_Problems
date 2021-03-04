#include <iostream>
#include <string>
using namespace std;

int main()
{
	int C;
	string str;
	
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		cin >> str;
		for (int i = 2; i <= 10; i++)
		{
			string sub = str.substr(i);
			int num = 0;
			int flag = 1;

			while (str.find(sub, num) != string::npos)
			{
				if (num != str.find(sub, num))
				{
					flag = 0;
					break;
				}
				num += i;
			}
			if (flag == 1)
			{
				cout << "#" << N << " " << i << endl;
				break;
			}
		}
	}
	return (0);
}