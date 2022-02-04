#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> a(N);

        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        auto big = a.begin() + N - K;
        auto small = a.begin() + N - 2*K;
        int ans = 0;
        for ( ; big != a.end() ; ) {
            ans += *big == *small ? 1 : 0;

            big++; small++;
        }

        for (int i = 0; i < N - 2*K; ++i) {
            ans += a[i];
        }
        
        cout << ans << '\n';
    }

    return 0;
}
