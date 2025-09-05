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
    Node* reverse_k_group(Node* head, int k){
        Node* temp = head;
        int count = 0;
        // checking if k nodes exist
        while(count < k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;

        }
        // recursively call for the rest of the ll
        Node* prevNode = reverse_k_group(temp, k);
        // reverse current k group
        temp =head;
        count = 0;
        while(count < k){
            Node* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }
        return prevNode;
    }

    void print(Node* node) {
        while (node) {
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    List l;
    for (int i = 1; i <= 8; i++){
        l.push_back(i);
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;
    l.head = l.reverse_k_group(l.head, k);
    cout << "Reversed in groups of " << k << ": ";
    l.print(l.head);

    return 0;
}
