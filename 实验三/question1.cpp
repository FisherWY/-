# include <iostream>
using namespace std;

void fun()
{
	int n, count=0;
	cout<<"输入n: ";
	cin>>n;
	for (int i = 0; i <= n/5; i++)
	{
		for (int j = 0; j <= (n-(5*i))/2; j++)
		{
			count++;
			int k = n - (5*i) - (2*j);
			cout<<i<<" * 5 + "<<j<<" * 2 + "<<k<<" = "<<n<<endl;
		}
	}
	cout<<"一共有 "<<count<<" 种兑换方法"<<endl;
}

int main(int argc, char const *argv[])
{
	fun();
	return 0;
}