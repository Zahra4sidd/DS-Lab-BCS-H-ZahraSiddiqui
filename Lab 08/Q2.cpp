#include<iostream>
using namespace std;

class Node{
    public:
    int playCount;
    string title;
    Node* left; 
    Node* right;
    Node(int p,string t):playCount(p),title(t){
        left = right = nullptr;
    }
};

Node* insertSong(Node* root, int pCount, string title){
    if(!root){
        return new Node(pCount, title);
    }
    if(pCount< root->playCount){
        root->left = insertSong(root->left,pCount,title);
    }
    else if(pCount > root->playCount){
        root->right = insertSong(root->right,pCount,title);
    }
    return root;
}

Node* searchSong(Node* root,int pCount){
    if(root==NULL || root->playCount==pCount) return root;
    if(pCount<root->playCount) return searchSong(root->left,pCount);
    else return searchSong(root->right,pCount);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->title << " (" << root->playCount << ")\n";
    inorder(root->right);
}

void postorder(Node* root){
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->title << " (" << root->playCount << ")\n";
}

Node* findMin(Node* root){
    if(root==NULL) return nullptr;
    Node* curr = root;
    while(curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
}

Node* deleteSong(Node* root, int key){
    if(root==nullptr) return nullptr;
    if(key<root->playCount){
        root->left = deleteSong(root->left,key);
    }
    else if(key>root->playCount){
        root->right = deleteSong(root->right,key);
    }
    else{
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
        Node* succ = findMin(root->right);
        root->playCount = succ->playCount;
        root->title = succ->title; 
        root->right = deleteSong(root->right,succ->playCount);
    }
    return root;
}
int main(){
    Node* root = nullptr;
    root = insertSong(root, 40, "Believer");
    root = insertSong(root, 10, "Calm Piano");
    root = insertSong(root, 70, "Shape of You");
    root = insertSong(root, 20, "Hometown");
    root = insertSong(root, 60, "Faded");
    root = insertSong(root, 90, "Closer");

    cout << "Inorder:\n";
    inorder(root);

    cout << "\nPostorder:\n";
    postorder(root);

    int target = 60;
    cout<<"\nSearching song with playcount: "<<target<<endl;
    Node* found = searchSong(root, target);
    if (found)
        cout << "Found: " << found->title << " (" << found->playCount << ")\n";
    else
        cout << "Not found\n";

    cout << "\nDeleting 40 (Believer)...\n";
    root = deleteSong(root, 40);

    cout << "\nUpdated inorder:\n";
    inorder(root);

    return 0;

}
