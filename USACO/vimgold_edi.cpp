#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
typedef long long ll;
using namespace std;

const ll INF = 1e18;

struct Node {
    char value;
    ll size;
    Node *l, *r;

    void print_substring(ll start, ll end) {
        start = max(start, 1ll);
        end = min(end, size);
        if (start > end) {
            return;
        }
        if (value != '.') {
            cout << value;
        } else {
            l->print_substring(start, end);
            r->print_substring(start - l->size, end - l->size);
        }
    }
};

Node* current[26];
pair<char, string> operations[200000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll l, r;
    int n;
    cin >> l >> r >> n;
    for (int i = n - 1; i >= 0; i--) {
        cin >> operations[i].first >> operations[i].second;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        current[c - 'a'] = new Node{c, 1};
    }
    for (int i = 0; i < n; i++) {
        Node* result = nullptr;
        for (char c : operations[i].second) {
            Node* to_merge = current[c - 'a'];
            if (result == nullptr) {
                result = to_merge;
            } else {
                result = new Node{
                    '.',
                    min(INF, result->size + to_merge->size),
                    result,
                    to_merge
                };
            }
        }
        current[operations[i].first - 'a'] = result;
    }

    current[0]->print_substring(l, r);
    cout << '\n';
    return 0;
}

