#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto& x : a) {
        cin >> x;
        x -= 2;
        sum += x;
    }

    vector<pll> s;
    while (sum > 0) {
        ll l = -1;
        for (ll i = 0; i < n; i++) {
            if (a[i] > 0 && l == -1) {
                l = i;
            }

            if (i == n-1 || a[i+1] == 0) {
                if (l == -1) {
                    sum = 0;
                    while (a[n-1] >= 2) {
                        s.push_back({ n-1, n-1 });
                        a[n-1] -= 2;
                    }
                    break;
                }

                ll rem = 0;
                for (ll j = l; j <= i; j++) {
                    a[j] -= 2;
                    rem += 2;
                }

                s.push_back({ i, l });
                sum -= rem;
                break;
            }
        }
    }

    sort(all(s), [](pll a, pll b) -> bool {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });
    ll idx = 0, pos = 0;
    while (idx < s.size()) {
        if (pos <= s[idx].first) {
            cout << 'R';
            pos++;
        } else {
            ll cnt = s[idx].first - s[idx].second + 1;
            cout << string(cnt, 'L');
            cout << string(cnt, 'R');
            idx++;
        }
    }
    cout << string(pos, 'L');
    
    return 0;
}
