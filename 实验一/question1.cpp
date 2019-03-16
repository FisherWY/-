# include <iostream>
# include <cmath>
using namespace std;

#define length 8

int problem1_1(int array[], int x, int min, int max);
int problem1_2(int array[], int x, int min, int max);
int problem1_3(int array[], int x, int min, int max);
int problem1_4(int array[], int x, int min, int max);
int problem1_5(int array[], int x, int min, int max);
int problem1_6(int array[], int x, int min, int max);

int main(int argc, char const *argv[])
{
	int array[length], x, min, max;
	cout<<"输入整形数组(8个元素):";
	for (int i = 0; i < length; i++)
	{
		cin>>array[i];
	}
	cout<<"输入要查找的范围,元素:";
	cin>>min>>max>>x;

	cout<<"题目1-1:"<<problem1_1(array, x, min, max)<<endl;
	cout<<"题目1-2:"<<problem1_2(array, x, min, max)<<endl;
	cout<<"题目1-3:"<<problem1_3(array, x, min, max)<<endl;
	cout<<"题目1-4:"<<problem1_4(array, x, min, max)<<endl;
	cout<<"题目1-5:"<<problem1_5(array, x, min, max)<<endl;
	cout<<"题目1-6:"<<problem1_6(array, x, min, max)<<endl;

	return 0;
}

int problem1_1(int array[], int x, int min, int max)
{
	if ((min+1) >= max) {
		return -1;
	}

	int index = floor((min + max)/2);

	// cout<<"index: "<<index<<" min: "<<min<<" max: "<<max<<endl;
	// cout<<"array: "<<array[index]<<endl;

	if (array[index] == x && array[index-1]!=x) {
		return index;
	} else if (array[index] >= x) {
		return problem1_1(array, x, min, index);
	} else {
		return problem1_1(array, x, index, max);
	}
}

int problem1_2(int array[], int x, int min, int max)
{
	if ((min+1) >= max) {
		return -1;
	}

	int index = ceil((min + max)/2);

	// cout<<"index: "<<index<<" min: "<<min<<" max: "<<max<<endl;
	// cout<<"array: "<<array[index]<<endl;

	if (array[index] == x && array[index+1]!=x) {
		return index;
	} else if (array[index] <= x) {
		return problem1_2(array, x, index, max);
	} else {
		return problem1_2(array, x, min, index);
	}
}

int problem1_3(int array[], int x, int min, int max)
{
	if (min >= max) {
		return -1;
	}

	int index = (min + max)/2;

	// cout<<"index: "<<index<<" min: "<<min<<" max: "<<max<<endl;
	// cout<<"array: "<<array[index]<<endl;

	if (array[index] < x && array[index+1] >= x) {
		return index;
	} else if (array[index] < x) {
		return problem1_3(array, x, index, max);
	} else {
		return problem1_3(array, x, min, index);
	}
}

int problem1_4(int array[], int x, int min, int max)
{
	if (min >= max) {
		return -1;
	}

	int index = (min + max)/2;

	if (array[index] > x && array[index-1] <= x) {
		return index;
	} else if (array[index] > x) {
		return problem1_4(array, x, min, index);
	} else {
		return problem1_4(array, x, index, max);
	}
}

int problem1_5(int array[], int x, int min, int max)
{
	if (min >= max) {
		return -1;
	}

	int index = (min + max)/2;

	if (array[index] >= x && array[index-1] < x) {
		return index;
	} else if (array[index] > x) {
		return problem1_5(array, x, min, index);
	} else {
		return problem1_5(array, x, index, max);
	}
}

int problem1_6(int array[], int x, int min, int max)
{
	if (min >= max) {
		return -1;
	}

	int index = (min + max)/2;

	// cout<<"index: "<<index<<" min: "<<min<<" max: "<<max<<endl;
	// cout<<"array: "<<array[index]<<endl;

	if (array[index] <= x && array[index+1] > x) {
		return index;
	} else if (array[index] <= x) {
		return problem1_6(array, x, index, max);
	} else {
		return problem1_6(array, x, min, index);
	}
}