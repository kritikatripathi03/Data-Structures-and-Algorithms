#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[], int size){
    for (int i = 0; i < 15; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int second[3] = {1, 2, 3};
    cout << second[2] << endl;

    int third[15] = {1, 2};

    printarray(third, 15);

    // initialising the whole array with 0 (happens only with 0)
    int fourth[15] = {0};
    printarray(fourth, 15);

    int fourthsize = sizeof(fourth)/sizeof(int);
    cout<<fourthsize<<endl;

    char firstchar[5] = {"a", "e", "i", "o", "u"}; 
    printarray(firstchar,5) //displays error as this function only takes int array lol

    double firstdouble[5];
    float firstfloat[5];
    return 0;
}