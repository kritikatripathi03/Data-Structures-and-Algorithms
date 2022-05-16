#include<bits/stdc++.h>
using namespace std;

int pivot_element(int arr[], int size){
    int start = 0, end = size - 1, mid;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        else if(arr[mid] <= arr[mid - 1] && arr[mid] <= arr[mid + 1]){
            return arr[mid];
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
int pivotelement(int arr[], int size){
    int start = 0, end = size - 1, mid;
    while(start < end){
        mid = (start + end)/2;
        if(arr[mid] > arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return arr[start]; //or end the same thing
}
int main(){
    int arr[] = {50, 51, 78, 93, 221, 0};
    cout << pivot_element(arr, 6) << endl;
    cout << pivotelement(arr, 6) << endl;
    return 0;
}