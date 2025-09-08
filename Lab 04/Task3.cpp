class Sort{
    public:
    void selection_sort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
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
    s1.selection_sort(arr, size);
    cout<<"Sorted array\n";
    s1.print_array(arr, size);
  
    return 0;
}
