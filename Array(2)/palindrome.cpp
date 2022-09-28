#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "kritika";
    int start = 0, end = s.length() - 1;
    while(start < end){
        if(s[start ++] != s[end --]){
            cout << false;
            return 0;
        }
    }
    cout << true;
    return 0;
}