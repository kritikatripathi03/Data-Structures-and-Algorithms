#include<bits/stdc++.h>
using namespace std;

int main(){
    //In ht priority queue the maximum or the minimum element is always at the top
    //To create max heap
    priority_queue<int> maxi;
    maxi.push(1);
    maxi.push(2);
    maxi.push(4);
    maxi.push(0);
    cout << "Size: " << maxi.size() << endl; 
    int n = maxi.size();
    for(int i  = 0; i < n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    //To create a min heap:
    priority_queue<int, vector<int>, greater<int> > mini;
    mini.push(1);
    mini.push(2);
    mini.push(4);
    mini.push(0);
    cout << "Size: " << mini.size() << endl; 
    n = mini.size();
    for(int i  = 0; i < n; i++){
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
    cout << mini.empty() << endl;

}