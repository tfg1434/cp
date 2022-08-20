#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        multiset<ll> a, b;
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            while (x%2==0) x/=2;
            a.insert(x);
        }
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            b.insert(x);
        }
        n = len(a);

        while (!b.empty()) {
            ll x = *b.rbegin();

            if (!a.count(x)) {
                if (x == 1) break;
                b.erase(b.find(x));
                b.insert(x/2);
                continue;
            } else {
                b.erase(b.find(x));
                a.erase(a.find(x));
            }
        }

        cout << (b.empty() ? "YES" : "NO") << '\n';

        // bool ans = true;
        // for (auto iter = b.rbegin(); iter != b.rend(); iter++) {
            // ll y = *iter;
            // if (a.count(y)) {
                // a.erase(y);
                // continue;
            // }
            // while (y != 1) {
                // y/=2;
                // if (a.count(y)) {
                    // a.erase(y);
                    // ans = true;
                    // break;
                // }
            // }
        // }
    }    
    
    return 0;
}

