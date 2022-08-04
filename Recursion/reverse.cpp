#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    if(s.length() == 0)
        return "";
    if(s.length() == 1)
        return s;
    return s[s.length() - 1] + reverse(s.substr(0, s.size() - 1));
}

int main(){
    cout << reverse("abcde") << endl;
    return 0;
}