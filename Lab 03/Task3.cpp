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

class List{  //push_front, push_back, pop_front, pop_back
    Node* head;
    Node* tail;

    public:
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

    Node* k_reverse(Node* head, int k){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int cnt = 0;
        Node* temp = head;
        for(int i=0;i<k;i++){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
        }
        while(curr!=nullptr && cnt < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if (next){
        head->next = k_reverse(next, k);
        }
        return prev;

    }
    
    void reverseInGroups(int k) {
        head = k_reverse(head, k);
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
    List l;
    for (int i = 1; i <= 8; i++){
        l.push_back(i);
    }
    int k = 3;
    l.reverseInGroups(k);
    cout << "Reversed in groups of " << k << ": ";
    l.print();

    return 0;
}
