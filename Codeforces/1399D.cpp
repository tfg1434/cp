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
        ll n; cin >> n;
        string s; cin >> s;
        vector<ll> ans(n);
        vector<ll> end0, end1;
        for (ll i = 0; i < n; i++) {
            ll pos = end0.size() + end1.size();

            if (s[i] == '0') {
                if (end1.empty()) {
                    end0.push_back(pos);
                } else {
                    pos = end1.back();
                    end1.pop_back();
                    end0.push_back(pos);
                }
            } else if (s[i] == '1') {
                if (end0.empty()) {
                    end1.push_back(pos);
                } else {
                    pos = end0.back();
                    end0.pop_back();
                    end1.push_back(pos);
                }
            }

            ans[i] = pos;
        }

        cout << end0.size() + end1.size() << '\n';
        for (auto x : ans) cout << x+1 << ' ';
        cout << '\n';
    }    
    
    return 0;
}

