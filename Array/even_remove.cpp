#include<iostream>
using namespace std;

int * removeEven(int Arr[], int size){
    int count = 0;
    for(int i = 0;  i < size; i ++){
        if (Arr[i] % 2 != 0){
            count ++;
        }
    }
    int result[count] = {0};
    count = 0;
    for(int i = 0;  i < size; i ++){
        if (Arr[i] % 2 != 0){
            result[count] = Arr[i];
            count ++;
        }
    }
    return *&result;
}

int main(){
    int Arr[6] = {1, 2, 3, 4, 5, 6};
    int* result = removeEven(Arr, 6);

    return 0;
}