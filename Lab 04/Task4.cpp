#include<iostream>
using namespace std;

class Sort{
public:
void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

void binary_search(int arr[], int n, int key){
        int low = 0;
        int high = n - 1;
        while(low < high){
            int mid = (low + high)/2;
            if(arr[mid] == key){
                cout<<"Found at index "<<mid<<endl;
                return;
            }
            else if(key > arr[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout<<key<<" not found\n";
    }

void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int* arr = new int[size];
    cout<<"Enter elements\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;
    Sort s1;
    s1.insertion_sort(arr, size);
    cout<<"Sorted array\n";
    s1.print_array(arr, size);
    s1.binary_search(arr, size, target);
    return 0;
}
