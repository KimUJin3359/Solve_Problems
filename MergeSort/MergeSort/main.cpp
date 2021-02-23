#include <iostream>

using namespace std;

int arr[7] = { 38, 27, 43, 3, 9, 82, 10 };
int buf[7];

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int index_l = left;
	int index_r = mid + 1;
	int index_b = left;
	
	while (index_l <= mid && index_r <= right)
	{
		if (arr[index_l] < arr[index_r])
			buf[index_b++] = arr[index_l++];
		else
			buf[index_b++] = arr[index_r++];
	}
	while (index_l <= mid)
		buf[index_b++] = arr[index_l++];
	while (index_r <= right)
		buf[index_b++] = arr[index_r++];
	for (int i = 0; i <= (right - left); i++)
		arr[left + i] = buf[left + i];
}

void partition(int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main()
{
	partition(0, 6);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	return (0);
}