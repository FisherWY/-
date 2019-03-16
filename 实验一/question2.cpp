# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

# define length 10

void find(int array[])
{
	int min = array[0];
	int max = array[0];
	int count = 0;
	for (int i = 1; i < length; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		if (array[i] > max)
		{
			max = array[i];
		}
		++count;
	}

	cout<<"min: "<<min<<endl;
	cout<<"max: "<<max<<endl;
	cout<<"count: "<<count<<endl;
}

int main(int argc, char const *argv[])
{
	int array[length];
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < length; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;

	find(array);

	return 0;
}