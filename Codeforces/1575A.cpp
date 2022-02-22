#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<pair<string, int>> v(n);
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        for (int j = 1; j < x.size(); j += 2) x[j] = 'Z' - x[j] + 'A';
        v[i] = {x, i};
    } 

    sort(all(v), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first < b.first;
    });

    for (auto [_, i] : v) cout << i + 1 << ' ';
    cout << '\n';
    
    return 0;
}

