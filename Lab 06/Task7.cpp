#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
struct Process {
    int id;
    int priority;
};
class Queue{
    private:
    int front, rear;
    Process arr[MAX];
    public:
    Queue():front(-1), rear(-1){}

    bool isFull(){
        return (rear == MAX-1);
    }
    bool isEmpty(){
        return(rear==-1 || front > rear);
    }

    void enqueue(Process p){
        if(isFull()){
            cout<<"Queue overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = p;
    }

    Process dequeue(){
        Process temp;
        if(isEmpty()){
            cout<<"Queue underflow\n";
            temp.id = -1;
            temp.priority = -1;
            return temp;
        }
        return arr[front++];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Arrival Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << "Process " << arr[i].id << " (Priority " << arr[i].priority << ")\n";
        }
    }
};
class Stack{
    private:
    Process arr[MAX];
    int top;
    public:
    Stack():top(-1){}

    bool isEmpty(){ return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(Process p){
        if(top >= MAX-1){
            cout<<"Stack overflow\n";
            return;
        }
        arr[++top] = p;
    }

    Process pop(){
        Process temp;
        if(!isEmpty()){
            return arr[top--];
        }
        else{
            cout<<"Stack underflow\n";
            temp.id = -1;
            temp.priority = -1;
            return temp;
        }
    }
    void display(){
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout <<"\nExecution Stack(high priority first):\n";
        for(int i = top; i >= 0; i--){
            cout<<"Process "<<arr[i].id<<" (Priority " << arr[i].priority << ")\n";
        }
    }
};
void schedule(Queue &q, Stack &s) {
    Process tempArr[MAX];
    int count = 0;
    while (!q.isEmpty()) {
        tempArr[count++] = q.dequeue();
    }
    //sort by priority
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (tempArr[i].priority < tempArr[j].priority) {
                Process temp = tempArr[i];
                tempArr[i] = tempArr[j];
                tempArr[j] = temp;
            }
        }
    }
    for (int i = count - 1; i >= 0; i--){
    s.push(tempArr[i]);
}
}

int main(){
    Queue q;
    Stack s;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Process p;
        cout << "\nEnter Process ID: ";
        cin >> p.id;
        cout << "Enter Priority: ";
        cin >> p.priority;
        q.enqueue(p);
    }
    q.display();
    schedule(q, s);
    s.display();
    return 0;
}
