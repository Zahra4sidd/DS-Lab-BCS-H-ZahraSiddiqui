#include <iostream>
using namespace std;

int* resizeArray(int* arr, int oldSize, int newSize){
    int* newArr = new int[newSize];
    int elementsToCopy = (oldSize < newSize) ? oldSize : newSize;
    for (int i = 0; i < elementsToCopy; ++i) {
        newArr[i] = arr[i];
    }
    for (int i = elementsToCopy; i < newSize; ++i) {
        newArr[i] = 0;
    }
    delete[] arr;
    return newArr;
}

int main(){
    int n;
    cout<<"Enter the number of months: ";
    cin>>n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cout << "Enter the expense of month " << i + 1 << ": ";
        cin >> arr[i];
    }
    char choice;
    cout << "Do you want to track more months? (y/n): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y'){
        int newSize;
        cout << "Enter the new total number of months: ";
        cin >> newSize;
        if(newSize > n){
            arr = resizeArray(arr, n, newSize);
            for(int i = n; i < newSize; i++){
                cout << "Enter the expense of month " << i + 1 << ": ";
                cin >> arr[i];
            }
            n = newSize;
        }
        else {
            cout << "New size should be greater than current size!\n";
        }
    }
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    int average = (total) / n;
    cout << "Total expenses: " << total << "\n";
    cout << "Average expense: " << average << "\n";

    delete[] arr; 
}
