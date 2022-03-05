#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
multiset<ll> a, b;


bool check(int ca, int cb) {
    priority_queue<int> pqa(all(a)), pqb(all(b));
    int va = 0, vb = 0;
    int take = ca - ca/4;

    for (int i = 0; i < ca - cb; i++) pqa.push(100);
    for (int i = 0; i < take && !pqa.empty(); i++) {
        va += pqa.top();
        pqa.pop();
    }
    for (int i = 0; i < take && !pqb.empty(); i++) {
        vb += pqb.top();
        pqb.pop();
    }

    return va >= vb;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        a.clear(); b.clear();
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.insert(x);
        }

        if (check(n, n)) {
            cout << 0 << '\n';
            continue;
        }

        int ans = INT_MAX;
        int lo = n+1, hi = 2*n;
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            if (check(mid, n)) {
                hi = mid - 1;
                ans = min(ans, mid);
            }
            else lo = mid + 1;
        }

        cout << ans - n << '\n';
    }    
    
    return 0;
}

