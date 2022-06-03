#include<bits/stdc++.h>
using namespace std;

int getLength(char name[]){
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

void getReverse(char name[], int n){
    for(int i = 0, l = n - 1; i < n / 2; i++, l--){
        swap(name[i], name[l]);
    }
    cout << name << endl;
}

int main(){
    char name[20];
    cout << "Enter a name: ";
    cin >> name;

    cout << "Your name is " << name << endl;
    //space, tab or enter wont let you take the whole index in string through cin
    int l = getLength(name);
    getReverse(name, l);
}