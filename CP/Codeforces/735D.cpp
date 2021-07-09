#include <bits/stdc++.h>

using namespace std;

int n;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) if (!(x % i)) return false;
    return true;
}

int main() {
    cin >> n;
    if (isPrime(n)) cout << 1;
    else if (n & 1) cout << (isPrime(n - 2) ? 2 : 3);
    else cout << 2;
}
