#include<bits/stdc++.h>
using namespace std;

int main(){
    int r = 2, c = 5, s = 2;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(s != 1){
                cout<<"e/\\e";
            }
            else{
                cout << "/\\";
            }
        }
        cout << endl;
    }
}