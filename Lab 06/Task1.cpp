#include<iostream>
using namespace std;

#define MAX 5

class Stack{
    private:
    int arr[MAX];
    int top;
    public:
    Stack():top(-1){}

    bool isEmpty(){
        if(top < 0){
            return true;
        }
        return false;
    }

    bool push(int x){
        if(top > MAX){
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int pop(){
        if(!isEmpty()){
            int x = arr[top--];
            return x;
        }
        return 0;
    }

    int peek(){
        if(!isEmpty()){
            int x = arr[top];
            return x;
        }
        return 0;
    }

    void printArr(){
        while(top != -1){
            cout<<pop()<<endl;
        }
    }
};

int main(){
    Stack s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.pop();
    s1.printArr();

    return 0;
}
