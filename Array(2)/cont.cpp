#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr{{4,3,2}, {1,2,3}, {1, 10,2}};
    int maximum = 0, n = arr.size();
    for (int i = 0 ; i < n ; i++){
        for (int j = 1 ; j <= arr[i][0] ; j++){
            maximum = max(maximum, arr[i][j]);
        }
        cout << maximum << endl;
    }
}