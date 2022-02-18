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
        //k mice, hole is at n
        int n, k; cin >> n >> k;
        vector<int> x(k);
        for (auto& i : x) cin >> i;
        sort(rall(x));

        ll total = 0;
        int ans = 0;

        while (ans < x.size() && total + n - x[ans] < n) total += n - x[ans++];

        cout << ans << '\n';
    }    
    
    return 0;
}

