# include <iostream>
using namespace std;

int AdjustArray(int a[], int left, int right) {
	int i = left, j = right;
	int x = a[i];

	while (i < j) {
		// 从右向左寻找，填左边坑
		while (i<j && a[j]>=x) {
			j--;
		}
		if (i < j) {
			a[i] = a[j];
			i++;
		}

		// 从左向右寻找，填右边坑
		while (i<j && a[i]<x) {
			i++;
		}
		if (i < j) {
			a[j] = a[i];
			j--;
		}
	}

	// 中间坑位，填入x
	a[i] = x;
	return i;
}

void QuickSort(int a[], int left, int right) {
	if (left < right)
	{
		int i = AdjustArray(a, left, right);
		// 递归调用，整理左边
		QuickSort(a, left, i-1);
		// 递归调用，整理右边
		QuickSort(a, i+1, right);
	}
}

int main(int argc, char const *argv[])
{
	int a[10] = {32, 12, 45, 65, 34, 2, 4, 76, 99, 0};
	QuickSort(a, 0, 9);
	return 0;
}