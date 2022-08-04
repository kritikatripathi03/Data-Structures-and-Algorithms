#include<bits/stdc++.h>
using namespace std;

void update(int **p2){
    //p2 = p2 + 1; - doesnt work
    //*p2 = *p2 + 1; - works
    **p2 = **p2 + 1; //works
}

int main(){
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout << "Before:" << endl;
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl;
    cout << "After: " << endl; 
    update(p2);
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl;
    
    
}