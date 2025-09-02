#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class List{
    public:  
    Node* head;
    Node* tail;

    List(){
        head = tail = nullptr;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* ifCycle(){
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};

int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.tail->next = l1.head->next;
    Node* startCycle = l1.ifCycle();
    if(startCycle){
        cout<<"Cycle present at node "<<startCycle->data<<endl;
    }else{
        cout<<"Cycle not present\n";
    }

    return 0;
}
