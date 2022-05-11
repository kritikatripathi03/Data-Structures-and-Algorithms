#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int size = 10, size2 = 11;
    int pairsum[100] = {0}, pairsum2[100] = {0}, i = 0, k = 0;
    while(k < size/2){
        pairsum[k] += arr[i] + arr[i+1];
        k++; // 1
        i += 2;  // 2
    }
    printarray(pairsum, size/2);
    k = 0, i = 0;
    while(k < size2/2){
        pairsum2[k] += arr2[i] + arr2[i+1];
        k++;
        i+=2;
    }
    pairsum2[k] += arr2[i];
    printarray(pairsum2, size2/2 + 1);
    return 0;
}