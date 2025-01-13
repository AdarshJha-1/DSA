#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> v;
    vector<int> v1(5, 1);
    cout << "Size: " << v.size() << endl;
    cout << "Cap: " << v.capacity() << endl;

    v.push_back(11);
    v.push_back(2323);
    v.push_back(123);
    v.push_back(453);
    v.push_back(4353);

    cout << "Size: " << v.size() << endl;
    cout << "Cap: " << v.capacity() << endl;

    cout << "Size: " << v1.size() << endl;
    cout << "Cap: " << v1.capacity() << endl;


for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}


v.insert(v.begin()  + 3, 100);
    
cout << endl ;

for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}


cout << endl;
cout << v[v.size() - 1];


sort(v.begin(), v.end());
for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

    return 0;

}