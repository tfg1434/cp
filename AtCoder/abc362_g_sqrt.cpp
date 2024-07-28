// O(nsqrtn) w/ a decent constant factor. TLE

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

vi zfun(const string& s) {
    int n = s.size();
    vi z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i-l], r-i);
        }
        while (i+z[i] <= n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i+z[i] > r) {
            l = i;
            r = i+z[i];
        }
    }
    return z;
}

const int N = 5e5, K = 700;
struct Trie {
    int cnt, sons[26];
    Trie() : cnt(0) {
        fill(all(sons), -1);
    }
} trie[K*K+1];
int tree_siz;

int count_freq(const string& s) {
    int n = s.size();
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (trie[cur].sons[c] == -1) return 0;
        cur = trie[cur].sons[c];
    }
    return trie[cur].cnt;
}

void solve() {
    string s; cin >> s;    
    int n = s.size();
    int q; cin >> q;
    vi ans(q);
    V<pair<string, int>> light;
    for (int i = 0; i < q; i++) {
        string t; cin >> t;
        int m = t.size();
        if (m <= K) {
            light.pb({t, i});
        } else {
            auto z = zfun(t+s);
            for (int i = m; i < m+n; i++) if (z[i] == m) ans[i]++;
        }
    }

    for (int b = 0; b <= (n-1)/K; b++) {
        for (int i = b*K; i < min(n, (b+1)*K); i++) {
            int cur = 0;
            tree_siz = 1;
            for (int j = i+1; j <= min(n, i+K); j++) {
                int c = s[j-1] - 'a';
                if (trie[cur].sons[c] != -1) {
                    cur = trie[cur].sons[c];
                } else {
                    trie[cur].sons[c] = tree_siz++;
                    cur = trie[cur].sons[c];
                }
                trie[cur].cnt++;
            }

            for (auto [t, ind] : light) {
                ans[ind] += count_freq(t);
            }
            while (tree_siz > 0) {
                tree_siz--;
                trie[tree_siz] = Trie();
            }
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
