# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

// 插入若干个无序整数
void input(vector<int> &v) {
	cout<<"输入整数,-1停止: ";
	int x, key;
	cin>>x;
	if (x==-1) {
		return;
	} else {
		v.push_back(x);
		// 输入的第一个数作为判断较小或者较大的数的依据
		key = x;
	}

	while(true) {
		cin>>x;
		if (x==-1)
			return;
		if (x>key) {
			// 较大的数
			v.insert(v.end(), x);
		} else {
			// 较小的数
			v.insert(v.begin(), x);
		}
	}
}

// 比较函数, 建造小顶堆
bool compare(const int &a,const int &b) {
	return a > b ? true : false;
}

// 寻找中位数
void fun(vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	vector<int> min(v.begin()+(v.size()/2+1), v.begin()+v.size() );
	vector<int> max(v.begin(), v.begin()+(v.size()/2+1) );

	make_heap(min.begin(), v.end(), compare);
	make_heap(max.begin(), max.end());

	cout<<"小顶堆: "<<min[0]<<endl;
	cout<<"大顶堆: "<<max[0]<<endl;
	if (v.size()%2 != 0) {
		// size为奇数时, 中位数只有1个
		cout<<"中位数: "<<min[0]<<endl;
	} else {
		// size为偶数时, 中中位数有2个
		cout<<"中位数: "<<min[0]<<" "<<max[0]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> v;

	input(v);

	fun(v);

	return 0;
}