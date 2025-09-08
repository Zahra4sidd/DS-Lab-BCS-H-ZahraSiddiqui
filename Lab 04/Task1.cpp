#include<iostream>
using namespace std;

class Search{
    public:
    void linear_search(int arr[], int n, int key){
        bool found = false;
        for(int i=0;i<n;i++){
            if(arr[i] == key){
                found = true;
                cout<<arr[i]<<" found at index "<<i<<endl;
                return;
            }
        }
        if(!found){
            cout<<key<<" not found\n";
        }
    }
};

int main(){
    int arr[] = {3,2,7,8,1,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    Search s;
    s.linear_search(arr, size, target);

    return 0;
}
