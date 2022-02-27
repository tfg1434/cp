#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


int getIndex(vector<int> v, int val) {
    auto iter = find(all(v), val);
    return iter - v.begin();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    int ans = 0;
    while (a != b) {
        int idx = a.size()-1;
        while (idx <= getIndex(b, a[idx])) idx--;
        a.erase(a.begin() + idx);
        b.erase(b.begin() + getIndex(b, a[idx]));
//        for (auto x : a) cout << x << " ";
//        cout << endl;
//        for (auto x : b) cout << x << " ";
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}
