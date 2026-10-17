#include <iostream>
using namespace std;

int main() {
    int parking[10] = {0};
    int n;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int reg;
        cout << "Enter registration number: ";
        cin >> reg;

        int slot = reg % 10;
        int start = slot;

        while (parking[slot] != 0) {
            slot = (slot + 1) % 10;

            if (slot == start) {
                cout << "Parking lot is full. Vehicle " << reg << " cannot be parked.\n";
                break;
            }
        }

        if (parking[slot] == 0) {
            parking[slot] = reg;
        }
    }

    cout << "\nFinal parking lot:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (parking[i] == 0)
            cout << "Empty";
        else
            cout << parking[i];
        cout << endl;
    }

    return 0;
}