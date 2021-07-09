#include <iostream>

using namespace std;

int q, n;

int main() {
    cin >> q;
    while (q--) {
        cin >> n;
        if (n == 2) cout << "2\n";
        else cout << n % 2 << "\n";
    }
    return 0;
}
