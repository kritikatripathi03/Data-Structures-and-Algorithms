#include<iostream>
#include<deque>

using namespace std;

int main(){
    //Deque is basically a double ended queue, so, we can perform pop and push functions on both
    //sides of the queue
    //In deque, size may keep on changing according to the operations but, the max size or the initial memory
    // allocated to the deque remains the same
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(3);

    for(int i: d){
        cout << i << " ";
    }

    d.pop_back();
    d.pop_front();
    cout << endl;

    for(int i: d){
        cout << i << " ";
    }
    d.push_back(1);
    d.push_front(2);
    d.push_front(3);
    cout << "First Index element: " << d.at(1) << endl;
    cout << "Third Index Element: " << d.at(3) << endl;

    cout << d.empty() << endl; 
    cout << "Before erase: " << endl;
    for(int i: d){
        cout << i << " "; 
    }

    d.erase(d.begin(), d.begin() + 1); //removes one elements
    cout << "\nAfter erase: " << endl;
    for(int i: d){
        cout << i << " ";
    }

}