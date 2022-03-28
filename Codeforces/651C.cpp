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

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
 
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int, ll> cx, cy;
    map<pii, ll> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cx[x]++;
        cy[y]++;
        mp[{x, y}]++;
    }

    ll ans = 0;
    auto iter = cx.begin();
    while (iter != cx.end()) {
        //choose
        ans += (iter->second * (iter->second - 1)) / 2;
        iter++;
    }
    iter = cy.begin();
    while (iter != cy.end()) {
        ans += (iter->second * (iter->second - 1)) / 2;
        iter++;
    }

    //mp is frequency array of (x, y)
    auto iter2 = mp.begin();
    while (iter2 != mp.end()) {
        ans -= (iter2->second * (iter2->second - 1)) / 2;
        iter2++;
    }

    cout << ans << endl;


    // map<int, int> cx, cy;
    // set<pii> st;
    // for (int i = 0; i < n; i++) {
        // int x, y; cin >> x >> y;
        // cx[x]++; cy[y]++;
        // st.insert({x, y});
    // }

    // int ans = 0;
    // set<pii> used;
    // for (auto [x, y] : st) {
        // if (cx[x] == 1) continue;
        // ans += nCr(cx[x], 2);
        // used.insert({x, y});
    // }
    // for (auto [x, y] : st) {
        // if (cy[y] == 1) continue;
        // ans += nCr(cy[y], 2);
        // if (used.count({ x, y })) ans--;
    // }

    // cout << ans << endl;
    
    return 0;
}

