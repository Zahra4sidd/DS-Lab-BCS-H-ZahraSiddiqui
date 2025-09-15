#include <iostream>
using namespace std;

// Part 1
void printNumbers(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    n--;
    printNumbers(n);
}
//Part 2
void funcB(int n);
void funcA(int n){ //prints even numbers
    if(n==0){
        return;
    }
    if(n % 2 == 0){
        cout<<"funcA: "<<n<<endl;
    }
    funcB(n-1);
}
void funcB(int n){  //prints odd numbers
    if(n==0){
        return;
    }
    if(n % 2 != 0){
        cout<<"funcB: "<<n<<endl;
    }
    funcA(n);
}
int main(){
    int n;
    cout<<"Part 1:\n";
    cout<<"Enter a number: ";
    cin>>n;
    printNumbers(n);
    cout<<"\nPart 2:\n";
    funcA(n);

    return 0;
}
