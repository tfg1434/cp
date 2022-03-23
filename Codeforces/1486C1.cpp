#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int query(int l, int r) {
    if (l >= r) return -1;

    cout << "? " << l+1 << " " << r+1 << endl;
    int pmax; cin >> pmax;

    return pmax - 1;//0-indexed
}

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(0);

    int n; cin >> n;
    int l = 0, r = n;

    while (r - l > 1) {
        int mid = (l+r)/2;
        int pmax = query(l, r-1);
        
        if (pmax < mid) {
            if (query(l, mid-1) == pmax) r = mid;
            else l = mid;
        } else {
            if (query(mid, r - 1) == pmax) l = mid;
            else r = mid;
        }
    }

    cout << "! " << r << endl;
    
    return 0;
}

