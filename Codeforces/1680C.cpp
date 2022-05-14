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
    
    int T; cin >> T; while (T--) {
        string s; cin >> s;
        ll n = s.size();
        vector<ll> pos;
        for (ll i = 0; i < n; i++) {
            if (s[i] == '1') pos.push_back(i);
        }

        auto can = [&](ll m) {
            ll k = pos.size();
            ll x = k - m;

            for (ll i = 0; i <= m; i++) {
                ll l = pos[i], r = pos[i + x - 1];
                if (r - l + 1 - x <= m) return true;
            }

            return false;
        };

        ll lo = 0, hi = pos.size();
        while (hi - lo > 1) {
            ll mid = (lo+hi)/2;
            if (can(mid)) hi = mid;
            else lo = mid;
        }

        //no 1s or 1 strip of ones (remove 0s around)
        if (pos.size() == 0 || pos.back() - pos[0] == pos.size() - 1) {
            cout << 0 << endl;
        } else {
            cout << hi << endl;
        }
    }    
    
    return 0;
}

