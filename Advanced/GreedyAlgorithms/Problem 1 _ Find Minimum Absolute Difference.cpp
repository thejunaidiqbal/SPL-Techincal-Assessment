#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int length(int a[]) {  //according to function parameters requirement there is only one parameter for findAbsMin(a[]) function.
	int count = 0;
	while (a[count]>=0)
	{
		count++;
	}
	return count;
}

int findAbsMin(int a[]) {      //main function
	unsigned int len = length(a);  // find length
	int absMin = 0;
	if (len != 0) {
		absMin = abs(a[len-1] - a[0]);
	}
	for (int i = 0; i < len; i++)
	{
		absMin = min(absMin, abs(a[i] - a[i + 1]));
	}
	return absMin;
}

int main() {
	int a[] = { 10, 12, 13, 15, 10 };
	cout << "Minimum Possible: " << findAbsMin(a) << endl;  

	system("pause>0");
}