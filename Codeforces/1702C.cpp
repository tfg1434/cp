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
        ll n, k; cin >> n >> k;
        vector<ll> u(n);
        for (auto& x : u) cin >> x;

        map<ll, ll> first, last;
        for (ll i = 0; i < n; i++) {
            if (!first.count(u[i])) first[u[i]] = i;
        }
        for (ll i = n - 1; i >= 0; i--) {
            if (!last.count(u[i])) last[u[i]] = i;
        }

        for (ll i = 0; i < k; i++) {
            ll a, b; cin >> a >> b;
            if (first.count(a) && last.count(b) && (first[a] <= last[b])) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }    
    
    return 0;
}

