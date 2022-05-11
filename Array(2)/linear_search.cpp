#include<bits/stdc++.h>
using namespace std;

bool linear_search(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return true;
        }
    }
    return false;
}

bool binary_search(int arr[], int size, int key){
    int s = 0, e = size - 1;
    while(s<=e){
        int  mid = (s + e)/2;
        if(key == arr[mid]){
            return true;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return false;
}

int main(){
    int size;
    cout << "Enter the number of elements:" << endl;
    cin >> size;
    cout << "Enter the elements" << endl;
    int searchfrom[100];
    for(int i = 0; i < size; i++){
        cin >> searchfrom[i];
    }
    int key;
    cout << "Enter the element that you wanna search:" ;
    cin >> key;

    int flag = binary_search(searchfrom, size, key);

    if( flag ){
        cout << "Key is present." << endl;
    }
    else{
        cout << "Key is not present." << endl;
    }
    return 0;
}