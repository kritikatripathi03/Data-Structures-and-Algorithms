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
    int arr[6] = {5, 10, 2, 3, 14, 5};
    int n = 6;

    selection_sort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
    return 0;
}