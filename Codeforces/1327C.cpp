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
    
    ll n, m, k; cin >> n >> m >> k;
    cout << n*m+n+m-3 << endl;

    for (ll i = 0; i < n-1; i++) cout << "U";
    for (ll i = 0; i < m-1; i++) cout << "L";

    bool r = true;
    for (ll i = 0; i < n-1; i++) {
        for (ll j = 0; j < m-1; j++) cout << (r ? "R" : "L");
        r = !r;
        cout << "D";
    }
    for (ll j = 0; j < m-1; j++) cout << (r ? "R" : "L");
    
    return 0;
}

