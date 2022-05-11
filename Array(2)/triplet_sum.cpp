#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void triplet_sum(int arr[], int size){
    int extra = 0;
    if(size % 3 != 0){
        extra = 1;
    }
    else{
        extra = 0;
    }
    int sum[100] = {0};
    int k = 0, i = 0;
    while(k < size/3){
        sum[k] += arr[i] + arr[i + 1] + arr[i + 2];
        k++;// 1 2
        i += 3;
    }
    for(;i < size; i++){
        sum[k] += arr[i];
    }
    printarray(sum, k + extra);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 12, size2 = 8;

    triplet_sum(arr, size);

    triplet_sum(arr2, size2);

    return 0; 
}