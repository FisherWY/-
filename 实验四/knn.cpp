# include <iostream>
# include <cmath>
# include <vector>
# include <map>
using namespace std;

// 精度K
int K = 3;

struct Data
{
	// x,y坐标
	float x,y;
	// 欧式距离
	float distance;
	// 数据集合属性
	char type;
};

// 训练集存放
vector<Data> v;
// 计算结果存放
map<char, int> result;

// sort的比较函数
bool compare(Data d1, Data d2)
{
	return d1.distance<d2.distance;
}

void knn(Data data)
{
	for (int i = 0; i < v.size(); i++)
	{
		// 计算欧式距离
		v[i].distance = sqrt(pow((data.x-v[i].x),2) + pow((data.y-v[i].y),2));
	}

	sort(v.begin(), v.end(), compare);

	cout<<"最接近的"<<K<<"个点的距离和属于的集合: "<<endl;
	for (int i = 0; i < K; i++)
	{
		cout<<"dis: "<<v[i].distance<<" type: "<<v[i].type<<endl;
		result[v[i].type]++;
	}

	int max = 0;
	char maxType = 'a';
	for (map<char,int>::iterator x=result.begin(); x!=result.end(); x++) 
	{
		if (x->second > max)
		{
			max = x->second;
			maxType = x->first;
		}
	}

	cout<<"该点应该归为: "<<maxType<<" 类"<<endl;
}

void init()
{
	// 训练集构建
	for (int i = 0; i < 5; i++)
	{
		Data d;
		d.x = 0.0;
		d.y = 0.0 + 0.1;
		d.type = 'a';
		v.push_back(d);
	}

	for (int i = 0; i < 5; i++)
	{
		Data d;
		d.x = 2.0;
		d.y = 0.0 + 0.1;
		d.type = 'b';
		v.push_back(d);
	}

	for (int i = 0; i < 5; i++)
	{
		Data d;
		d.x = 4.0;
		d.y = 0.0 + 0.1;
		d.type = 'c';
		v.push_back(d);
	}

	// 结果集构建
	result['a'] = 0;
	result['b'] = 0;
	result['c'] = 0;
}

int main(int argc, char const *argv[])
{
	init();

	// 用户输入
	Data input;
	cout<<"输入坐标x,y:";
	cin>>input.x>>input.y;
	knn(input);
	return 0;
}