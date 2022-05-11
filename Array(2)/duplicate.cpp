#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {-1, 2, 3, -1, 6, 2, -2, -2, -1, 2};
    int size = 10;
    for(int i = 0; i < size - 1; i++){
        for(int j = i; j < size; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    int i = 0, count;
    while(i < size){
        count = 0;
        for(int j = i; j < size; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > 1){
            cout << arr[i] << " ";
        }
        i += count;
    }
    return 0;
}