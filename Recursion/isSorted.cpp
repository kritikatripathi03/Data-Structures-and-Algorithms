#include<bits/stdc++.h>
using namespace std;
bool isSorted(int *arr, int size){
    if(size == 0 || size == 1)
        return true;
    if(size == 2){
        if(arr[0] < arr[1])
            return true;
        return false;
    }
    if(arr[0] < arr[1] && isSorted(arr + 1, size - 1))
        return true;
    return false;
    
}
int main(){
    int arr[] = {5, 1, 2, 3, 4, 5, 6};
    cout << isSorted(arr, 7) << endl;
    return 0;
}