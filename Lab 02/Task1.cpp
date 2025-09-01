#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the array size: ";
    cin>>size;
    int* arr = new int[size] ();
    int n;
    cout<<"Enter the number of times you want to update array values: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int index;
        cout<<"Enter the index: ";
        cin>>index;
        if(index<size){
            int val;
            cout<<"Enter the value at index '"<<index<<"': ";
            cin>>val;
            arr[index] = val;
        }else{
            cout<<"Invalid index entered!";
            exit(0);
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
    delete[] arr;

}
