#include<iostream>
using namespace std;

class Sort{
public:
void comb_sort(int arr[], int n){
    int gap = n;
    float shrink = 1.3;
    bool swapped = true;
    int comparisons = 0, swaps =0;
    while(gap>1 || swapped==true){
        gap = (int)(gap/shrink);
        if(gap<1){
            gap = 1;
        }
        swapped = false;
        for(int i=0;i+gap < n;i++){
            comparisons++;
            if(arr[i] > arr[i+gap]){
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }
    cout<<"Total number of comparisons: "<<comparisons<<endl;
    cout<<"Total number of swaps: "<<swaps<<endl;
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
    s1.comb_sort(arr, size);
    cout<<"Sorted array:\n";
    s1.print_array(arr, size);
    delete[] arr;
    return 0;
}
