#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<string> s;
    //Stack follows last in first out rule
    s.push("Love");
    s.push("Babbar");
    s.push("Kumar");

    cout << "Top Element: " << s.top() << endl;
    s.pop();
    cout << "Updates top element: " << s.top() << endl;
    cout << "size of stack: " << s.size() << endl;
    // capacity() not possible
    cout << "Is empty? " << s.empty() << endl;
    return 0;

}