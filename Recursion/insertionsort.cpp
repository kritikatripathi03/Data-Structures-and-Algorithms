#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int i, int n){
    if(n == 0 || n == 1){
        return;
    }
    if(i == n){
        return;
    }
    int j = i - 1, num = arr[i];
    for(; j >= 0; j--){
        if(num < arr[j])
            arr[j + 1] = arr[j];
        else
            break;
    }
    arr[j + 1] = num;
    insertion_sort(arr, i + 1, n);
}

int main(){
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    insertion_sort(arr, 1, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
    return 0;
}