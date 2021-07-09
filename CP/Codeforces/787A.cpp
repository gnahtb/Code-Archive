#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    for (int x = 0; x <= 1000000; ++x)
        if (a * x + b >= d && !((a * x + b - d) % c)) {
            cout << a * x + b << "\n";
            return 0;
        }
    cout << "-1\n";
    return 0;
}
