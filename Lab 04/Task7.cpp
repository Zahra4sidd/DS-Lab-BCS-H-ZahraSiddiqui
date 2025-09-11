#include<iostream>
using namespace std;

class Sort{
public:
void shell_sort(int arr[], int n){
    for(int gap = n/2; gap>0; gap/=2){
        for(int i=gap;i<n;i++){
            int curr = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>curr){
                arr[j] = arr[j-gap];
                j-=gap;
            }
            arr[j] = curr;
        }
    }
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
    Sort s1;
    s1.shell_sort(arr, size);
    cout<<"Sorted array:\n";
    s1.print_array(arr, size);
    delete[] arr;
    return 0;
}

/* comparing each sort:
Slowest -> Fastest (1000 elements) 
Bubble sort  ~500k comparisons ~250k swaps
Insertion sort ~250k comparisons ~250k shifts
Shell sort ~20k–50k (depending on gap)
*/

