#include <iostream>
using namespace std;

int sumTail(int n, int total){
    if(n == 0){
        return total;
    }
    total += n;
    n--;
    return sumTail(n,total);
}

int sumNonTail(int n, int total){
    if(n == 0){
        return total;
    }
    int res = sumNonTail(n-1, total);
    return res + n;

}
int main(){
    int n = 5;
    int total = 0;
    cout<<"sumTail: "<<sumTail(n, total)<<endl;
    cout<<"sumNonTail: "<<sumNonTail(n, total)<<endl;

    return 0;
}
/*
Tail recursion performs computation before the recursive call and can reuse stack frames (optimized), 
while non-tail recursion does computation after the call and requires all stack frames to remain until unwinding, 
using more memory.
*/
