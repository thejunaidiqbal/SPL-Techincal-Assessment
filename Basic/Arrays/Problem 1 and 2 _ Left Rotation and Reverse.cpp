#include<iostream>
using namespace std;

int length(int[]);  //function length is because according to problem requirement there is no paramenter for size of array pass so make a length function because "Sizeof(array)" function didn't work in functions it just work in main function or where the array is initialized.

int* rotLeft(int a[], int d) {    //problem 1
	int checkSize = length(a);  //check the size of array
	int* temp = new int[d], i;   //dynamically call according to rotate 

	for (i = 0; i < d; i++)
	{
		temp[i] = a[i];   //save rotating number to temp, loop counter depend on the rotation
	}

	for (int j = 0; j < checkSize; j++)
	{
		if (i < checkSize) {
			a[j] = a[i];     //store other data of this array to start of this array
			i++;
		}
		else
		{
			a[j] = temp[(j + d) - i];  //set the rotation data to remaining part of same array
		}
	}


	delete[]temp;  //delete the temp to free memory
	return a;    //return array
}

int *reverseArray(int a[]) {        //problem 2  
	int len = length(a);    //first find all the length of array
	int* ptr = new int[len];    //dynamically create new array for reverse
	int *ptr2 = a;       //ptr2 is the temp array
	int outlength = 0;   //for find length of array of new array ptr
	for (int i = 0; i < len; i++)
	{
		ptr2 = rotLeft(ptr2, length(ptr2) - 1);    //in everytime rotate left function call and rotate array with length - 1 in each iteration
		outlength = length(ptr);    //find new length of new pointer array
		ptr[outlength] = ptr2[0];    //store the first element of data in last of pointer array ptr
	}
	return ptr;
}


int main() {
	int d = 0;
	int arr[] = { 1,2,3,4,5 }; //initialize array 
	cout << "Enter value to left rotate: ";
	cin >> d;

	int* a = rotLeft(arr, d);  //function call
	int len = length(a);
	//display result
	cout << "Left Rotate:  [";
	for (int i = 0; i < len; i++)
	{
		cout << a[i];
		if (i < len - 1) {
			cout << ", ";
		}
	}
	cout << "]\n\n";

	//problem 2

	int arr2[] = { 1,2,3,4,5 };   //for problem 2 new array
	int *revA = reverseArray(arr2);  //call the function of reverse
	len = length(revA);    //update new length of reverse array
	cout << "Reverse Array using rotLeft:  [";
	for (int i = 0; i < len; i++)
	{
		cout << revA[i];
		if (i != len - 1) {
			cout << ", ";
		}
	}
	cout << "]\n";

	system("pause>0");
}

int length(int a[]) {
	int count = 0;
	while (a[count] > -999)   //check the length of array ... -999 is just a random number to check
	{
		count++;
	}
	return count;
}



/*	
   Absolutely, we can reverse the array using rotleft function, but we must decrement the length of main array. 
   In everytime rotate left function call and rotate array with length - 1 in each iteration.
   And store the first element of data in last of pointer array ptr, as shown in reverseArray(a[]) function.

   And the complexity of this reverse function is n^2. 
*/