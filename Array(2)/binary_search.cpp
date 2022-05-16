#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int size, int key){
    int s = 0, e = size-1, mid;
    while(s <= e){
        mid = (s+e)/2;
        if(arr[mid] == key){
            return mid + 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else{
            e  = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {11, 22, 34, 45, 56, 67, 78, 89, 90};
    int size = sizeof(arr)/sizeof(int);
    int n = 22;
    int res = binary_search(arr, size, n);
    cout << res << endl;
    return 0;
}