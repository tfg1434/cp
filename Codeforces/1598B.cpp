#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
constexpr int max_n = 1000;
int arr[max_n][5];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) continue;

            int c1 = 0, c2 = 0, cNo = 0;
            for (int k = 0; k < n; k++) {
                if (arr[k][i] == 1) c1++;
                if (arr[k][j] == 1) c2++;
                if (arr[k][i] == 0 && arr[k][j] == 0) cNo++;
            }

            if (c1 >= n/2 && c2 >= n/2 && cNo == 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        solve();
    }    
    
    return 0;
}

