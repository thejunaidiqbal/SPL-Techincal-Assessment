#include <iostream>
#include<map>
using namespace std;
void frequency(int a[], int n)
{
	map<int, int> arrMap;
	// we can traverse through a[] and count freq.
	for (int i = 0; i < n; i++) {
		arrMap[a[i]]++;
	}
	//now traverse through arrMap and print freq. 
	cout << "Output Array: [";
	for (auto x : arrMap) {
		cout << "{" << x.first << ":" << x.second << "} ";
	}
	cout << "]\n";
}

int main()
{
	int a[] = { 1,2,3,4,5,4,3,1 };
	int size = sizeof(a) / sizeof(a[0]);
	frequency(a, size);
	
	system("pause>0");
}

/*
  We understand that the output array define the input array. So if we find mean of this array, so 
  the answer is yea, we find the mean of output array. If we calculate the sum of all the numbers (i.e. in this array
  the sum is 15,,, suppose define 'var1=15'), and then find sum of frequency (i.e. suppose define 'var2=8') of all the numbers. So the total sum (i.e. var3=var1+var2.. var3=15+8=23) is equal to the numbers in array.
  And now divide the sum of all (i.e. var3) by sum of frequency (var2)...>> (var3/var2) so teh result is mean of the array of original.
*/