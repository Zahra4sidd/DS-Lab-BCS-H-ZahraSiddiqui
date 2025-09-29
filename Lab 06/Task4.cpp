#include<iostream>
using namespace std;

#define MAX 5

class CircularQueue{
    private:
    int front, rear;
    int arr[MAX];
    public:
    CircularQueue():front(-1), rear(-1){}

    bool isFull(){
        return ((rear+1) % MAX == front);
    }
    bool isEmpty(){
        return(rear==-1 && front==-1);
    }

    void enqueue(int val){
        if(isFull()){
            cout<<"Queue overflow\n";
            return;
        }
        if(isEmpty()){
            rear = 0;
            front = 0;
        }
        else{
            rear = (rear+1) % MAX;
        }
        arr[rear] = val;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow\n";
            return -1;
        }
        int x = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1) % MAX;
        }
        return x;
    }
};

int main(){
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    q.enqueue(40);
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    
    return 0;
}
