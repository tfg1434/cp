// ACMP.RU 1159 Manacher's Algorithm
// MLE but I don't know why

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int gen_base(int l, int r) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    int base = uniform_int_distribution<int>(l+1, r)(mt_rand);
    if (base % 2 == 0) base--;
    return base;
}

struct polyhash {
    static const int mod = (int)1e9+123;
    static int base;
    static vector<int> pow1;
    static vector<u64> pow2;
    vector<int> pre1;
    vector<u64> pre2;
    polyhash(const string& s) : pre1(s.size()+1), pre2(s.size()+1) {
        assert(base < mod);
        while (pow1.size() <= s.size()) {
            pow1.push_back(1ll*pow1.back()*base%mod);
            pow2.push_back(pow2.back()*base);
        }
        for (int i = 0; i < s.size(); i++) {
            assert(s[i] < base);
            pre1[i+1] = (pre1[i] + 1ll*pow1[i]*s[i]) % mod;
            pre2[i+1] = pre2[i] + pow2[i]*s[i];
        }
    }
    pair<int, u64> operator()(int l, int r, int max_pow) {
        int hash1 = pre1[r] - pre1[l];
        if (hash1 < 0) hash1 += mod;
        u64 hash2 = pre2[r] - pre2[l];
        if (max_pow != 0) {
            hash1 = 1ll*hash1*pow1[max_pow-r+1]%mod;
            hash2 = hash2*pow2[max_pow-r+1];
        }
        return {hash1, hash2};
    }
};

int polyhash::base{(int)1e9+7};
vector<int> polyhash::pow1{1};
vector<u64> polyhash::pow2{2};

#define int int64_t

void solve() {
    string s; cin >> s;
    int n = s.size();
    polyhash hash(s);
    reverse(s.begin(), s.end());
    polyhash rev_hash(s);
    reverse(s.begin(), s.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int len = (lo+hi)/2;
            if (len == 0) {
                lo = len+1;
                continue;
            }
            if (i-len < 0 || i+len >= n) {
                hi = len;
                continue;
            }
            bool ok = hash(i-len, i, n) == rev_hash(n-1-i-len, n-1-i, n);
            ok ? lo = len+1 : hi = len;
        }
        ans += hi;
    }

    for (int i = 0; i < n-1; i++) if (s[i] == s[i+1]) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int len = (lo+hi)/2;
            if (len == 0) {
                lo = len+1;
                continue;
            }
            if (i-len < 0 || i+1+len >= n) {
                hi = len;
                continue;
            }
            bool ok = hash(i-len, i, n) == rev_hash(n-1-i-len-1, n-1-i-1, n);
            ok ? lo = len+1 : hi = len;
        }
        ans += hi;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
