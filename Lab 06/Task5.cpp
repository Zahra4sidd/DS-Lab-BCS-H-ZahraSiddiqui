#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define MAX 20

class Stack{
    private:
    char arr[MAX];
    int top;
    public:
    Stack():top(-1){}

    bool isEmpty(){
        if(top < 0){
            return true;
        }
        return false;
    }

    bool push(char x){
        if(top >= MAX-1){
            cout<<"Stack overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }
    char pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        else{
            cout<<"Stack underflow\n";
            return '\0';
        }
    }
    char peek(){
        if(!isEmpty()){
            char x = arr[top];
            return x;
        }
        else{
            return '\0';
        }
    }
};
int priority(char op){
    if(op == '^') return 3;
    if(op == '*') return 2;
    if(op == '+' || op=='-') return 1;
    else return -1;
}
string infixToPostfix(string s){
    string ans = "";
    Stack st;
    int i=0, n=s.size();
    while(i < n){
        if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') || s[i]>='0'&&s[i]<='9'){
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.isEmpty() && st.peek()!='('){
                ans += st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isEmpty() && priority(s[i]) <= priority(st.peek())){
                ans += st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.isEmpty()){
        ans += st.pop();
    }
    return ans;
}
int main() {
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;
    string postfix = infixToPostfix(infix);
    cout <<"Postfix expression: "<<postfix<<endl;
    return 0;
}
