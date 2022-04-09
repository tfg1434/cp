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


void solve() {
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (auto& x : a) {
        cin >> x;
        sum += x;
    }

    for (int k = n; k >= 1; k--) {
        if (sum % k != 0) continue;
        ll target = sum / k;
        //split into n-k subarrays, in which each subarray has sum target
        ll curr = 0;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            curr += a[j];
            if (curr > target) {
                ok = false;
                break;

            } else if (curr == target) {
                curr = 0;
            }
        }

        if (ok) {
            cout << n - k << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();
    }
    
    return 0;
}

