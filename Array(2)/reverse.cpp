#include<bits/stdc++.h>
using namespace std;

void rev1(int rev[], int size){
    for(int i = 0; i < size/2; i++){
        int temp = rev[size - 1 - i];
        rev[size - 1 - i] = rev[i];
        rev[i] = temp;
    }
}

void rev2(int rev[], int size){
    int start = 0, end = size - 1;
    while(start <= end){
        swap(rev[start], rev[end]);
        start++;
        end--;
    }
}

int main(){
    int size;
    cout << "Enter the number of elements in your array:";
    cin >> size;
    int rev[100];
    cout << "Enter the elements of the array:" << endl;;
    for(int i = 0; i < size; i++){
        cin >> rev[i];
    }
    rev1(rev,size);
    
    cout << "Here's your reversed array:" << endl;
    for(int i = 0; i < size; i++){
        cout << rev[i] << " ";
    }

    int rev_2[10] = {10, 9, 2, 3, 4, 5, 6, 7, 8, 1};
    cout << "Here's your reversed array:" << endl;

    rev2(rev_2,10);

    for(int i = 0; i < 10; i++){
        cout << rev_2[i] << " ";
    }

    cout << endl;
    return 0;
}