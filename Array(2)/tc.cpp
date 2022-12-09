#include<iostream>
using namespace std;

int main(){
    int n = 5, count1 = 0, count2 = 0, count3 = 0;
    for(int i = 0; i < n; i ++){
        count1 ++;
        cout << i << "  ";
        for(int j = i; j < i * i; j ++){
            count2 ++;
            cout << j << "  ";
            for(int k = 1; k < j; k ++){
                count3++;
                cout << k << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << count1 << " " << count2 << " " << count3 << endl;
    return 0;
}