#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {20, 13, 4, 9, 21, 55, 23, 1, 5, 53};
    for(int i = 0; i < 10; i++){
        bool swapped = false;
        for(int j = 0; j < 10 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    return 0;
}