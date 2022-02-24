#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ll K, N;


ll sum(ll a, ll b) {
    return (a+b) * (b-a+1) / 2;
}

bool ok(ll spd, ll endSpd, ll rem) {
    if (spd <= endSpd) return true;
    //from (S-1) to X. but you can exceed on last timestep
    ll need = sum(endSpd+1, spd-1) + 1;
    
    return need <= rem;
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K >> N;
    vector<ll> xs(N);
    for (auto& i : xs) cin >> i;

    //(S-1) + (S-2) + ... + X metres to completely stop
    for (ll i = 0; i < N; i++) {
        ll x = xs[i];
        ll spd = 0;
        ll rem = K;
        ll ans = 0;

        while (rem > 0) {
            if (ok(spd+1, x, rem - (spd+1))) spd++;
            else if (ok(spd, x, rem-spd)) {  }
            else spd--;

            assert(spd > 0);
            rem -= spd;
            ans++;
        }

        cout << ans << endl;
    }
    
    return 0;
}

