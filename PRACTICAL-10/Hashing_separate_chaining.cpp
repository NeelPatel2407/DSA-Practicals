#include <iostream>
using namespace std;

struct Node {
    int code;
    Node* next;
};

int main() {
    Node* shelves[10] = {nullptr};
    int n;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code;
        cout << "Enter book code: ";
        cin >> code;

        int shelf = code % 10;

        Node* newBook = new Node;
        newBook->code = code;
        newBook->next = shelves[shelf];
        shelves[shelf] = newBook;
    }

    cout << "\nFinal contents of shelves:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        Node* temp = shelves[i];

        if (temp == nullptr) {
            cout << "Empty";
        }

        while (temp != nullptr) {
            cout << temp->code << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    return 0;
}