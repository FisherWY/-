# include <iostream>
# include <vector>
using namespace std;

// C(a,b)形式
void fun(int a, int b)
{
	// 分子molecule，分母denominator
	vector<int> molecule;
	vector<int> denominator;

	int result = 1;

	for (int i = 1; i <= b; i++)
	{
		molecule.push_back(a-i+1);
		denominator.push_back(b-i+1);
	}

	for (int i = 0; i < denominator.size(); i++)
	{
		for (int j = 0; j < molecule.size(); j++)
		{
			if (molecule[j] % denominator[i] == 0)
			{
				molecule[j] = molecule[j] / denominator[i];
				denominator[i] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < molecule.size(); i++)
	{
		result *= molecule[i];
	}

	cout<<"计算结果: "<<result<<endl;

}

int main(int argc, char const *argv[])
{
	fun(7,3);
	return 0;
}