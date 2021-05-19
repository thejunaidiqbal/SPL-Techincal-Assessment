#include<iostream>
using namespace std;

int length(int []);
int findMaximum(int a[], int size) {
	int* left = new int[size];
	int* right = new int[size];
	int leftCount = 0, rightCount = 0, temp = 0;
	for (int i = 0; i < size; i++)  //split the array
	{
		if (a[i] < 0) {
			left[leftCount] = a[i];
			leftCount++;
		}
		else if (a[i] >= 0) {
			right[rightCount] = a[i];
			rightCount++;
		}
	}

	if (leftCount > 0) {

		for (int i = 0; i < leftCount; i++)
		{
			left[i] = (-1) * left[i];
		}
		for (int i = 0; i < leftCount; i++)
		{
			for (int j = 0; j < leftCount; j++)
			{
				if (left[i] > left[j]) {
					temp = left[i];
					left[i] = left[j];
					left[j] = temp;
				}
			}
		}
		for (int i = 0; i < leftCount; i++)
		{
			left[i] = (-1) * left[i];
		}


	}
	if (rightCount > 0) {
		temp = 0;
		for (int i = 0; i < rightCount; i++)
		{
			for (int j = 0; j < rightCount; j++)
			{
				if (right[i] < right[j]) {
					temp = right[i];
					right[i] = right[j];
					right[j] = temp;
				}
			}
		}

	}

	if (leftCount > 0 && rightCount > 0) {
		int* finalArray = new int[size], i=0, j=0,k=0;
		for (; i < size; i++)
		{
			if (i < leftCount) {
				finalArray[i] = left[k++];
			}
			else {
				finalArray[i] = right[j++];
			}
		}
		return finalArray[i-1];
	}
	else if (leftCount > 0 && rightCount == 0) {
		int Lsize = length(left);
		return left[Lsize - 1];

	}
	else if (rightCount > 0 && leftCount == 0) {
		int Rsize = length(right);
		return right[Rsize - 1];
	}

	return -1;
}


int main() {
	int arr[] = { -1,1,-2,2,-3,3,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum: " << findMaximum(arr, size);
	system("pause>0");
}


int length(int a[]) {
	int count = 0;
	while (a[count] > -999)
	{
		count++;
	}
	return count;
}



/*
	Yes we can use distributiveArray method to solve this problem. When the final array return it will sorted (in somecases depend on pivot). 
	So we can say that the last element of array is maximum. So we easily find the maximum element of array through distributiveArray() method
	Now this findMaximum() method is a smart sorting method to solve this problem. 
*/