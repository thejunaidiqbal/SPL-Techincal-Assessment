#include<iostream>
using namespace std;

int size(int a[]); //prototype of size fun to find sizes
int* sort(int a[]);  //prototype of sort fun to sort the data

int* findPairs(int a[], int b)  //a[] array of data and "b" is the target number
{
	int len = size(a), * ptr = new int[size(a)], count = 0;   //dynamically allocate pointer according to requirement
	a = sort(a);

	int ArrStart = 0, ArrEnd = len - 1;
	while (ArrStart < ArrEnd) {
		if (a[ArrStart] + a[ArrEnd] == b) {
			ptr[count++] = a[ArrStart];
			ptr[count++] = a[ArrEnd];

		}
		(a[ArrStart] + a[ArrEnd] < b) ? ArrStart++ : ArrEnd--;
	}
	ptr[count] = -1;
	return ptr;
}

int* filterIdentical(int a[]) {
	int len = size(a);
	int* temp = new int[len], * m = a;
	int count = 0;

	for (int i = 0; i < len; i += 2)
	{
		m[i] = a[i];
		m[i + 1] = a[i + 1];
		for (int j = 0; j < len; j += 2)
		{
			if ((i != j && (i + 1 != j)) && (a[j] != -1 && a[j + 1] != -1) && ((m[i] != -1 && m[i + 1] != -1))) {
				if ((m[i] == a[j] && m[i + 1] == a[j + 1]) || (m[i] == a[j + 1] && m[i + 1] == a[j])) {    //match the pairs and if the pairs match it will assign -1 to that array index because it means pair of this indexes will match now find other
					temp[count++] = m[i];
					temp[count++] = m[i + 1];
					temp[count++] = a[j];
					temp[count++] = a[j + 1];
					a[j] = a[j + 1] = m[i] = m[i + 1] = -1;
				}
			}
		}
	}
	temp[count] = -99;    //this is any negative number to check the length of pointer
	return temp;
}

int main() {
	int arr[] = { 10, 12, 14, 16, 18 };
	int b = 30;   //target number
	int* ptr = findPairs(arr, b);
	int i = 0;
	cout << "Output: [";
	if (ptr[i] != -1) {
		while (ptr[i] != -1) {
			cout << "{" << ptr[i] << "," << ptr[i + 1] << "}";
			i += 2;
			if (ptr[i] != -1) {
				cout << ", ";
			}
		}
	}
	else {
		cout << "No Pair Found";
	}
	cout << "]\n\n";


	//to find identical pairs
	int arr2[] = { 2,3,5,7,3,2,2,3,5,9 };
	/*
		Above pairs have not any identical so
		initialize another array to solve identical pair question.
		Note: When a pair found it neglect these pairs in second loop to find another pair.
	*/
	int* ptr2 = filterIdentical(arr2);
	i = 0;
	cout << "Idential: [";
	if (ptr2[i] != -99) {
		while (ptr2[i] != -99) {
			cout << "{" << ptr2[i] << "," << ptr2[i + 1] << "}";
			i += 2;
			if (ptr2[i] != -99) {
				cout << ", ";
			}
		}
	}
	else {
		cout << "No Identical Pair Found";
	}
	cout << "]\n";


	delete ptr;    //free the memory
	delete ptr2;
	system("pause>0");
}

int size(int a[]) {
	int count = 0;
	while (a[count] >= 0) {
		count++;
	}
	return count;
}

int* sort(int a[]) {
	int temp, * ptr = a;
	int len = size(a);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (ptr[i] < ptr[j]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
	return ptr;
}