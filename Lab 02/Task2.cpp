#include<iostream>
using namespace std;

int main(){
    int row,col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;
    int** arr = new int*[row];
    for(int i=0;i<row;i++){
        arr[i] = new int[col]();
    }
    while(true){
        int i,j;
        cout<<"Enter the position (0 0 for the first seat)to fill seats: ";
        cin>>i>>j;
        if(i<row && j<col){
            arr[i][j] = 1;
        }else{
            cout<<"Invalid position entered!\n";
        }
        int flag;
        cout<<"Do you wish to continue (1:yes 0:no): ";
        cin>>flag;
        if(flag==0){
            break;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0;i<row;i++){
    	delete[] arr[i];
	}
	delete[] arr;
}
