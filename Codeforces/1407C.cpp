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


ll ask(ll x, ll y) {
    cout << "? " << x+1 << " " << y+1 << endl;
    ll res; cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> ans(n);
    ll mx = 0;
    for (ll i = 1; i < n; i++) {
        ll a = ask(mx, i);
        ll b = ask(i, mx);
        if (a > b) { //mx < i
            ans[mx] = a;
            mx = i;
        } else {
            ans[i] = b; //i mod x
        }
    }

    ans[mx] = n;
    cout << "! ";
    for (ll x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}

