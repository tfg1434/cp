#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


void yes() {
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        ll n, m, k; cin >> n >> m >> k;
        //n nodes, m edges, diam < k
        //each node after the first one has one more possible edges
        //max num edges = n(n-1) / 2
        ll total = n * (n - 1) / 2;

        //all nodes are connected
        if (m == total && k > 2) {
            yes();
            continue;
        }

        //it's a tree, diam is 2
        if (m < total && m >= n - 1 && k > 3) {
            yes();
            continue;
        }

        //single node
        if (n == 1 && m == 0 && k >= 2) {
            yes();
            continue;
        }

        cout << "NO" << endl;
    }    
    
    return 0;
}

