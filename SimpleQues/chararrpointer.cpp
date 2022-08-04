#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch[6] = "abcde";
    char *c = &ch[0];
    cout << c << endl;

    char temp = 'z';
    cout << temp << endl;
    char *p = &temp; 
    cout << p << endl; //It will print z followed by other characters untill it finds a null
    return 0;
}