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


ll GCD(ll x, ll y) {
    while ((x%=y) && (y%=x));
    return x+y;
}

//thanks for using an ancient version Online Judge
ll LCM(ll x, ll y) { return x / GCD(x, y) * y; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    while (cin >> n >> m) {
        vector<ll> ms(m);
        for (auto& x : ms) cin >> x;

        ll ans = 0;
        //smart way to consider all possible combinations
        //of lcm by using a bitset
        for (int i = 1; i < (1 << m); i++) {
            ll lcm = 1ll, cnt = 0ll;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    lcm = LCM(lcm, ms[j]);
                    if (lcm > n) break;
                    cnt++;
                }
            }

            if (cnt%2==1) ans += n/lcm;
            else ans -= n/lcm;
        }

        cout << n - ans << endl;
    }
    
    return 0;
}

