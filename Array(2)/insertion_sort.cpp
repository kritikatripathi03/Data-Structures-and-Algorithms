#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {20, 13, 4, 9, 21, 55, 23, 1, 5, 53};
    for(int i = 1; i < 10; i++){
        int j = i - 1, temp = arr[i];
        for(; j >= 0; j--){
            if(arr[j] > temp)
            arr[j + 1] = arr[j];

            else
            break; 
        }
        arr[j + 1] = temp;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    return 0;
}