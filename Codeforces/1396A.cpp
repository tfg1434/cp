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
    
    ll n;
    while (cin >> n) {
        vector<ll> a(n);
        for (auto& x : a) cin >> x;

        if (n == 1) {
            cout << "1 1\n0\n";
            cout << "1 1\n0\n";
            cout << "1 1\n" << -a[0] << '\n';
            continue;
        }

        cout << "1 1\n" << -a[0] << '\n';
        cout << "1 " << n << '\n' << "0 ";
        for (ll i = 1; i < n; i++) {
            cout << a[i] * -n << ' ';
        }
        cout << '\n';
        cout << "2 " << n << '\n';
        for (ll i = 1; i < n; i++) {
            cout << a[i] * (n-1) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

