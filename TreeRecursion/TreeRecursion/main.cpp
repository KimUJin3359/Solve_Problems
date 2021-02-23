#include <iostream>
using namespace std;

int inorder[100001] = { -1, };
int postorder[100001] = { -1, };

//		    1
//	   2          3
//  4    5     6     7
// 8 9    11 12 13 14 15

// inorder(left - root - right)
// 8 4 9 2 5 11 1 12 6 13 3 7 14 15
// postorder(left - right - root)
// 8 9 4 11 5 2 12 13 6 7 14 15 3 1

void make_tree(int in_left, int in_right, int po_left, int po_right)
{
	int i_i;

	if (in_left > in_right || po_left > po_right)
		return;
	cout << postorder[po_right] << " ";
	for (i_i = 0; i_i < (in_right - in_left); i_i++)
	{
		if (inorder[in_left + i_i] == postorder[po_right])
			break;
	}
	make_tree(in_left, in_left + i_i - 1, po_left, po_left + i_i - 1);
	make_tree(in_left + i_i + 1, in_right, po_left + i_i, po_right - 1);
}

int main()
{
	int size;
	int index = 0;

	cin >> size;
	for (int i = 0; i < size; i++)
		cin >> inorder[i];
	for (int i = 0; i < size; i++)
		cin >> postorder[i];
	make_tree(0, size - 1, 0, size - 1);
	return (0);
}