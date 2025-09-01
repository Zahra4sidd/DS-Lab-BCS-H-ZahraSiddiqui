#include <iostream>
using namespace std;

int main(){
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;
    int** salaries = new int*[departments];
    int* empCount = new int[departments];
    for (int i = 0; i < departments; i++) {
        cout << "Enter number of employees in department " << i + 1 << ": ";
        cin >> empCount[i];
        salaries[i] = new int[empCount[i]];
        cout << "Enter salaries for department " << i + 1 << ":\n";
        for (int j = 0; j < empCount[i]; j++) {
            cin >> salaries[i][j];
        }
    }
    for (int i = 0; i < departments; i++) {
        int maxSalary = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) {
            if (salaries[i][j] > maxSalary) {
                maxSalary = salaries[i][j];
            }
        }
        cout << "Highest salary in department " << i + 1 << " is " << maxSalary << "\n";
    }
    int maxAvgDept = 0;
    float maxAvgSalary = 0.0;
    for (int i = 0; i < departments; i++) {
        float sum = 0;
        for (int j = 0; j < empCount[i]; j++) {
            sum += salaries[i][j];
        }
        float avg = sum / empCount[i];
        if (avg > maxAvgSalary) {
            maxAvgSalary = avg;
            maxAvgDept = i;
        }
    }
    cout << "Department " << maxAvgDept + 1 << " has the maximum average salary of " << maxAvgSalary << "\n";

    for (int i = 0; i < departments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;

    return 0;
}
