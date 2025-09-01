#include <iostream>
using namespace std;

class SafePointer {
    int* ptr;
public:
    SafePointer(){ 
        ptr = nullptr; 
    }
    SafePointer(int value){ 
        ptr = new int(value); 
    }
    ~SafePointer() {
        delete ptr;
    }
    void setValue(int value) {
        if (!ptr){
            ptr = new int;
        }
        *ptr = value;
    }
    int getValue(){
        if (ptr){
            return *ptr;
        }
        cout << "Pointer not initialized!\n";
        return -1;
    }
    void release(){
        delete ptr;
        ptr = nullptr;
    }
};

int main(){
    int n = 5;
    SafePointer* students = new SafePointer[n];
    for (int i = 0; i < n; i++) {
        int marks;
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks;
        students[i].setValue(marks);
    }
    cout <<"Marks of students:\n";
    for (int i = 0; i < n; i++) {
        cout<<"Student " <<i + 1<<": " << students[i].getValue() << endl;
    }
    for (int i = 0; i < n; i++) {
        students[i].release();
    }
    delete[] students;
    return 0;
}
