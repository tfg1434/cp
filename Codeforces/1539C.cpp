#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(all(a));

    vector<ll> gaps;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > x) {
            gaps.push_back(max(0ll, a[i] - a[i - 1] - 1) / x);
        }        
    }
    sort(all(gaps));

    ll ans = 0;
    for (int i = 0; i < gaps.size(); i++) {
        if (k >= gaps[i]) {
            k -= gaps[i];
            ans++;

        } else break;
    }

    cout << gaps.size() - ans + 1 << '\n';
    
    return 0;
}

