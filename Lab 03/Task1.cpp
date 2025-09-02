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

    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
    bool isPalindrome(){
        Node* fast = head;
        Node* slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){ //find the middle
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next); //reverse the second half
        Node* pos1 = head;
        Node* pos2 = slow->next;
        while(pos2 != NULL){   // compare the 2 halves
            if(pos1->data != pos2->data){
                return false;
            }
            pos1 = pos1->next;
            pos2 = pos2->next;
        }
        return true;
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
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(1);
    l1.print();
    if(l1.isPalindrome()){
        cout<<"Palindrome\n";
    }else{
        cout<<"Not palindrome\n";
    }

    return 0;
}
