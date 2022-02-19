#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;

        int idx = n-1;
        int ans = 0;
        while (true) {
            bool found = false;
            for (int i = idx-1; i >= 0; i--) {
                if (a[i] > a[idx]) {
                    idx = i;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << ans << '\n';
                break;
            }

            ans++;
        }
    }    
    
    return 0;
}

