#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;

struct polyhash {
    static const int mod = (int)1e9+123;
    static const int base = (int)1e9+7;
    static vector<int> pow1;
    static vector<u64> pow2;
    vector<int> pre1;
    vector<u64> pre2;
    polyhash(const vector<int>& a) : pre1(a.size()+1), pre2(a.size()+1) {
        while (pow1.size() <= a.size()) {
            pow1.push_back(1ll*pow1.back()*base%mod);
            pow2.push_back(pow2.back()*base);
        }
        for (int i = 0; i < a.size(); i++) {
            pre1[i+1] = (pre1[i] + 1ll*a[i]*pow1[i]) % mod;
            pre2[i+1] = pre2[i]+a[i]*pow2[i];
        }
    }
    pair<int, u64> operator()(int l, int r, int max_pow) {
        int hash1 = pre1[r]-pre1[l];
        if (hash1 < 0) hash1 += mod;
        u64 hash2 = pre2[r]-pre2[l];
        if (max_pow > 0) {
            hash1 = 1ll*hash1*pow1[max_pow-r+1]%mod;
            hash2 *= pow2[max_pow-r+1];
        }
        return {hash1, hash2};
    }
};

// hack
pair<int, u64> operator - (pair<int, u64> x, pair<int, u64> y) {
    pair<int, u64> res = {x.first - y.first, x.second - y.second};
    if (res.first < 0) res.first += polyhash::mod;
    return res;
}
pair<int, u64> operator - (pair<int, u64> x) {
    auto res = pair<int, u64>{-x.first, -x.second};
    if (res.first < 0) res.first += polyhash::mod;
    return res;
}

vector<int> polyhash::pow1 {1};
vector<u64> polyhash::pow2 {1};

int n, m;
vector<int> a, b;

void solve() {
    cin >> n >> m;
    a.resize(n); b.resize(m);
    for (auto&x : a) cin >> x;
    for (auto&x : b) cin >> x;
    if (n > m) {
        swap(n, m);
        swap(a, b);
    }
    reverse(begin(a), end(a));
    polyhash rev_hash_a(a);
    reverse(begin(a), end(a));
    polyhash hash_a(a);
    reverse(begin(b), end(b));
    polyhash rev_hash_b(b);
    reverse(begin(b), end(b));
    polyhash hash_b(b);

    int ans = 0;
    {
        int lo = 1, hi = n;
        while (lo < hi) {
            int len = (lo+hi)/2;
            auto calc_a = [&](int i, int len) {
                return hash_a(i+1, i+len+1, m) - rev_hash_a(n-1 - (i) + 1, n-1 - (i-len) + 1, m);
            };
            auto calc_b = [&](int i, int len) {
                return hash_b(i+1, i+len+1, m) - rev_hash_b(m-1 - (i) + 1, m-1 - (i-len) + 1, m);
            };

            set<pair<int, u64>> st;
            for (int i = 0; i < n; i++) {
                if (i-len < 0 || i+len >= n) continue;
                st.insert(calc_a(i, len));
            }

            bool found = false;
            for (int i = 0; i < m; i++) {
                if (i-len < 0 || i+len >= m) continue;
                auto dif = -calc_b(i, len);
                if (st.count(dif)) found = true;
            }

            found ? lo = len+1 : hi = len;
        }

        ans = max(ans, 2*hi - 1);
    }
    {
        int lo = 1, hi = n;
        while (lo < hi) {
            int len = (lo+hi)/2;
            auto calc_a = [&](int i, int len) {
                return hash_a(i+1, i+1+len, m) - rev_hash_a(n-1 - (i+1) + 1, n-1 - (i-len+1) + 1, m);
            };
            auto calc_b = [&](int i, int len) {
                return hash_b(i+1, i+1+len, m) - rev_hash_b(m-1 - (i+1) + 1, m-1 - (i-len+1) + 1, m);
            };

            set<pair<int, u64>> st;
            for (int i = 0; i < n-1; i++) {
                if (i-len+1 < 0 || i+len >= n) continue;
                st.insert(calc_a(i, len));
            }

            bool found = false;
            for (int i = 0; i < m-1; i++) {
                if (i-len+1 < 0 || i+len >= m) continue;
                auto dif = -calc_b(i, len);
                if (st.count(dif)) found = true;
            }

            found ? lo = len+1 : hi = len;
        }

        ans = max(ans, 2*(hi-1));
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
