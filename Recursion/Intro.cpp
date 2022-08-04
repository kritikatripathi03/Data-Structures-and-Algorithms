#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int powerOfTwo(int n){
    if(n == 0)
        return 1;
    return 2 * powerOfTwo(n - 1);
}

void reverseCounting(int n){ //Tail Recursion
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    
    cout << n << endl;
    reverseCounting(n - 1);

}

void counting(int n){ //Head Recursion
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    counting(n - 1);
    cout << n << endl;
}

int main(){
    //when there is no base case in your recursive function, it gives a segmentation fault
    //Because there will be a stack overflow
    //Base case must have a return statement
    //There are 2 types of Recursion- Head Recursion and Tail Recursion
    cout << factorial(5) << endl;
    cout << powerOfTwo(3) << endl;
    reverseCounting(5);
    counting(5);
    return 0;
}