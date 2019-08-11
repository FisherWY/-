#include <iostream>
using namespace std;

void MergeArray(int a[], int first, int mid, int last, int temp[]) {
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}

	while (i <= m) {
		temp[k++] = a[i++];
	}

	while (j <= n) {
		temp[k++] = a[j++];
	}

	for (int i = 0; i < k; i++) {
		a[first + i] = temp[i];
	}
}

void MergeSort(int a[], int first, int last, int temp[]) {
	if (first < last) {
		int mid = (first + last) / 2;
		// 左边分割字数组
		MergeSort(a, first, mid, temp);
		// 右边分割字数组
		MergeSort(a, mid, last, temp);
		// 合并左右数组
		MergeArray(a, first, mid, last, temp);
	}
}

bool MergeMain(int a[], int n) {
	int *p = new int[n];
	if (p == NULL) {
		return false;
	}
	MergeSort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

int main(int argc, char const *argv[])
{
	int a[10] = {5, 7, 6, 32, 65, 123, 2, 1, 21, 12};
	MergeMain(a, 10);
	return 0;
}