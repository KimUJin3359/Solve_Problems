#include <iostream>
using namespace std;

int len = 10;
int arr[10] = { 3, 5, 1,4,2, 8, 9, 13, 0, 15 };
//2 5 1 3 4
//2 1 5 3 4

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(int left, int right)
{
	int pivot = arr[left];
	int less = left + 1;
	int more = right;

	if (left >= right)
		return;
	while (less <= more)
	{
		while (less <= right && arr[less] < pivot)
			less++;
		while (more >= less && arr[more] > pivot)
			more--;
		if (less < more)
			swap(arr[less], arr[more]);
		else
			swap(arr[left], arr[more]);
	}
	quickSort(left, more - 1);
	quickSort(more + 1, right);
}

int main()
{
	quickSort(0, len - 1);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	return (0);
}