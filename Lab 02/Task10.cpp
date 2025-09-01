#include <iostream>
using namespace std;
int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;
    int* bookCounts = new int[categories];
    int** books = new int*[categories];
    for (int i = 0; i < categories; i++) {
        cout << "Enter number of books in Category " << i + 1 << ": ";
        cin >> bookCounts[i];
        books[i] = new int[bookCounts[i]];
        cout << "Enter " << bookCounts[i] << " book IDs: ";
        for (int j = 0; j < bookCounts[i]; j++) {
            cin >> books[i][j];
        }
    }
    int searchID;
    cout << "Enter book ID to search: ";
    cin >> searchID;
    bool found = false;
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < bookCounts[i]; j++) {
            if (books[i][j] == searchID) {
                cout << "Book ID " << searchID << " is available in Category " << i + 1 << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Book ID " << searchID << " not found in the library.\n";
    }
    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] bookCounts;
    return 0;
}
