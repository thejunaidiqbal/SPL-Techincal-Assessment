#include<iostream>
using namespace std;

int Memo(int arr[], int num) {
	if (num == 0 || num == 1) {
		return 1;
	}
	else {
		return (arr[num - 2] + arr[num - 1]);
	}
}


int* fibonnaci(int num) {
	static int* fib = new int[num + 1];
	fib[0] = 0;
	for (int i = 1; i < num + 1; i++)
	{
		fib[i] = Memo(fib, i);
	}

	return fib;
}



int main() {
	int num = 9, i = 0;
	int* p;
	p = fibonnaci(num);
	while (i < (num + 1))
	{
		cout << p[i] << "  ";
		i++;
	}

	system("pause>0");
}



/* Memorization:
	It is optimization technique to solve recursive problem and improve performance. In this technique
	we save the result of previous computation.
*/