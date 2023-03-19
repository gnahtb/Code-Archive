#include <bits/stdc++.h>

using namespace std;

void gen_test() {
    ofstream f("inp.txt");
    int n = rand() % 5 + 2;
    int m = rand() % 5 + 2;
    int c = rand() % 10 + 1;
    f << n << " " << m << " " << c << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            f << (rand() % 10 + 1) << " ";
        }
        f << endl;
    }
    f.close();
}

bool diff(string fn1, string fn2) {
    ifstream f1(fn1.c_str()), f2(fn1.c_str());
    while (!f1.eof() && !f2.eof()) {
        string s1, s2;
        getline(f1, s1);
        getline(f2, s2);
        if (s1 != s2) {
            f1.close();
            f2.close();
            return false;
        }
    }
    if (!f1.eof() || !f2.eof()) {
        f1.close();
        f2.close();
        return false;
    }
    f1.close();
    f2.close();
    return true;
}

int main() {
    srand(time(nullptr));
    for (int itest = 0; itest < 10000; ++itest) {
        gen_test();
        system("sol.exe <inp.txt >sol.txt");
        system("me.exe <inp.txt >me.txt");
        if (diff("sol.txt", "me.txt")) {
            cout << "ok" << endl;
        } else {
            cout << "crap!" << endl;
        }
    }
    return 0;
}
