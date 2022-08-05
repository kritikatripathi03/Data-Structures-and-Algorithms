#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e){
    int cnt = 0;
    int pivot = arr[s];
    for(int i = s + 1; i <= e; i++){
        if(arr[i] < pivot){
            cnt++;
        }
    }
    int pIndex = s + cnt;
    swap(arr[s], arr[pIndex]);
    pivot = arr[pIndex];
    int i = s, j = e;
    while(i < pIndex && j > pIndex){
        while(arr[i] < pivot)
            i ++;
        while(arr[j] > pivot)
            j --;
        if(arr[i] > pivot && arr[j] < pivot)
            swap(arr[i++], arr[j--]);
    }

    return pIndex;    
}

void quicksort(int *arr, int s, int e){
    if(s >= e){
        return;
    }
    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main(){
    int arr[15] = {1, 7, 3, 5, 6, 8, 10, 9, 4, 6, 11, 0};
    int n = 12;

    quicksort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
    return 0;
}