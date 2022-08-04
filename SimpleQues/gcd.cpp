#include<bits/stdc++.h>
using namespace std;
//EUCLID'S ALGORITHM
int gcd(int a, int b){
    if (a == 0)
    return b;

    if (b == 0)
    return a;

    while(a != b){
        if (b < a){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}

int gcd_recurse(int a, int b){
    if (a == 0){
        return b;
    }
    if (b == 0){
        return a;
    }
    if (a == b){
        return b;
    }
    if(a < b){
        return gcd_recurse(a, b - a);
    }
    return gcd_recurse(a - b, b);
}
int main(){
    int a;
    cin >> a;

    int b;
    cin >> b;

    cout << gcd_recurse(a, b) << endl;
}