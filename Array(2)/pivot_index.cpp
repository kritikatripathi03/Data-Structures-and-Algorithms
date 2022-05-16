#include<bits/stdc++.h>
using namespace std;

int pivotIndex(int nums[]) {
        int n = 6;
        int sum = 0, sum1, sum2;
        int p[10000] = {0};
        int q[1000] = {0};
        for(int i = 1; i < n + 1; i++){
            sum += nums[i - 1];
            p[i] = sum;
        }
        for(int i = 0; i < n; i++){
            q[i] = p[n] - p[i] - nums[i];
        }
        for(int i = 0; i < n; i++){
            cout << q[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n + 1; i++){
            cout << p[i] << " ";
        }
        cout <<  endl;
        for(int i = 0; i < n; i++){
            if(p[i] == q[i]){
                return i;
            }
        }
        return -1;
    }

int main(){
    int arr[] = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(arr) << endl;
    return 0;
}