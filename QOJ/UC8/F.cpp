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

const int MAX_CNT = 10;
int cnt[MAX_CNT];

void solve() {
    int n; cin >> n;    

    V<string> ss(n);
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> ss[i] >> a[i]; a[i]--;
        cnt[a[i]]++;
    }

    string ans;
    for (int i = 0; i < n; i++) {
        string s = ss[i];
        int rank = 1;
        for (int j = a[i]+1; j < MAX_CNT; j++) rank += cnt[j];
        int pre_len = max(0, (int)s.size()-rank);
        ans += s.substr(0, pre_len);
    }
    ans[0] -= 32;
    cout << "Stage: " << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
