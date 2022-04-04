#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
int n;
constexpr int MAX_SIEVE = 1e3+5;
vector<bool> isPrime(MAX_SIEVE, true);


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (ll i = 2; i*i <= MAX_SIEVE; i++) {
        if (isPrime[i])         
            for (ll j = i*i; j <= MAX_SIEVE; j += i)
                isPrime[j] = false;
    }

    cin >> n;
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = 1; ; j++) {
            ll val = binpow(i, j);
            if (val > n) break;
            ans.push_back(val);
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << endl;
    
    return 0;
}

