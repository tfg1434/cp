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
    
    ll n; cin >> n;
    vector<ll> h(n+1);
    for (ll i = 1; i <= n; i++) cin >> h[i];

    stack<ll> sk;
    sk.push(1); 
    vector<ll> ans(n+1, 0);
    for (ll i = 2; i <= n; i++) {
        while (!sk.empty() && h[i] > h[sk.top()]) {
            ans[sk.top()] = i;
            sk.pop();
        }

        sk.push(i);
    }
    while (!sk.empty()) {
        ans[sk.top()] = 0;
        sk.pop();
    }

    for (ll i = 1; i <= n; i++) cout << ans[i] << '\n';
    
    return 0;
}

