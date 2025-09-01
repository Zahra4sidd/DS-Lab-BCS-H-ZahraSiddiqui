#include<iostream>
using namespace std;

int main(){
	int stu;
	cout<<"Enter the number of students: ";
	cin>>stu;
	int** arr = new int*[stu];
	int* cour = new int[stu];
	for(int i=0;i<stu;i++){
		cout<<"Enter the number of courses for student "<<i+1<<": ";
		cin>>cour[i];
		arr[i] = new int[cour[i]];
	}
	for(int i=0;i<stu;i++){
		cout<<"Enter "<<cour[i]<<" marks for student "<<i+1<<endl;
		for(int j=0;j<cour[i];j++){
			cin>>arr[i][j];
		}
	}
	float sum=0;
	float avg =0;
	for(int i=0;i<stu;i++){
		sum=0;
		avg=0;
		for(int j=0;j<cour[i];j++){
			sum += arr[i][j];
		}
		avg = sum/cour[i];
		cout<<"Average marks of student "<<i+1<<": "<<avg<<endl;
	}
	
	for(int i=0;i<stu;i++){
		delete[] arr[i];
	}
	delete[] arr;
}
