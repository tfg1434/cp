// ACMP.RU substring search

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int gen_base(const int l, const int r) {
    assert(r-l > 1);
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    int base = uniform_int_distribution<int>(l+1, r)(mt_rand);
    return base % 2 == 0 ? base - 1 : base;
}

struct polyhash {
    static const int mod = (int)1e9+123;
    static vector<int> pow1;
    static vector<u64> pow2;
    static int base;
    vector<int> pre1;
    vector<u64> pre2;
    polyhash(const string& s) : pre1(s.size()+1, 0), pre2(s.size()+1, 0) {
        assert(base < mod);
        while (pow1.size() <= s.size()) {
            pow1.push_back(1ll*pow1.back()*base%mod);
            pow2.push_back(pow2.back()*base);
        }
        for (int i = 0; i < s.size(); i++) {
            assert(base > s[i]);
            pre1[i+1] = (pre1[i] + 1ll*pow1[i]*s[i])%mod;
            pre2[i+1] = pre2[i] + pow2[i]*s[i];
        }
    }
    pair<int, u64> operator()(int l, int r, int max_pow = 0) {
        int hash1 = pre1[r] - pre1[l];
        if (hash1 < 0) hash1 += mod;
        u64 hash2 = pre2[r] - pre2[l];
        if (max_pow != 0) {
            hash1 = 1ll*hash1*pow1[max_pow-l-(r-l)+1]%mod;
            hash2 = hash2*pow2[max_pow-l-(r-l)+1];
        }
        return {hash1, hash2};
    }
};

int polyhash::base((int)1e9+7);
vector<int> polyhash::pow1{1};
vector<u64> polyhash::pow2{1};

void solve() {
    string src, search; cin >> src >> search;
    int n = src.size(), m = search.size();
    if (n < m) return;
    int max_pow = n;
    polyhash src_hash(src);
    pair<int, u64> need = polyhash(search)(0, m, max_pow);
    for (int i = 0; i <= n-m; i++) {
        if (src_hash(i, i+m, max_pow) == need) cout << i << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
