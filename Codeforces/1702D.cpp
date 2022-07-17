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
        string w; cin >> w;
        ll n = len(w);
        ll p; cin >> p;

        vector<ll> cnt(26, 0);
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cnt[w[i] - 'a']++;
            sum += w[i] - 'a'+1;
        }

        ll mxIdx = 25;
        while (sum > p && mxIdx >= 0) {
            if (sum - cnt[mxIdx]*(mxIdx+1) > p) {
                sum -= cnt[mxIdx]*(mxIdx+1);
                cnt[mxIdx] = 0;
                mxIdx--;
            } else {
                while (sum > p) {
                    sum -= (mxIdx+1);
                    //could sum become negative? is it a problem?
                    cnt[mxIdx]--;
                }
                break;
            }
        }

        for (char c : w) {
            if (cnt[c - 'a'] > 0) {
                cnt[c - 'a']--;
                cout << c;
            }
        }
        cout<< endl;
    }    
    
    return 0;
}

