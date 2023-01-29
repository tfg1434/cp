#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long


constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        string a, b; cin >> a >> b;

        if (a == b) {
            cout << 0 << endl;
            continue;
        }

        ll n = a.size();
        map<char, vector<ll>> mp;
        set<char> as; //set of a's of all to be changed
        map<char, char> chk;
        bool ok = true;

        for (ll i = 0; i < n; i++) {
            if (chk.count(a[i]) && chk[a[i]] != b[i]) {
                ok = false;
                break;
            }
            chk[a[i]] = b[i];

            if (a[i] == b[i]) continue;

            mp[b[i]].push_back(i);
            as.insert(a[i]);
        }

        if (!ok) {
            cout << -1 << endl;
            continue;
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;

            if (!as.count(b[i])) {
                //i is unique
                set<ll> cnt;
                cnt.insert(a[i]);
                for (ll j = 0; j < mp[b[i]].size(); j++) {
                    ll idx = mp[b[i]][j];
                    if (idx == i) continue;

                    as.erase(a[idx]);
                    cnt.insert(a[idx]);
                    a[idx] = b[i];
                }
                as.erase(a[i]);
                a[i] = b[i];
                ans += cnt.size();
            }
        }

        set<ll> bs;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            bs.insert(b[i]);
        }
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;

            if (!bs.count(a[i])) {
                //i is round
                set<ll> cnt;
                cnt.insert(a[i]);
                for (ll j = 0; j < mp[b[i]].size(); j++) {
                    ll idx = mp[b[i]][j];
                    if (idx == i) continue;

                    as.erase(a[idx]);
                    bs.erase(b[idx]);
                    cnt.insert(a[idx]);
                    a[idx] = b[i];
                }
                as.erase(a[i]);
                bs.erase(b[i]);
                a[i] = b[i];
                ans += cnt.size();
            }
        }
        set<pll> deleted;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            if (deleted.count({ a[i], b[i] })) continue;
            
            if (!as.count(b[i])) {
                ans++;
                as.erase(a[i]);
                deleted.insert({ a[i], b[i] });
                a[i] = b[i];
            }
        }

        if (as.size() > 0) {
            if (as.size() % 2 == 0) {
                ans += 3 * (as.size() / 2);
            } else {
                // ans += 3*(as.size()-1)/2 + 2;
                ans += 2*as.size() - 1;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
