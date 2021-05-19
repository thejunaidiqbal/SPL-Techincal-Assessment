#include<iostream>
#include<string>
using namespace std;

string removeChar(string name, char x)
{
	string temp = "";
	for (int i = 0; i < name.length(); i++)
	{
		if (x != name[i]) {
			temp += name[i];
		}
	}
	return temp;
}

int main() {
	string name = "We Are Your Technology Partners";
	char x = ' ';
	cout << "Original String:\t" << name
		<< "\n\nAfter removing string will be:\t" << removeChar(name, x);

	system("pause>0");
}



//Question: Can we use the Tree data structure or hashing to optimize this?
/*We know that tree DS consists of roots, leaves & branches and it is upside down. So it we talk on
  optiminze this problem so first we know about the complexities of tree DS and hashtable. 
  The complexity of searching, inserting & deleting operations are O(n), O(n), O(n) or maybe in somecase (generally not worst cases) are O(h) of insertion & deletion.
  But if we talk about AVL it has Log(n) for searching, inserting and deletion. So if we talk on hashtable,
  so the complexity of hastable in generally O(1).
*/