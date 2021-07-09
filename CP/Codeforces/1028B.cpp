#include <iostream>

using namespace std;

string a, b;

int main() {
    a = b = "5";
    for (int i = 0; i < 125; ++i) a = "9" + a, b = "0" + b;
    for (int i = 0; i < 125; ++i) b = "9" + b;
    cout << a << "\n" << b << "\n";
    return 0;
}
