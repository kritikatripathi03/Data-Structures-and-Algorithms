#include<iostream>
using namespace std;

int main(){
    int j = 5;
    int& i = j;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;

    return 0;
}