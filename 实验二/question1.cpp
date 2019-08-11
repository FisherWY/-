# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

# define length 10

// 生成随机数组
void mkrand(int *a) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		a[i] = rand() % 100 + 1;
	}
}

// 比较函数, 建造小顶堆
bool compare(int a, int b) {
	return a > b ? true : false;
}

int main(int argc, char const *argv[])
{
	int *a = new int[length];
	int *b = new int[length];
	int *k = new int(0);
	mkrand(a);
	mkrand(b);
	cout<<"生成的随机数组a："<<endl;
	for (int i = 0; i < length; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	cout<<"生成的随机数组b："<<endl;
	for (int i = 0; i < length; i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;

	// 排序
	sort(b, b+length);

	// 创建容器
	vector<int> v(a, a+length);
	// 创建堆
	make_heap(v.begin(), v.end(), compare);

	cout<<"要出堆的次数: ";
	cin>>*k;

	if (*k>=length) {
		cout<<"非法输入"<<endl;
	} else {
		for (int i = 0; i < *k; i++)
		{
			pop_heap(v.begin(), v.end(), compare);
			v.pop_back();
		}
		cout<<"mina: "<<v.front()<<endl;
	}

	cout<<"minb: "<<b[*k]<<endl;

	delete k;
	delete[] a;
	delete[] b;
	return 0;
}