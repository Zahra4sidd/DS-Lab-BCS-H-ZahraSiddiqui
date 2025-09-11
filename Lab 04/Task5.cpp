#include<iostream>
using namespace std;

class Search{
public:
int interpolation_search(int arr[], int n, int key){
        int low = 0;
        int high = n - 1;
        while(low<=high && key>arr[low] && key<arr[high]){
            if(arr[high] == arr[low]){  //if only one element in the array
                if(key == arr[low]){
                    return low;
                }else{
                    break;
                }
            }
            int pos = low + ((key - arr[low])* (high - low)) / (arr[high] - arr[low]); //estimate key position
            if(pos<low || pos>high){
                break;
            }
            if(arr[pos] == key){
                return pos;
            }
            else if(key > arr[pos]){
                low = pos + 1;
            }
            else{
                high = pos - 1;
            }
        }
        return -1;
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
    Search s1;
    int res = s1.interpolation_search(arr, size, target);
    if(res == -1){
        cout<<target<<" not found\n";
    }
    else{
        cout<<target<<" found at index "<<res<<endl;
    }
    return 0;
}
