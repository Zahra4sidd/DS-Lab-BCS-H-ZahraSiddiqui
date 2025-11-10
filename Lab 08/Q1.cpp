#include<iostream>
using namespace std;

class Node{
    public:
    string name;
    Node* mother; //left
    Node* father; //right
    Node(string n):name(n){
        mother = father = nullptr;
    }
};

void printRoot(Node* root){
    if(root==nullptr) return;
    cout<<"Youngest: "<<root->name<<endl;
}

void printLeaf(Node* root){
    if(!root) return;
    if(root->father==nullptr && root->mother==nullptr){
        cout<<root->name<<" ";
    }
    printLeaf(root->mother);
    printLeaf(root->father);
}

int height(Node* root){
    if(root==nullptr) return -1;
    return max(height(root->mother), height(root->father)) + 1;
}

void printLevel(Node* root, int level, int curr){
    if(!root) return;
    if(level == curr){
        cout<<root->name<<" ";
        return;
    }
    printLevel(root->mother, level, curr+1);
    printLevel(root->father, level, curr+1);
}

void displayLevels(Node* root){
    int h = height(root);
    for(int lvl = 0;lvl<=h;lvl++){
        cout<<"Level "<<lvl<<": ";
        printLevel(root,lvl,0);
        cout<<endl;
    }
}

int main(){
    Node* child = new Node("Adam");

    child->mother = new Node("Sara");
    child->father = new Node("David");
    //grandparents
    child->mother->mother = new Node("Linda");
    child->mother->father = new Node("George");
    child->father->mother = new Node("Emma");
    child->father->father = new Node("Joseph");
    printRoot(child);
    cout<<"Leaf Nodes:\n";
    printLeaf(child);
    cout<<endl;
    cout<<"Height: "<<height(child)<<endl;
    cout<<"Members by level:\n";
    displayLevels(child);
    return 0;
}
