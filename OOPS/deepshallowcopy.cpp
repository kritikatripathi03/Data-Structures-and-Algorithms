#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;
    char *name;
    Hero(){
        cout << "Simple Constructor called!" << endl;
        name = new char[100];
    }
    Hero(Hero& temp){
        this -> health = temp.health;
        this -> level = temp.level;
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;
    }

    Hero(int health, char level){ //constructor when 2 parameters are given
        cout << "Constructor called" << endl;
        this -> health = health;
        this -> level = level;
    }

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

    void setName(char name[]){
        strcpy(this -> name, name);
    }

    void print(){
        cout << "Health: " << this -> health << ", ";
        cout << "Level: " << this -> level << ", ";
        cout << "Name :" << this -> name << endl;
        cout << endl;
    }
    ~Hero(){
        cout << "Destructor called." << endl;
    }
};

int main(){

    Hero hero1;
    hero1.setLevel('4');
    hero1.setHealth(9);
    char name[8] = "Kritika";
    hero1.setName(name);
    hero1.print();

    Hero *b = new Hero();

    delete b;

    Hero hero2(hero1);
    hero2.print();    
    hero1.name[0] = ' ';
    hero2.print(); // In deep copy we make an entirely different array but in shallow copy the
//the objects point to the adress of another object dso, any change to the object changes this one too.
    Hero hero3 = hero1;
    hero3.print();

    //copy assignment operator
    //hero4 = hero2;
    return 0;
}

//Destrcutor gets automatically called to statically allocated object but not for dynamically
//allocated objects
//Destructor is called only onse per object