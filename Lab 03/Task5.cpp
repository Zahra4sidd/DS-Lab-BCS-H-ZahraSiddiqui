#include <iostream>
using namespace std;

class sNode{
    public:
    int data;
    sNode* next;

    sNode(int val){
        data = val;
        next = nullptr;
    }
};
class dNode{
    public:
    int data;
    dNode* next;
    dNode* prev;
    dNode(int val){
        data = val;
        next = prev = nullptr;
    }
};
class list{
    public:
    sNode* head;
    list(){
        head = nullptr;
    }
    void toCircular(){
        sNode* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;
    }
    dNode* toDoubly(){
        dNode* dHead = new dNode(head->data);
        dNode* dCurr = dHead;
        sNode* sCurr = head->next;
        while(sCurr != NULL){
            dNode* newNode = new dNode(sCurr->data);
            dCurr->next = newNode;
            newNode->prev = dCurr;
            dCurr = newNode;
            sCurr = sCurr->next;
        }
        return dHead;
    }
};
