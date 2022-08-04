#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    int num = 5;
    int *ptr = &num;

    double num2 = 2.3;
    double *p2 = &num2;

    cout << "Value at : " << *ptr << endl;
    cout << "Value at : " << *p2 << endl;

    cout << p2 << endl;

    cout << "Size of double variable" << sizeof(num2) << endl;
    cout << "Size of int pointer" << sizeof(ptr) << endl;
    //Therefore, the size of pointer variable is either 4 or 8 bytes.
    cout << "Size of int pointer" << sizeof(p2) << endl;
    /*int *p = 0;
    cout << *p << endl;*/
    //Segmentation error raises when your pointer is pointing to a null value
    //Dk why I cant see any error here!
   /* (*ptr)++;
    cout << num << endl;

    int num3 = 7;
    int *p = &num3;
    int **q = &p;
    cout << p << " and " << q << endl;
    cout << *p << " and " << **q << endl;*/

    int arr[10];
    // ERROR
    //arr = arr + 1;
    
    int *p = &arr[0];
    cout << p << endl;
    p++;
    cout << p << endl;

    return 0;
}