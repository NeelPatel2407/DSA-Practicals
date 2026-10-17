#include <iostream>
using namespace std;

int main() {
    int table[10] = {0};
    int n;

    cout << "Enter number of student IDs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int slot = h1;
        int count = 0;

        while (table[slot] != 0 && count < 10) {
            count++;
            slot = (h1 + count * h2) % 10;
        }

        if (count == 10) {
            cout << "Hash table is full. ID " << id << " cannot be inserted.\n";
        } else {
            table[slot] = id;
        }
    }

    cout << "\nFinal hash table:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (table[i] == 0)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}