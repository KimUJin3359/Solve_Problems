#include <iostream>
using namespace std;

int A, B;
int CNT = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	while (B >= A)
	{
		if (A == B)
			break;
		else
		{
			if (B % 10 == 1)
				B /= 10;
			else if (B % 2 == 0)
				B /= 2;
			else
				break;
		}
		CNT++;
	}
	if (B == A)
		cout << CNT;
	else
		cout << -1;
	return (0);
}