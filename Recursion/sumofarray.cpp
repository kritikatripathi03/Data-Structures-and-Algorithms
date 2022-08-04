#include<bits/stdc++.h>
using namespace std;

int sum(int *arr, int size){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    return arr[0] + sum(arr + 1, size - 1);
}

bool linearsearch(int *arr, int key, int size){
    if(size == 0){
        return false;
    }
    if(arr[0] == key)
        return true;
    return linearsearch(arr + 1, key, size - 1);
}

bool binarysearch(int *arr, int start, int end, int key){
    int mid = (start + end) / 2;
    if(start > end){
        return false;
    }
    if(arr[mid] == key){
        return true;
    }
    if(arr[mid] < key){
        return binarysearch(arr, mid + 1, end, key);
    }
    return binarysearch(arr, start, mid - 1, key);

}
int main(){
    int arr[] = {11, 25, 39, 72, 81, 94, 101};
    cout << binarysearch(arr, 0, 6, 72) << endl;
    return 0;
}