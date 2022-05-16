#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {0, 1, 1, 0, 0, 1};
    int size = sizeof(arr)/sizeof(int);
    int i = 0, j = size - 1;
    while(i < j){
        if(arr[i] == 0 && i < j){
            i++;
        }
        else if(arr[j] == 1 && i < j){
            j--;
        }
        else if(arr[i] == 1 && arr[j] == 0 && i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}