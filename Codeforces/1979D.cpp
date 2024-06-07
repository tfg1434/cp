#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

int n, k;

bool check(const V<array<int, 2>>& blocks) {
    int nxt = blocks[0][0];
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i][0] != nxt || blocks[i][1] != k) return false;
        nxt ^= 1;
    }
    return true;
}

void solve() {
    string s;
    cin >> n >> k >> s;
    V<array<int, 2>> blocks;
    int i = 0, j = 0;
    while (i < n) {
        while (j < n && s[j] == s[i]) j++;
        blocks.pb({s[i]-'0', j-i});
        i = j;
    }
    vi pre(blocks.size()+1);
    for (int i = 0; i < blocks.size(); i++)
        pre[i+1] = pre[i]+blocks[i][1];

    auto [y, x] = blocks.back();
    if (x > k) {
        cout << "-1\n";
    } else if (x == k) {
        for (int i = 0; i < blocks.size()-1; i++) if (blocks[i][0] != y) {
            if (blocks[i][1] > k) {
                V<array<int, 2>> new_blocks;
                new_blocks.pb({blocks[i][0], blocks[i][1]-k});
                for (int j = i+1; j < blocks.size(); j++) new_blocks.pb(blocks[j]);
                new_blocks.pb({blocks[i][0], k});
                for (int j = i-1; j >= 0; j--) new_blocks.pb(blocks[j]);
                if (check(new_blocks)) {
                    cout << pre[i]+k << '\n';
                } else {
                    cout << "-1\n";
                }
                return;
            }
        }
        cout << (check(blocks) ? n : -1) << '\n';
    } else {
        for (int i = 0; i < blocks.size()-1; i++) if (blocks[i][0] == y){
            if (blocks[i][1] == k-x) {
                V<array<int, 2>> new_blocks;
                for (int j = i+1; j < blocks.size(); j++) new_blocks.pb(blocks[j]);
                new_blocks.back()[1] = k;
                for (int j = i-1; j >= 0; j--) new_blocks.pb(blocks[j]);
                if (check(new_blocks)) {
                    cout << pre[i+1] << '\n';
                } else {
                    cout << "-1\n";
                }
                return;
            } else if (blocks[i][1] == 2*k-x) {
                V<array<int, 2>> new_blocks;
                new_blocks.pb({blocks[i][0], k});
                for (int j = i+1; j < blocks.size(); j++) new_blocks.pb(blocks[j]);
                new_blocks.back()[1] = k;
                for (int j = i-1; j >= 0; j--) new_blocks.pb(blocks[j]);
                if (check(new_blocks)) {
                    cout << pre[i]+k-x << '\n';
                } else {
                    cout << "-1\n";
                }
                return;
            }
        }
        cout << "-1\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

