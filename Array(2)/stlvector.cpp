#include<iostream>
#include<vector>
using namespace std;

int main(){
    //vectors are dynamic and if you add an element extra, that is more than its size, it doubles its size
    vector<int> v;
    vector<int> a(5, 1);
    for(int i: a){
        cout << a[i] << " ";
    }

    cout << endl;
    vector<int> last(a);
    for(int i: last){
        cout << last[i] << " ";
    }
    cout << "\nCapacity: " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity: " << v.capacity() << endl;
    //Capacity doubles as we add an extra element
    v.push_back(3);
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    //Size shows the number of elements present and capacity shows how many elements can be stored in the vector

    cout << "2nd element: " << v.at(2) << endl;
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl; 

    v.pop_back();
    //Pop bak and push back work with the last element of vector
    for(int i: v){
        cout << i << " ";
    }

    //Clear deletes all elements in the vector, but capacity remains the same
    v.clear();
    cout << "\nCapacity:" << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

}