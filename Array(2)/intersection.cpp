#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr1[6] = {1, 3, 5, 7, 9, 11};
    int arr2[7] = {1, 3, 6, 9, 12, 15, 18};
    int size1 = 6, size2 = 7;
    int intersect[13], k = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(arr1[i] == arr2[j]){
                intersect[k] = arr1[i];
                k += 1;
            }
        }
    }
    for(int i = 0; i < k; i++){
        cout << intersect[i] << " ";
    }
    cout << endl;
    return 0;
}