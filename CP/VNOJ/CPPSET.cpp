#include <bits/stdc++.h>

using namespace std;

struct SkipList {
    static const int LEVEL_MAX = 20;
    struct Node {
        struct Cell {
            Node *next, *prev;

            Cell(Node* _next = nullptr, Node* _prev = nullptr) {
                next = _next;
                prev = _prev;
            }
        };

        int value;
        vector<Cell> link;
    } *head, *tail;

    SkipList() {
        head = new Node;
        tail = new Node;

        head->value = INT_MIN;
        tail->value = INT_MAX;

        for (int i = 0; i < LEVEL_MAX; ++i) {
            head->link.emplace_back(tail, nullptr);
            tail->link.emplace_back(nullptr, head);
        }
    }

    bool empty() {
        return head->link[0].next == tail;
    }

    Node* lower_bound(int x) {
        Node* cur = head;
        for (int i = LEVEL_MAX - 1; i >= 0; --i)
            while (cur->link[i].next != tail && cur->link[i].next->value < x)
                cur = cur->link[i].next;
        return cur->link[0].next;
    }

    Node* upper_bound(int x) {
        Node* cur = head;
        for (int i = LEVEL_MAX - 1; i >= 0; --i)
            while (cur->link[i].next != tail && cur->link[i].next->value <= x)
                cur = cur->link[i].next;
        return cur->link[0].next;
    }

    void insert(int x) {
        Node* tmp = lower_bound(x);
        if (tmp != tail && tmp->value == x) return;

        Node* ins = new Node;
        ins->value = x;
        ins->link.emplace_back(nullptr, nullptr);
        while (ins->link.size() < LEVEL_MAX && rand() % 2 == 0)
            ins->link.emplace_back(nullptr, nullptr);

        Node* cur = head;
        for (int i = LEVEL_MAX - 1; i >= 0; --i) {
            while (cur->link[i].next != tail && cur->link[i].next->value < x)
                cur = cur->link[i].next;
            if (i < ins->link.size()) {
                ins->link[i].next = cur->link[i].next;
                ins->link[i].prev = cur;
                cur->link[i].next->link[i].prev = ins;
                cur->link[i].next = ins;
            }
        }
    }

    void erase(int x) {
        Node* era = lower_bound(x);
        if (era == tail || era->value != x) return;

        Node* cur = head;
        for (int i = LEVEL_MAX - 1; i >= 0; --i) {
            while (cur->link[i].next != tail && cur->link[i].next->value <= x)
                cur = cur->link[i].next;
            if (cur == era) {
                Node* pn = cur->link[i].prev;
                Node* nn = cur->link[i].next;
                pn->link[i].next = nn;
                nn->link[i].prev = pn;
            }
        }

        delete era;
    }
} sl;

int q, v;

void solve1() {
    cin >> v;
    sl.insert(v);
}

void solve2() {
    cin >> v;
    sl.erase(v);
}

void solve3() {
    if (sl.empty()) {
        cout << "empty\n";
        return;
    }
    cout << sl.head->link[0].next->value << "\n";
}

void solve4() {
    if (sl.empty()) {
        cout << "empty\n";
        return;
    }
    cout << sl.tail->link[0].prev->value << "\n";
}

void solve5() {
    cin >> v;
    if (sl.empty()) {
        cout << "empty\n";
        return;
    }
    auto it = sl.upper_bound(v);
    if (it == sl.tail) {
        cout << "no\n";
        return;
    }
    cout << it->value << "\n";
}

void solve6() {
    cin >> v;
    if (sl.empty()) {
        cout << "empty\n";
        return;
    }
    auto it = sl.lower_bound(v);
    if (it == sl.tail) {
        cout << "no\n";
        return;
    }
    cout << it->value << "\n";
}

void solve7() {
    cin >> v;
    if (sl.empty()) {
        cout << "empty\n";
        return;
    }
    auto it = sl.lower_bound(v)->link[0].prev;
    if (it == sl.head) {
        cout << "no\n";
        return;
    }
    cout << it->value << "\n";
}

void solve8() {
    cin >> v;
    if (sl.empty()) {
        cout << "empty\n";
        return;
    }
    auto it = sl.upper_bound(v)->link[0].prev;
    if (it == sl.head) {
        cout << "no\n";
        return;
    }
    cout << it->value << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> q) {
        if (q == 0) break;
        switch (q) {
            case 1: solve1(); break;
            case 2: solve2(); break;
            case 3: solve3(); break;
            case 4: solve4(); break;
            case 5: solve5(); break;
            case 6: solve6(); break;
            case 7: solve7(); break;
            case 8: solve8(); break;
        }
    }

    return 0;
}