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
    
    ll n; cin >> n;
    stack<ll> dirty, wet, clean;
    for (ll i = n; i >= 1; i--) {
        dirty.push(i);
    }

    ll c; while (cin >> c) {
        ll x; cin >> x;

        if (c == 1) {
            for (ll i = 0; i < x; i++) {
                wet.push(dirty.top());
                dirty.pop();
            }
        } else {
            for (ll i = 0; i < x; i++) {
                clean.push(wet.top());
                wet.pop();
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << clean.top() << '\n';
        clean.pop();
    }
    
    return 0;
}

