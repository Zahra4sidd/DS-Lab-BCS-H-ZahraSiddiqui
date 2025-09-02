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

    Node* merge(Node* head1, Node* head2){
        if(head1==NULL || head2==NULL){
            return head1 == NULL ? head2 : head1;
        }

        if(head1->data <= head2->data){
            head1->next = merge(head1->next, head2);
            return head1;
        }else{
            head2->next = merge(head1, head2->next);
            return head2;
        }
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
    List l1,l2,result;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(5);
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);
    Node* merged = result.merge(l1.head, l2.head);
    result.head = merged;
    result.print();

    return 0;
}
