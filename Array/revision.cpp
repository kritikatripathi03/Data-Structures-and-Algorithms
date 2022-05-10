#include<bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void bubblesort(int arr[], int n){
    int counter = 0;
    while(counter<n-1){
        for(int i=0; i<n-counter-1; i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        counter++;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selectionsort(arr, n);
    int key;
    cin>>key;
    int s = 0, e = n-1;
    for(int i=0; i<n; i++){
        int mid = s+e/2;
        if(key==arr[mid]){
            cout<<mid<<endl;
            return 0;
        }
        else if(key>arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout<<-1;
    return 0;

}