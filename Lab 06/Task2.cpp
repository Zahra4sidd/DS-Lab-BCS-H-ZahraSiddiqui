#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node(string val):data(val),next(nullptr){}
};

class Stack{
    Node* top;
    public:
    Stack():top(nullptr){}

    bool isEmpty(){
        return (top==NULL);
    }

    void push(string val){
        Node* newNode = new Node(val);
        if(top == NULL){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }

    void pop(){
        if(!isEmpty()){
            Node* temp;
            temp = top;
            top = top->next;
            delete temp;
        }
        else{
            cout<<"No previous page (stack underflow)\n";
        }
    }

    string peek(){
        if(!isEmpty()){
            return top->data;
        }
        else{
            return "No page available\n";
        }
    }
};

int main() {
    Stack browserHistory;

    browserHistory.push("Google.com");
    browserHistory.push("YouTube.com");
    browserHistory.push("Github.com");

    cout << "Current Page: " << browserHistory.peek() << endl;

    browserHistory.pop();
    cout << "After going back, Current Page: " << browserHistory.peek() << endl;

    return 0;
}
