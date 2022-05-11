#include<bits/stdc++.h>
using namespace std;

int get_MAX(int arr[], int size){
    int max = INT_MIN;
    for(int i = 0; i < size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int get_MIN(int arr[], int size){
    int min = INT_MAX;
    for (int i = 0; i < size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int get_SUM(int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int n; 
    cout << "Enter the size of array:";
    cin >> n;
    int arr[100];
    cout << "Enter the elements:" << endl;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int max = get_MAX(arr, n);
    cout << "The maximum value of the array is:" << max <<endl;
    
    int min = get_MIN(arr, n);
    cout << "The minimum value of the array is:" << min <<endl;

    int sum = get_SUM(arr, n);
    cout << "The sum of the values of the array is:" << sum <<endl;
    return 0;
}