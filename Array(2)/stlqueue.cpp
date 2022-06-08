#include<bits/stdc++.h>
using namespace std;

int main(){
    // Queue works on the principle of first in first out.
    //All operations have a time complexity of O(1)
    //Yet to explore other functions on Queue
    queue<string> q;
    q.push("Love");
    q.push("Babbar");
    q.push("Kumar");
    cout << "First Element: " << q.front() << endl;
    cout << "Size before pop " << q.size() << endl;
    cout << "First Element: " << q.front() << endl;
    cout << " Size after pop: "<< q.size()<< endl;
    cout << q.empty() << endl;
}