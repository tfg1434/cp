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
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(all(a));

        vector<int> ans(n);
        for (auto& x : ans) x = 0;
        int c = 1;
        for (int i = 0; i < n; i++) {
            ans[a[i].second] = c;

            c++;
            if (c > k) {
                c = 1;
                while (a[i].first == a[i-1].first) {
                    i++;
                }
            }
        }

        for (auto& x : ans) cout << x << " ";
        cout << '\n';
    }    
    
    return 0;
}

