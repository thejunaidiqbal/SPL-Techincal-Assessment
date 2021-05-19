#include<iostream>
#include<string>
using namespace std;

bool shareSubString(string a, string b) {
	for (int i = 0; i < a.length(); i++)   //looping till the string a length
	{
		for (int j = 0; j < b.length(); j++)    //looping till the string b length
		{
			if (a[i] == b[j]) {       //match character by character in string a with b
				return true;         //return true if match is found
			}
		}

	}
	
	return false;
}


int main() {

	
	string a = "abcd";   //initialize string a
	string b = "cde";	//initialize string b
	cout << "Bool: " << shareSubString(a, b) << endl;  //fun call for input 1

	system("pause>0");
}