#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[], int n, int len){
    int start = 0, end = len - 1;
    int mid, ans = -1;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == n){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] > n){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int lastOccurrence(int arr[], int n, int len){
    int start = 0, end = len - 1;
    int mid, ans = -1;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == n){
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] > n){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1, 1, 2, 3, 5, 8, 8};
    cout << firstOccurrence(arr, 8, 7) << endl;
    cout << lastOccurrence(arr, 8, 7) << endl;
}