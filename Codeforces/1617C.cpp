#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N;

void solve() {
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int ans = 0;

    for (int i = 0; i < a.size(); ++i) {
        int item = a[i];
        int n = i+1;

        if (item != n) {
            if (ceil(item/2.0) <= n) {
                cout << -1 << endl;
                return;
            }
            
            ans++;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve(); 
    }

    return 0;
}
