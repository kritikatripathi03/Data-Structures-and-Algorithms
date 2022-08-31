#include<iostream>
using namespace std;

class Hero {
    public:
    int health;
    char level;

    Hero(int health, char level){ //constructor when 2 parameters are given
        cout << "Constructor called" << endl;
        this -> health = health;
        this -> level = level;
    }
    Hero(){//contructor when no parameter is given
        cout << "Constructor is called" << endl;
    }

    int getHealth(){
        return health;
    }

    Hero(Hero& temp){
        this -> health = temp.health;
        this -> level = temp. level;
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

    Hero ramesh(70, 'A');

    Hero *h = new Hero();

    cout << ramesh.getHealth() << endl;
    cout << ramesh.getLevel() << endl;

    Hero Suresh(ramesh);

    cout << Suresh.getHealth() << endl;
    cout << Suresh.getLevel() << endl;

    return 0;
}