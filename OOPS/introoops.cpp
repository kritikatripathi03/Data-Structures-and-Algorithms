#include<iostream>
using namespace std;

class Hero{
    private:
    int health;
    public:
    int level;

    int getHealth(){
        return health;
    }

    int getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }
    void setLevel(int l){
        level = l;
    }
};

int main(){
    //static allocation
    Hero h1;
    //h1.health = 10; private bana diya, directly access nhi kar sakte
    //this is where getter and seeter comes into play
    h1.setHealth(70);
    h1.level = 1;

    cout << "Size is: " << sizeof(h1) << endl; // should be 4 bytes
    //cout << "Health is: " << h1.health << endl;
    cout << "Health is: " << h1.getHealth() << endl;
    cout << "Level is: " << h1.level << endl;

    //dynamic allocation
    Hero* b = new Hero;
    b -> setHealth(90); // (*b).setHealth(90);
    b -> setLevel(3);

    cout << "Health is:" << (*b).getHealth() << endl;
    cout << "Level is: " << (*b).getLevel() << endl;

    cout << "Health is:" << b -> getHealth() << endl;
    cout << "Level is: " << b -> getLevel() << endl;    

    return 0;
}