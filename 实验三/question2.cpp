# include <iostream>
# include <vector>
using namespace std;

void fun2()
{
	int minSize, maxSize, n, fishSize[51], min, max;

	cout<<"fish's minSize and maxSize: ";
	cin>>minSize>>maxSize;
	cout<<"fish number n: ";
	cin>>n;
	cout<<"fish's size: ";
	for (int i = 0; i < n; i++) {
		cin>>fishSize[i];
	}

	if (n>0) {
		min = fishSize[0]*2;
		max = fishSize[0]*10;
	}

	for (int i = 1; i < n; i++) {
		if (fishSize[i]*2 < min) {
			min = fishSize[i]*2;
		}
		if (fishSize[i]*10 > max) {
			max = fishSize[i]*10;
		}
	}

	cout<<"有这么多种: "<<maxSize-minSize-(max-min)<<endl;
}

int main(int argc, char const *argv[])
{
	fun2();
	return 0;
}