#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(int arr[]) {
        int n = 5;
        int start = 0, end = n - 1, mid, ans;
        while(start <= end){
            mid = (start + end)/2;
            if(arr[mid] < arr[mid + 1]){
                start = mid + 1;
                //cout<<arr[mid]<<endl;
            }
            else if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                //cout << "H" <<arr[mid]<<endl;
                return mid;
            }
            else{
                //cout << "L"<<arr[mid]<<endl;
                end = mid - 1;
            }
        }
        return -1;
}

int last_occurence(int arr[], int n, int key){
    int start = 0, end = n - 1, ans = -1, mid;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == key){
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key){
            end = mid + 1;
        }
        else{
            start = mid - 1;
        }
    }
    return ans;
}

int first_occurence(int arr[], int n, int key){
    int start = 0, end = n - 1, ans = -1, mid;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key){
            end = mid + 1;
        }
        else{
            start = mid - 1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {1, 2, 3, 1, 0};
    cout<< peakIndexInMountainArray(arr) << endl;

    return 0;  
}