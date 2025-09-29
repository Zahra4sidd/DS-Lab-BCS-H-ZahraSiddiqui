
#include<iostream>
using namespace std;

#define MAX 5

class Queue{
    private:
    int front, rear;
    int arr[MAX];
    public:
    Queue():front(-1), rear(-1){}

    bool isFull(){
        return (rear == MAX-1);
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
            rear++;
        }
        arr[rear] = val;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow\n";
            return -1;
        }
        return arr[front++];
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    q.display();
    
    return 0;
}
