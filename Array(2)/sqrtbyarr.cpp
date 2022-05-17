#include<bits/stdc++.h>
using namespace std;

int moreprecision(int x){
    
}

long long int sqrt(int x){
    int start = 0, end = x;
    long long int mid = start + (end-start)/2, ans = -1;
    while(start <= end){
        long long int square = mid*mid;
        if(square == x){
            return mid;
        }
        else if(square < mid){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return moreprecision(ans);
}

int main(){
    return 0;
}