#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = (a[i] + a[i]) % n;
    set<int> s(all(c));
    if (s.size() == n) {
        for (int i = 0; i < 2; i++) {
            for (auto x : a) cout << x << " ";
            cout << endl;
        }
        for (auto x : c) cout << x << " ";

    } else {
        cout << -1;
    }

    cout << endl;
    
    return 0;
}

