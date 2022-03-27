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
vector<int> a;
map<int, vector<int>> mp;
int n, k;


bool makeMetal(int metal) {
    for (auto x : mp[metal]) {
        if (a[x] != 0) {
            a[x]--;
        } else {
            if (makeMetal(x)) {
                a[x]--;
            } else return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    a = vector<int>(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, m; cin >> l >> m;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            mp[l].push_back(x);
        }
        sort(all(mp[l]));
    }

    int ans = 0;
    //initial check

    while (true) {
        int mn = INF, mnMetal = -1;
        for (auto x : mp[n]) {
            //loop through ingredients to make N
            if (a[x] < mn) {
                mn = a[x];
                mnMetal = x;
            }
        }
        // cout << mnMetal << " " << mn << endl;

        bool ok = true;
        for (auto x : mp[mnMetal]) {
            //loop through ingredients to make the metal
            //we have the least of
            if (!makeMetal(x)) {
                ok = false;
                break;
            }
        }
        if (!ok) break;

        //check how much metal N we can make now
        int cnt = INF;
        for (auto x : mp[n]) {
            cout << x << " " << a[x] << endl;
            cnt = min(cnt, a[x]);
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    
    return 0;
}

