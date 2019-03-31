# include <iostream>
using namespace std;

void fun3()
{
	int n, a[1001], maxArea=0;

	cout<<"输入n: ";
	cin>>n;
	cout<<"输入高度: ";
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}

	// i表示跨度
	for (int i = 1; i <= n; i++)
	{
		// 遍历数组
		for (int j = 0; j <= n-i; j++)
		{
			int minHeight = a[j];
			// 找出一个跨度中，高度最小的一栋
			for (int k = 0; k < i; k++)
			{
				if (a[j+k]<minHeight)
				{
					minHeight = a[j+k];
				}
			}
			// 计算矩形面积
			int area = minHeight * i;
			if (area > maxArea)
			{
				maxArea = area;
			}
		}
	}

	cout<<"maxArea: "<<maxArea<<endl;
}

void fun3_1()
{
	int n, a[1001], maxArea=0;

	cout<<"输入n: ";
	cin>>n;
	cout<<"输入高度: ";
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int area = a[i];

		// 向前找矩形，直到找到的矩形比当前矩形小
		for (int j = i-1; j >= 0; j--)
		{
			if (a[j] >= a[i]) {
				area += a[i];
			} else {
				break;
			}
		}

		// 向后找矩形，直到找到的矩形比当前矩形小
		for (int j = i+1; j < n; j++)
		{
			if (a[j] >= a[i]) {
				area += a[i];
			} else {
				break;
			}
		}

		if (area > maxArea)
		{
			maxArea = area;
		}
	}

	cout<<"maxArea: "<<maxArea<<endl;
}

int main(int argc, char const *argv[])
{
	fun3_1();
	return 0;
}