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
    
    ll n; while (cin >> n) {
        vector<ll> a(n);
        for (auto& x : a) cin >> x;

        if (n == 1) {
            cout << "1 1\n";
            cout << -a[0] << endl;
            cout << "1 1\n0\n";
            cout << "1 1\n0\n";
            continue;
        }

        cout << 1 << ' ' << n << endl;
        for (ll i = 0; i < n; i++) {
            ll res = a[i] % (n-1);
            a[i] -= res * n;
            cout << -res*n << ' ';
        }
        cout << endl;

        cout << 1 << ' ' << n-1 << endl;
        for (ll i = 0; i < n-1; i++) {
            ll res = -a[i];
            a[i] += res;
            cout << res << ' ';
        }
        cout << endl;

        cout << n << ' ' << n << endl;
        cout << -a[n-1] << endl;
    }
    
    return 0;
}

