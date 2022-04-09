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
ll n;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n;
        vector<ll> h(n);
        for (auto& x : h) {
            cin >> x;
        }
        ll mx = *max_element(all(h));

        ll day = 0;
        while (h.size() != 0) {
            day++;
            for (auto x : h) cout << x << " "; cout << endl;
            for (int i = 0; i < h.size(); ++i) {
                ll x = h[i];
                if (x == mx){
                    h.erase(h.begin() + i);
                    continue;
                }

                if (day % 2 == 1) {
                    if (mx - x != 2) {
                        h[i]++;
                        break;
                    }
                } else {
                    if (mx - x >= 2) {
                        h[i] += 2;
                        break;
                    }
                }
            }

        }

        cout << day << '\n';
    }    
    
    return 0;
}

