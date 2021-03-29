#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > PQ;
int N;

int main()
{
	int num;
	int size = 0;
	int res = 1;
	int flag = 0;
	bool dup = false;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		PQ.push(num);
	}
	while(PQ.size())
	{
		// 처음 값은 하나만 존재하든 둘이 존재하든 A, B그룹에 둘다 포함될 수 있으므로 * 2
		if (size == 0 && PQ.top() == size)
		{
			res *= 2;
			PQ.pop();
		}
		// 그 외의 값은 이미 앞에 나온 값에 이어져 붙음
		else if (PQ.top() == size)
			PQ.pop();
		// 연속된 숫자가 아닐 경우 그룹을 정할 수 없음
		else
			break;

		// 앞 까지 0, 0 / 1, 1 / 잘 오다가 마지막만 하나가 나올 경우 A, B그룹 둘다 포함될 수 있으므로 * 2
		// 0, 0 / 1, 1 / 2, 3, 4 의 경우도 포함
		if (dup && size != 0 && PQ.size() == 0)
		{
			res *= 2;
			break;
		}
		// 0 만 입력받았을 때, 0, 1, 2, 3... 한 줄로만 나열될 때 그냥 종료
		else if (PQ.size() == 0)
			break;

		// 0, 0 / 1, 1 / 받다가 마지막 값이 아님에도 하나의 값만 나왔을 경우 단일 입력으로 바꿔줌
		// 0, 0 / 1, 1 / 2 / 3 같은 경우
		if (flag == 1 && PQ.top() != size)
			flag = 0;
		// 0, 1, 2, 3 .. 한줄로 받다가 두개의 값을 입력받을 경우 종료
		// 0 / 1 / 2 / 3, 3 같은 경우
		else if (size != 0 && flag == 0 && PQ.top() == size)
			break;
		// 0, 0 / 1, 1 같은 경우
		// 2 * 2 가능 한 개씩 중복이 추가될 수록 경우의 수는 * 2
		else if (size != 0 && PQ.top() == size)
		{
			flag = 1;
			dup = true;
			res *= 2;
			PQ.pop();
		}
		// 첫 번째 조건에서 * 2를 이미 해줌
		else if (size == 0 && PQ.top() == size)
		{
			flag = 1;
			dup = true;
			PQ.pop();
		}
		size++;
	}
	if (PQ.size())
		cout << 0;
	else
		cout << res;
}