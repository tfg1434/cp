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
        ll n; cin >> n;

        if (n == 1) {
            cout << "-1\n";
            ll _; cin >> _;
            continue;
        }

        vector<ll> a(n);
        for (auto& x : a) cin >> x;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (auto& x : a) pq.push(x);
        vector<ll> ans(n);
        for (ll i = 0; i < n; i++) {
            ll x = pq.top(); pq.pop();
            
            if (x != a[i] || i == n-1) {
                ans[i] = x;
            } else {
                ans[i] = pq.top(); pq.pop();
                pq.push(x);
            }
        }

        if (ans[n-1] == a[n-1])
            swap(ans[n-1], ans[n-2]);

        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
    }    
    
    return 0;
}

