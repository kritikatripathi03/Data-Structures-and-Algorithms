#include<iostream>
#include<array>

using namespace std;

int main(){
    int basic[3] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4}; // STL array is static
    int size = a.size();
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << "\nElement at 2nd index- " << a.at(2) << endl;
    cout << "Empty Array? " << a.empty() << endl;
    cout << "First element of array: "<< a.front() << endl;
    cout << "Last element of array: "<< a.back() << endl;
    return 0;
}