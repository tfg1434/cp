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
    if (n <= 2) {
        cout << 0 << endl;
    } else {
        cout << n - 1 << endl;
    }
    cout << 1 << endl;

    vector<ll> a(n+1);
    ll d = n-1;
    ll pos = 1;
    while (abs(d) > 1) {
        a[pos] = d;
        pos += d;
        d = -d;
        if (d > 0)d--;
        else d++;
    }
    if (n % 2) {
        a[pos] = 1;
        a[pos-1] = n;
    } else {
        a[pos] = -1;
        a[pos+1] = n;
    }

    for (ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}

