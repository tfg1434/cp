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
constexpr int MAX_N = 1e5 + 5;
int ans[MAX_N];
int sum, lim;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> sum >> lim;
    int tot = 0;

    for (int i = lim; i >= 1; i--) {
        if (i % 2 == 0) {
            int cnt = 0;
            for (int j = i; !(j & 1); j >>= 1) cnt++;
            int lowbit = pow(2.0, cnt);
            if (sum - lowbit >= 0) {
                sum -= lowbit;
                ans[i] = 1;
                tot++;
            }
        } else {
            //odd has lowbit of 1
            sum--;
            ans[i] = 1;
            tot++;
        }

        if (sum == 0) break;
    }

    if (sum != 0) {
        cout << -1 << endl;
    } else {
        cout << tot << endl;
        for (int i = 1; i <= lim; i++) {
            if (ans[i]) cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}

