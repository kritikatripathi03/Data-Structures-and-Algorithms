#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {20, 13, 4, 9, 21, 55, 23, 1, 5, 53};
    for(int i = 0; i < 10; i++){
        int minIndex = i;
        for(int j = i + 1; j < 10; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    return 0;
}