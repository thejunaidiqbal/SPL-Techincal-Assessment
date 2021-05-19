#include<iostream>
using namespace std;

int length(int a[]) {
	int count = 0;
	while (a[count] > -1000)
	{
		count++;
	}
	return count;
}

int insert(int a[], int num) {
	int len = length(a);
	if (len == 0) {

		return num;
	}
	else {
		for (int i = 0; i < len; i++)
		{
			if (a[i] > num)
			{
				return num;
			}
			else {
				return num;
			}
		}
	}
}

int* reverse(int a[]) {
	int len = length(a);
	int start = len - len, end = len - 1;
	int* temp = a, j = 0;
	while (start < end)
	{
		int tempv = temp[start];
		temp[start] = temp[end];
		temp[end] = tempv;
		start++;
		end--;
	}
	return temp;
}
int* DistributeArray(int a[], int b) {  //a[] array of integers and "b" is the pivot
	int size = length(a);
	if (size % 2 == 0) {
		cout << "[";
		for (int i = 0; i < size / 2; i++)
		{
			cout << a[i];
			if (i != (size / 2) - 1) {
				cout << ", ";
			}
		}
		cout << "] ";
		cout << "[";
		for (int i = size / 2; i < size - 1; i++)
		{
			cout << a[i];
			if (i != size - 2) {
				cout << ", ";
			}
		}
		cout << "]\n";
		return NULL;
	}
	else {
		static int* left = new int[size], * right = new int[size];
		int c = 0, c1 = 0;
		for (int i = 0; i < size; i++)
		{
			if (a[i] != b) {
				if (a[i] < b) {

					left[c++] = insert(left, a[i]);

					//left[c++] = insert(left, a[i]);
				}
				else {
					right[c1++] = insert(right, a[i]);
				}



			}
		}
		//left = reverse(left);
		int len2 = length(left);
		int len3 = length(right);
		int* ptr = new int[len2 + len3 + 1];
		int j = 0, k = 0;
		for (int i = 0; i < (len2 + len3) + 1; i++)
		{
			if (i < len2) {
				if (i + 1 == len2 && len2 > len3) {
					ptr = reverse(ptr);
					ptr[i] = left[j++];

				}
				else if (i + 1 == len2 && len2 < len3) {
					ptr[i] = left[j++];
					ptr = reverse(ptr);
				}
				else if (i + 1 == len2 && len2 == len3) {
					ptr[i] = left[j++];
					ptr = reverse(ptr);
				}
				else {
					ptr[i] = left[j++];
					//cout << ptr[i] << endl;
				}
			}
			else if (i == len2) {
				ptr[i] = b;
			}
			else {
				ptr[i] = right[k++];
			}
		}
		//ptr[k] = -1000;
		return ptr;
	}
}

int main() {
	int arr[] = { 1,-1,-2,2,-3,3,0 };
	int b = 0;   //pivot value
	int size = sizeof(arr) / sizeof(arr[0]);
	int* temp = new int[size + 1];
	temp = DistributeArray(arr, b);
	if (temp != NULL) {
		int i = 0, len = length(temp);
		cout << "[";
		while (i < len)
		{
			cout << temp[i];
			if (i < len - 1) {
				cout << ", ";
			}
			i++;
		}
		cout << "] for Pivot " << b << endl;
	}
	else {
		cout << "\nNo Pivot in array\n";
	}

	delete[]temp;
	system("pause>0");
}



/*	
	If the even number of elements in array, so there were two middle values so we can use the
	concept of median. If even number of array i.e. {2,3,6,5,1,7} so middle values are 6 & 5, so
	Sum the two values and divide by 2 for finding median.
*/