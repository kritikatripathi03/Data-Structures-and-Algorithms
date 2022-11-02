#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    string made = "1101";
    int count = 0;
    for(int i = 0; i < made.length(); i ++){
        if(made[i] == str[i]){
            count += 1;
        }
    }
    cout << count << endl;
}