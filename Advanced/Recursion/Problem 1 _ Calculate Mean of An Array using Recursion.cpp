#include<iostream>
using namespace std;

int length(int[]);

/*
//according to requirement of function parameters in given question
there will just one parameters (int a[]), so thats why in first recursive
it will find the length from length function.
*/

double calMean(int a[], int len = 0) {
	/*
		because this is recursive function so on first time function call this condition will execute
		otherwise it didn't execute. 
	*/
	if (len == 0) {
		len = length(a);   //find length 
	}
	if (len == 1) {
		return a[len - 1];
	}
	else {
		return (calMean(a, len - 1) * (len - 1) + a[len - 1]) / len;
	}
}

int main() {
	int arr[] = { 10, 12, 14, 16, 18 };
	cout << "Mean: " << calMean(arr) << endl;   //function call
	system("pause>0");
}

int length(int a[]) {
	unsigned int count = 0;
	while (a[count] >= 0) //find length only unsigned numeric data
	{
		count++;
	}
	return count;
}



