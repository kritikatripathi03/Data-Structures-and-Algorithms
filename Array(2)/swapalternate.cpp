#include<bits\stdc++.h>
using namespace std;

int main(){
    int arr[11] = {10, 2, 9, 3, 4, 7, 5, 6, 8, 1, 45};
    int i = 0 , size = 11;
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
