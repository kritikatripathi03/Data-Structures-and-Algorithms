#include<bits/stdc++.h>
using namespace std;

double moreprecision(int x, int precision, int tempsol){
    double factor = 1;
    double ans = tempsol;

    for(int i = 0; i < precision; i++){
        factor /= 10;
        for(double j = ans; j*j < x; j = j + factor){
            ans = j;
        }
    }
    return ans;
}

long long int sqrt(int x){
    int start = 0, end = x;
    long long int mid = start + (end-start)/2, ans = -1;
    while(start <= end){
        long long int square = mid*mid;
        if(square == x){
            return mid;
        }
        else if(square < x){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    long long int tempsol;
    cout << sqrt(37) << endl;;
    cout << moreprecision(37, 3, tempsol);
    return 0;
}