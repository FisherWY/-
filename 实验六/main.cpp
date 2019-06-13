# include <iostream>
# include <queue>
# include <vector>
using namespace std;

vector<float> w;
float bestw = 0.0;
int n;
queue<float> q;

void AddLiveNode(float wt, int i)
{
	if (i == n-1)
	{
		if (wt > bestw)
		{
			bestw = wt;
		}
	}
	else
	{
		q.push(wt);
	}
}

void MaxLoading(float c)
{
	// 分层标志
	q.push(-1);
	// 节点层数
	int i = 0;
	// 当前船的载重量, 目前的最优值
	float ew = 0;
	// 搜索子集空间树
	while(!q.empty()) 
	{
		// c1船装载当前货物
		if (ew + w[i] <= c)
		{
			AddLiveNode(ew + w[i], i);
		}
		// c1船不装载当前货物
		AddLiveNode(ew, i);
		// 取下一种情况
		ew = q.front();
		q.pop();
		// 当前层搜索完毕，添加标志结束本层
		if (ew == -1)
		{
			// 搜索完毕
			if (q.empty())
			{
				return;
			}
			q.push(-1);
			ew = q.front();
			q.pop();
			i++;
		}
	}
}

int main(int argc, char const *argv[])
{
	float c1, c2, s = 0.0;
	cin>>c1>>c2>>n;
	for (int i = 0; i < n; i++)
	{
		float x;
		cin>>x;
		w.push_back(x);
		s += x;
	}
	// 一艘船载满的情况
	if (s<=c1 || s<=c2)
	{
		cout<<"需要一艘船即可"<<endl;
		return 0;
	}
	// 不可能载满的情况
	if (s > c1 + c2)
	{
		cout<<"没有解决方案"<<endl;
		return 0;
	}
	MaxLoading(c1);
	// 输出结果
	if (s - bestw <= c2)
	{
		cout<<"第一艘船应该装: "<<bestw<<endl;
		cout<<"第二艘船应该装: "<<s-bestw<<endl;
	}
	else 
	{
		cout<<"没有解决方案"<<endl;
	}
	return 0;
}

