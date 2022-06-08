#include<iostream>
#include<set>

using namespace std;

int main(){
    //Set stores different or unique items in itself, if we give it 5 5s it will still have 1 5.
    //It is sorted in ordered set and unordered set does not sort
    //The time complexity of insert operation is Big O(log n)
    set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(8);
    s.insert(5);
    s.insert(8);
    s.insert(5);
    s.insert(1);

    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator itr = s.find(5);
    for(auto it = itr; it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

}
