#include <bits/stdc++.h>

using namespace std;

int da, db;

int main() {
    cin >> da >> db;
    if (da == db) {
        cout << da << "0 " << db << "1\n";
        return 0;
    }
    if (da + 1 == db) {
        cout << da << "9 " << db << "0\n";
        return 0;
    }
    if (da == 9 && db == 1) {
        cout << da << " " << db << "0\n";
        return 0;
    }
    cout << "-1\n";
    return 0;
}
