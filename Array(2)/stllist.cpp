#include<iostream>
#include<list>
using namespace std;

int main(){
    //The origin of STL list is from doubly linked list
    //There are 2 pointers roaming in this list, so using functions like at isn't possible
    list<int> l;

    list<int> n(l);
    list<int> t(5, 100);
    //5 is the size, 100 is the repeated element
    l.push_back(1);
    l.push_back(2);
    for(int i: l){
        cout << i << " ";
    }

    //Functions like begin, end, empty and others have a tc of O(1), but in case of 
    //list, the tc of erase fn is O(n), coz we cant directly go to an element, need to travel
    l.erase(l.begin());
    cout << "\nafter erase" << endl;
    for(int i: l){
        cout << i << " ";
    }

    cout << "Size of list: " << l.size() << endl;
    return 0;
}