#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int fdiv(int x, int y) {
    return x/y - ((x^y)<0 && x%y);
}

const int INF = 2e18;
int n, q;
const int max_n = 200000;
vector<int> a, queries;
int ans[max_n+1];
int base_sum, base_mn, base_sum2, base_mn2;

void precomp() {
    multiset<int> old;
    for (auto x : a) old.insert(x);
    ans[0] = *begin(old);
    int off = 0;
    multiset<int> cur;
    for (int i = 0; i < n; i++) {
        old.erase(old.find(a[i]));
        cur.insert(a[i] - off);
        off++;
        ans[i+1] = off+(*begin(cur));
        if (old.size()) ans[i+1] = min(ans[i+1], *begin(old));
    }

    base_mn = base_mn2 = INF;
    for (int i = 0; i < n; i++) {
        base_mn = min(base_mn, a[i]+n-i);
        base_sum += a[i]+n-i;
        if (i < n-1) {
            base_sum2 += a[i]+n-i;
            base_mn2 = min(base_mn2, a[i]+n-i);
        }
    }
    base_sum2 += a.back(); // i put +1 and wasted a lot of time
}

int work(int k) {
    if (k <= n) return ans[k];
    if ((k-n) % 2 == 0) {
        int mn = base_mn + k-n;
        int sum = base_sum + (k-n)*n;
        int res = min(mn, fdiv(sum-(k-n)/2, n));
        return res;
    } else {
        int mn = min(a.back(), base_mn2 + k-n);
        int sum = base_sum2 + (k-n)*(n-1);
        int res = min(mn, fdiv(sum-(k-n+1)/2, n));
        return res;
    }
}

void solve() {
    cin >> n >> q;
    a.resize(n); for (auto& x : a) cin >> x;
    queries.resize(q); for (auto& x : queries) cin >> x;
    sort(begin(a), end(a));
    precomp();

    for (auto k : queries) cout << work(k) << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(0);
    solve();
}

