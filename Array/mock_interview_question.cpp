#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    int arr[10] = {1, 7, 4, 9, 10, 11, 6, 3, 58, 2};
    for(int i = 0; i < 10; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 6; i ++){
        for(int j = i + 1; j < i + k; j ++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < 10; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << arr[k - 1] << endl;
}