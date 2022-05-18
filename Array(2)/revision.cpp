#include<bits/stdc++.h>
using namespace std;

int last_occ(int arr[], int n, int key){
    int start = 0, end = n - 1, mid, ans = -1;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == key){
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int first_occ(int arr[], int n, int key){
    int start = 0, end = n - 1, mid, ans = -1;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int peak_mountain(int arr[], int n){
    int start = 0, end = n - 1, mid;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int pivot_index(int arr[], int n){
    int p[10000] = {0};
    int sum = 0;
    for(int i = 1; i < n + 1; i++){
        sum += arr[i - 1];
        p[i] = sum;
    }
    for(int i = 0; i < n; i++){
        if(p[i] == p[n] - arr[i] - p[i]){
            return i;
        }
    }
    return -1;
}

int rotated_sorted(int arr[], int n, int k){
    int start = 0, end = n - 1, mid;
    while(start <= end){
        mid = (start +  end)/2;
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid] > k && arr[mid] > 0){
            if(k > arr[0]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 5, 5};
    cout << first_occ(arr, 5, 5) << endl;
    cout << last_occ(arr, 5, 5) << endl;
    int arr2[] = {4, 5, 6, 1, 2, 3};
    cout << peak_mountain(arr2, 6) << endl; 
    int arr3[] = {7, 8, 9, 0, 1, 2, 3};
    cout << rotated_sorted(arr3, 7, 8) << endl;
    return 0;
}