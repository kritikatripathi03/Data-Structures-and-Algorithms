#include<bits/stdc++.h>
using namespace std;

void mergesort(int *arr, int s, int e){
    
}
int main(){
    
    int arr[15] = {1, 7, 3, 5, 6, 8, 10, 9, 4, 6, 11, 0};
    int n = 12;

    mergesort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
    return 0;
}