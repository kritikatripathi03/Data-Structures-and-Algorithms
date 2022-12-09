#include<iostream>
using namespace std;

int main(){
    int n = 10, count = 0;
    for(int i = 0; i < n; i ++){
        cout << i << "  ";
        for(int j = 1; j < i; j ++){
            cout << j << " ";
            count ++;
        }
        cout << endl;
    }
    cout << count << endl;
    return 0;
}