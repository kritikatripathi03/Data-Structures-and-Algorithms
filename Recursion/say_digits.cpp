#include<iostream>
using namespace std;

void say_digits(long long n){
    string map[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(n == 0){
        return;
    }
    
    say_digits(n / 10);
    cout << map[n % 10] << " ";
}
int main(){
    say_digits(123456789);

    return 0;
}