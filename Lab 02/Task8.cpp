#include <iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter number of days: ";
    cin>>n;
    cout<<"Enter number of readings per day: ";
    cin>>m;
    float** temp = new float*[n];
    for(int i=0;i<n;i++){
        temp[i] = new float[m];
    }
    float* dailyAvg = new float[n];
    for(int i=0;i<n;i++){
        float sum=0;
        for(int j=0;j<m;j++){
            cout<<"Reading "<<j+1<<" for day "<<i+1<<": ";
            cin>>temp[i][j];
            sum+=temp[i][j];
        }
        dailyAvg[i] = sum/m;
    }
    cout << "Daily Average Temperatures:\n";
    for (int i=0;i<n;i++) {
        cout<<"Day "<< i+1<<": "<<dailyAvg[i]<<endl;
    }
    int hottest = 0, coldest = 0;
    for (int i = 1; i < n; i++){
        if (dailyAvg[i] > dailyAvg[hottest]){
            hottest = i;
        }
        if (dailyAvg[i] < dailyAvg[coldest]){
            coldest = i;
        }
    }
    cout<<"Hottest day: day "<<hottest+1<<endl;
    cout<<"Coldest day: day "<<coldest+1<<endl;
    for (int i = 0; i < n; i++){
        delete[] temp[i];
    }
    delete[] temp;
    delete[] dailyAvg;
    return 0;
}
