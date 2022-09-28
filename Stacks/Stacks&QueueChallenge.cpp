#include <iostream>
using namespace std;
 
class myQueue {
  private:
  int * queueArr;
  int capacity;
  int numElements;
  int front;
  int back;
  public:
 
  myQueue(int size){
    queueArr = new int[size * 3];
    capacity = size * 3;
    front = -1;
    back = -1;
  }
 
  bool isEmpty(){
    return front == -1 || back < front;
  }
 
  int getFront(){
    if(isEmpty()){
        return -1;
    }
    return queueArr[front];
  }
 
  void enqueue(int value) {
    if(front == -1){
        front = 0;
    }
    back++;
    if(back < capacity) {
        queueArr[back] = value;
    }
  }
 
  int dequeue() {
    if(isEmpty()){
        return -1;
    }
    int temp = queueArr[front];
    front++;
    return temp;
  }
 
  int getSize(){
    return back - front + 1;
  }
 
  void showqueue() {
    if(isEmpty()){
        return;
    }
    for(int i = front; i <= back; i++){
        cout << " " << queueArr[i];
    }
    cout << endl;
  }
};
 
class myStack {
  private:
  int * stackArr;
  int capacity;
  int numElements;
  public:
    myStack(int size){
        stackArr = new int[size];
        capacity = size;
        numElements = 0;
    }
 
    bool isEmpty(){
        return numElements == 0;
    }
 
    int getTop(){
        if(isEmpty()){
            return -1;
        }
        return stackArr[numElements - 1];
    }
    bool push(int value) {
        if(numElements < capacity) {
            stackArr[numElements] = value;
            numElements++;
            return true;
        }
        return false;
    }
    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int temp = stackArr[numElements - 1];
        numElements--;
        return temp;
    }
    int getSize() {
        return numElements;
    }
    void showStack() {
        for(int i = 0; i < numElements; i++) {
            cout << " " << stackArr[i];
        }
        cout << endl;
    }
};
 
myQueue reverseK(myQueue queue, int k) {
    int size = queue.getSize();
    myStack stk(k);
 
    for(int i = 0; i < k; i++) {
        stk.push(queue.dequeue());
    }
 
    for(int i = 0; i< k; i++) {
        queue.enqueue(stk.pop());
    }
 
    for(int i = 0; i < size - k; i++) {
        queue.enqueue(queue.dequeue());
    }
    return queue;
}