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
constexpr int MAXN = 2*1e5 + 5;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;
        ll h = 0, idx = 1;
        queue<ll> q;

        q.push(1);
        ll cnt = 1; //cnt = nodes in this height, x = nodes in next height
        while (!q.empty()) {
            ll x = 0;
            for (int i = 0; i < cnt; i++) {
                ll curr = q.front(); q.pop();

                ll prev = -1;
                while (idx < n) {
                    if (a[idx] < prev) break;
                    prev = a[idx]; q.push(a[idx]);
                    idx++; x++;
                }
            }

            cnt = x;
            if (q.size() != 0) h++;
        }

        cout << h << '\n';
    }    
    
    return 0;
}

