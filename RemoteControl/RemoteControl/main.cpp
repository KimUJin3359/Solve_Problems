/* 어려웠던 점
1. push button의 종료 조건 (처음에 num <= 5000000으로 설정해서 num이 5000000일 떄 num보다 크면서 결과값이 작은 경우를 생각하지 못했음)
2. 0의 처리 (0만 누를 수 있을 때, 10을 만들려면 11번을 눌러야 되는데 처음 짠 로직에서는 10이 떴음 cnt != 0 조건을 추가함으로써 해결)
3. 0의 무한반복 (num == 0 && cnt > 1을 추가함으로써 해결)
4. button[10] = { true, }로 설정해뒀는데 button[0]에만 true값, 나머지는 전부 false값이 들어가 있었음
5. 위의 경우로 집중을 하지 못해 초기화의 위치를 잘 못 잡아줌
6. ABS(x) (x > 0) ? x : -x 를 했는데 9999 및 5457에서 정상동작 하지 않음
4, 6번 문제 원인 분석하기
*/

#include <stdio.h>
#pragma warning(disable : 4996)
#define SIZE 1000000

int find, res;
bool button[10];

void push_button(int num, int cnt)
{
	if (num == 0 && cnt > 1)
		return;
	if (num > SIZE)
		return;
	if (cnt != 0 && res > cnt + ((find > num) ? find - num : num - find))
		res = cnt + ((find > num) ? find - num : num - find);
	for (int i = 0; i < 10; i++)
	{
		if (button[i])
			push_button((num * 10) + i, cnt + 1);
	}
}

int main()
{
	int rep, input;

	//initialize
	for (int i = 0; i < 10; i++)
		button[i] = true;
	scanf("%d", &find);
	scanf("%d", &rep);
	for (int i = 0; i < rep; i++)
	{
		scanf("%d", &input);
		button[input] = false;
	}

	//for only up, down button
	res = ((find > 100) ? find - 100 : 100 - find);

	//push button
	push_button(0, 0);

	printf("%d", res);
	return (0);
}