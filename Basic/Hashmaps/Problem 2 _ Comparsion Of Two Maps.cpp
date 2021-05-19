#include <iostream>
#include <map>
using namespace std;

template <typename Map>
bool hashmap(Map const& x, Map const& b) {
    return x.size() == b.size() && equal(x.begin(), x.end(), b.begin());
}


int main() {
    map<char, int> x, b;

    //first hashmap x  = {a:1,b:2,c:3} and b={c:3,b:2,a:1}
    x['a'] = 1;
    x['b'] = 2;
    x['c'] = 3;

    b['c'] = 3;
    b['b'] = 2;
    b['a'] = 1;

    cout << "Hashmap: x  = {a:1,b:2,c:3} and b={c:3,b:2,a:1} - Returns:  " << hashmap(x, b) << endl;


    //second hashmap x' = {a:1,b:2,d:3}  and  b={x:3,c:2,a:1}
    x['a'] = 1;
    x['b'] = 2;
    x['c'] = 3;

    b['x'] = 3;
    b['c'] = 2;
    b['a'] = 1;

    cout << "Hashmap: x' = {a:1,b:2,d:3}  and  b={x:3,c:2,a:1} - Returns:  " << hashmap(x, b) << endl;


    system("pause>0");
}


/* 
    We can also check how many matches found. But in hashmap() function just return the True or False
    (boolean) values. We match all the keys of first map to second map. For finding how many matches found
    so we make another function for this but in this function just bool values return. 
*/