#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N, H;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> H;
        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        
        int k = 0;
        vector<int> dt(N - 1);
        for (int i = 0; i < N - 1; i++) {
            dt[i] = a[i + 1] - a[i];
        }
        while (true) {
            int total = 0;
            for (int i = 0; i < N - 1; ++i) {
                total += min(k, dt[i]); 
            }
            total += k; //last hit
            
            if (total >= H) break;
            
            k++;
        }
        
        cout << k << '\n';
    }

    return 0;
}
