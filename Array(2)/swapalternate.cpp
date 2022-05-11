#include<bits\stdc++.h>
using namespace std;

int main(){
    int arr[10] = {10, 2, 9, 3, 4, 7, 5, 6, 8, 1};
    int i = 0 , size = 10;
    while(i <= size - 2){
        swap(arr[i], arr[i+1]);
        i+=2;
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
