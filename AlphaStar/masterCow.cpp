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
        vector<string> G(n);
        vector<ll> C(n), W(n);
        for (ll i = 0; i < n; i++) cin >> G[i] >> C[i] >> W[i];

        bool found = false;
        ll ans = -1;
        for (ll i = 1000; i <= 9999; i++) {
            string s = to_string(i);

            bool ok = true;
            for (ll j = 0; j < n; j++) {
                ll c = 0, w = 0;
                vector<ll> used;
                for (ll k = 0; k < 4; k++) {
                    if (s[k] == G[j][k]) {
                        c++;
                        used.push_back(k);
                    }
                }
                for (ll k = 0; k < 4; k++) {
                    if (count(all(used), k)) continue;
                    for (ll l = 0; l < 4; l++) {
                        if (s[l] == G[j][k] && count(all(used), l) == 0){
                            w++;
                            break;
                        }
                    }
                }
                  // cout << "---" << i << '\n';
                  // cout << c << ' ' << w << '\n';
                  // cout << C[j] << ' ' << W[j] << endl;
                if (c != C[j] || w != W[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                found = true;
                ans = i;
                break;
            }        
        }

        if (!found) {
            cout << "NONE\n";
        } else {
            cout << to_string(ans) << endl;
        }
    }
    
    return 0;
}

