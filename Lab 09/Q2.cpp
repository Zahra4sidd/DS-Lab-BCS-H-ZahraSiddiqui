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
    Node* y = n->left;
    Node* T3 = y->right;
    y->right =n;
    n->left = T3;
    n->height = max(getHeight(n->left),getHeight(n->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    return y;
}
Node* leftRotate(Node* n){
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
void rangeQuery(Node* root, int X, int Y){
    if(root == nullptr) return;
    if(X < root->data) rangeQuery(root->left, X,Y);
    if(root->data>=X && root->data<=Y){
        cout<<root->data<<" ";
    }
    if(Y > root->data) rangeQuery(root->right,X,Y);
}
int main(){
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "Prices between 35 and 65: ";
    rangeQuery(root, 35, 65);
    cout << endl;

    return 0;
}
