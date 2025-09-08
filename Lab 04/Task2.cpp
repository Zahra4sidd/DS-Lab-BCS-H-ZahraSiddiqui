class Sort{
    public:
void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
    cout<<"Unsorted array\n";
    s1.print_array(arr, size);
    s1.bubble_sort(arr, size);
    cout<<"Sorted array\n";
    s1.print_array(arr, size);
    return 0;
}
