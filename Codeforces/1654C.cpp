#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
        vector<ll> a(n);
        ll sum = 0;
        for (auto& x : a) cin >> x, sum += x;

        multiset<ll> b = { sum };
        multiset<ll> c(all(a));
        while (!b.empty()) {
            ll x = *--b.end(); //b.end() is one over the last element
            if (x < *--c.end()) break;

            b.erase(--b.end());
            if (c.find(x) != c.end()) {
                c.erase(c.find(x));
            } else {
                b.insert(x / 2);
                b.insert((x + 2 - 1) / 2);
            }
        }

        cout << (c.empty() ? "YES" : "NO") << '\n';
    }    
    
    return 0;
}

