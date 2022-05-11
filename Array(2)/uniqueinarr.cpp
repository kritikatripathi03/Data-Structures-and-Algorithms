#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {10, 29 , 33, 45, 29, 10, 29, 33, 92, 45 };
    int size = 10;
    int freq[100] = {0};
    for(int i = 0; i < size; i++){
        freq[arr[i]] += 1;
    }

    for(int i = 0; i < 100; i++){
        if(freq[i] == 1){
            cout << "U:" << i << endl;
            cout << endl;
        }

        if(freq[i] > 1){
            cout << "D:" << i << " ";
        }
    }
    cout << endl;

    return 0;
}