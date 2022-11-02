#include<stdio.h>

void fibonacci(int t, int f, int s){
    int n;
    if(t >= 1){
        n = f + s;
        printf("%d ", n);
        t -= 1;
        fibonacci(t, s, n);
    }
}

void main(){
    fibonacci(5, 0, 1);
}