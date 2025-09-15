#include <iostream>
using namespace std;

int calculateFactorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n * calculateFactorial(n-1);
}

int main(){
    int n = 5;
    cout<<"Factorial of "<<n<<": "<<calculateFactorial(n)<<endl;
  
    return 0;
}
