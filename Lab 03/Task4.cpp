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

class circularList{
    public:
    Node* head;
    Node* tail;
    circularList(){
        head = tail = nullptr;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            newNode->next = head;
        }else{
            tail->next = newNode;
            tail = newNode;
            newNode->next = head; 
        }
    }

    int josephus(int k){
        Node* curr = head;
        Node* prev = tail;
        while(curr->next != curr){ //until one node remains
            for(int i=0;i<k-1;i++){  // traverse to the kth pos
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;  // delete the node
            Node* temp = curr;
            curr = prev->next;
            delete temp;
        }
        int survivor = curr->data;
        delete curr;
        head= tail= nullptr;
        return survivor;
    }
};

int main(){
    int n = 7;
    int k = 3;
    circularList cll;
    for (int i = 1; i <= n; i++){
        cll.push_back(i);
    }
    cout<<"The survivor is at position: "<<cll.josephus(k)<<endl;
    return 0;
}
