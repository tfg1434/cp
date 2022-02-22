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
        vector<int> v(3); cin >> v[0] >> v[1] >> v[2];
        sort(all(v));
        int a = v[0], b = v[1], c = v[2];
        int m; cin >> m;
        int mx = a-1+b-1+c-1;
        int mn = c - 1 - a - b;
        if (mx >= m && m >= mn) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
    
    return 0;
}

