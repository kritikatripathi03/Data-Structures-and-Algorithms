#include<bits/stdc++.h>
using namespace std;

int largestRowSum(int arr[][3], int n){
    int maxi = INT_MIN;
    for(int row = 0; row < n; row++){
        int rsum = 0;
        for(int col = 0; col < 3; col++){
            rsum += arr[row][col];
        }
        maxi = max(rsum, maxi);
    }
    return maxi;
}

int main(){
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    for(int col = 0; col < 3; col++){
        int csum = 0;
        for(int row = 0; row < 3; row++){
            csum += arr[row][col];
        }
        cout << csum << endl;
    }
    cout << largestRowSum(arr, 3);
    return 0;
}