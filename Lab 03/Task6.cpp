#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;
    Node(int val){
        data = val;
        next = child = nullptr;
    }
};

class list{
    public:
    Node* flatten(Node* head){
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                // flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->child = NULL;
                // find the tail
                while(curr->next != NULL){
                    curr = curr->next;
                }
                // attach tail to next
                if(next != NULL){
                    curr->next = next;
                }

            }
            curr = curr->next;
        }
        return head;
    }
    void print(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n4->next = n5;
    n2->child = n4;
    list l1;
    n1 = l1.flatten(n1);
    cout << "After flattening:\n";
    l1.print(n1);

    Node* temp;
    while (n1 != NULL) {
        temp = n1;
        n1 = n1->next;
        delete temp;
    }
    return 0;
}
