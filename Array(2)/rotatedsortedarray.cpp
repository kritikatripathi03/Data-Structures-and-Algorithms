#include<bits/stdc++.h>
using namespace std;

int rotated_sorted(int arr[], int size, int key){
    int start = 0, end = size - 1, mid;
    while(start < end){
        mid = (start + end)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            if(arr[mid] > arr[0]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        else{
            if(arr[mid] > arr[0]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }

        }
    }
    return start;
}
int main(){
    int arr[] = {7,8,9,1,2};
    cout << rotated_sorted(arr, 6, 8) << endl;

}