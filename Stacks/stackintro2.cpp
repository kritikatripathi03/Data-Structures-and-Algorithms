#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top = -1;
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top ++;
            arr[top] = element;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
        }
        else{
            top -= 1;
        }
    }
    void peek(){
        if(top >= 0 && top < size){
            cout << arr[top] << endl;
        }
        else{
            cout << "Stack Underflow" << endl;
            cout << -1 << endl; 
        }
    }
    bool isEmpty(){
        if(top == -1)
            return true;
        return false;
    }
};

int main(){

    Stack st(5);
    st.push(22);
    st.push(34);
    st.push(55);
    st.peek();
    st.pop();
    st.peek();
    cout << st.isEmpty() << endl;
    st.pop();
    st.pop();
    cout << st.isEmpty() << endl;


    return 0;
}