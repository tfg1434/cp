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
constexpr ll N = 1e5;


ll calc(ll n) {
    ll res = (n/3)*(n/3)*3; //3H^2
    
    for (ll i = 0; i <= n%3; i++) {
        res += (n / 3) * 2 + i;
    }

    return 2*res; //#tri = 2*#intersections at centre of hex
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        ll lo = 1, hi = 1e5;
        while (lo < hi) {
            ll mid = (lo+hi)/2;
            if (calc(mid) < n) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }

        cout << lo+1 << endl;
    }    
    
    return 0;
}

