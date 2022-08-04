#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    if(s.length() == 0)
        return "";
    if(s.length() == 1)
        return s;
    return s[s.length() - 1] + reverse(s.substr(0, s.size() - 1));
}

void reverse2(string &s, int i, int j){
    
    if(i > j)
        return;
    swap(s[i], s[j]);
    i ++;
    j --;
    return reverse2(s, i, j);
}

int main(){
    //cout << reverse("abcde") << endl;
    string s = "abcde";
    reverse2(s, 0, s.size() - 1);
    cout << s << endl;
    return 0;
}