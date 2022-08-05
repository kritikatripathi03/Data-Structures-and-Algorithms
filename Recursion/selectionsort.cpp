#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *arr, int s, int n){
    if(n == 0 || n == 1)
        return;
    if(s == n)
        return;
    for(int i = s + 1; i < n; i ++){
        if(arr[s] > arr[i])
            swap(arr[s], arr[i]);
    }
    selection_sort(arr, ++s, n);
    
}
int main(){
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    selection_sort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
    return 0;
}