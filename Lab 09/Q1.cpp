#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    int height;
    Node(int val):data(val),left(nullptr),right(nullptr),height(1){}
};
int getHeight(Node* n){
    if(n==nullptr) return 0;
    return n->height;
}
int getBalance(Node* n){
    if(n==nullptr) return 0;
    return getHeight(n->left) - getHeight(n->right);
}
int max(int a, int b){
    if(a > b) return a;
    else return b;
}
Node* rightRotate(Node* n){
    cout<<"Right rotation performed!\n";
    Node* y = n->left;
    Node* T3 = y->right;
    y->right =n;
    n->left = T3;
    n->height = max(getHeight(n->left),getHeight(n->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    return y;
}
Node* leftRotate(Node* n){
    cout<<"Left rotation performed!\n";
    Node* y = n->right;
    Node* T2 = y->left;
    y->left = n;
    n->right =T2;
    n->height = max(getHeight(n->left),getHeight(n->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    return y;
}
Node* insert(Node* n, int val){
    if(n ==NULL){
        cout<<"Inserted: "<<val<<endl;
        return new Node(val);
    }
    if(val < n->data){
        n->left = insert(n->left, val);
    }
    else if(val>n->data){
        n->right = insert(n->right,val);
    }
    else return n;

    n->height = max(getHeight(n->left),getHeight(n->right))+1;
    int balance = getBalance(n);
    cout<<"Node "<<n->data<<" | BF = "<<balance<<",Height = "<<n->height<<endl;
    if(balance>1 && val<n->left->data) 
    return rightRotate(n);
    if(balance<-1 && val>n->right->data)
    return leftRotate(n);
    if(balance>1 && val>n->left->data){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if(balance<-1 && val<n->right->data){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}
Node* getMin(Node* n){
    while(n->left!=nullptr){
        n = n->left;
    }
    return n;
}
Node* deleteNode(Node* root, int key){
        if(root==nullptr) return nullptr;
        if(key<root->data){
            root->left = deleteNode(root->left,key);
        }
        else if(key>root->data){
            root->right = deleteNode(root->right,key);
        }
        else{
            cout<<"Deleted: "<<key<<endl;
            // Case1: leaf node
            if(root->left==nullptr && root->right==nullptr){
                delete root;
                return nullptr;
            }
            //Case2: 1 child
            else if(root->left==nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //Case3:2 children
            Node* succ = getMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right,succ->data);
        }
    root->height = max(getHeight(root->left),getHeight(root->right))+1;
    int balance = getBalance(root);
    cout<<"After deletion: Node "<<root->data<<" | BF = "<<balance<<",Height = "<<root->height<<endl;
    if(balance>1 && key<root->left->data) 
    return rightRotate(root);
    if(balance<-1 && key>root->right->data)
    return leftRotate(root);
    if(balance>1 && key>root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && key<root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main(){
    Node* root = nullptr;

    cout << "INSERTING ROLL NUMBERS\n";
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Tree Height after insertions: " << getHeight(root) << endl;
    cout << "DELETIONS\n";
    root = deleteNode(root, 20);
    root = deleteNode(root, 70);
    root = deleteNode(root, 60);

    cout << "Tree Height after deletions: " << getHeight(root) << endl;
}
