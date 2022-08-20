#include<bits/stdc++.h>
using namespace std;

string recursebin(long long int num, int ten){
    string result = "";
    if(num == 0){
        return "0";
    }
    return result.push_back((num % 2) * (long long int)(pow(10, ten)+1e-9) + recursebin(num / 2, ten + 1));
}

int main(){
    int ten = 10;
    cout << to_string(recursebin(786435, 0)) << endl;
}