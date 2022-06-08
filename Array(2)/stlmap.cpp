#include<iostream>
#include<map>

using namespace std;

int main(){
    //Map is just like the dictionary of python.
    //The time complexity of insert in this is O(long n)
    map<int, string> m;
    m[1] = "Love";
    m[2] = "Babbar";
    m[3] = "Kumar";
    m.insert({13, "bheem"});
    for(auto i : m){
        cout << i.first << " " << i.second << endl;
    }

    cout << m.count(13) << endl;

    m.erase(13);
    for(auto i : m){
        cout << i.first << " " << i.second << endl;
    }

    auto it = m.find(2);
    for(auto i = it; i != m.end(); i++){
        cout << (*i).first << endl;
    }
    
}