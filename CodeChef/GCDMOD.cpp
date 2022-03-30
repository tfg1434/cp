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
ll a, b, n;


ll binpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        b >>= 1;
        a = a * a % m;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> a >> b >> n;

        if (a == b) {
            cout << (binpow(a, n) + binpow(b, n)) % MOD << '\n';
            continue;
        }

        ll res = abs(a - b);
        vector<ll> divs;
        //find all divisors
        for (ll i = 1; i * i <= res; i++) {
            if (res % i == 0) {
                if (i*i == res) divs.push_back(i);
                else divs.push_back(i), divs.push_back(res / i);
            } 
        }
        sort(rall(divs));

        for (int i = 0; i < divs.size(); i++) {
            ll x = divs[i];
            if ((binpow(a, n, x) + binpow(b, n, x)) % x == 0) {
                cout << x%MOD << '\n';
                break;
            }
        }
    }    
    
    return 0;
}

