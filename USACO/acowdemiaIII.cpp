#include <bits/stdc++.h>
using namespace std;
using Cow = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int arr[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            arr[i][j] = c;
        }
    }
    int ans = 0;
    set<vector<Cow>> ss;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 'G') continue;
            vector<Cow> v;

            for (int k = 0; k < 4; k++) {
                int x = j + dx[k], y = i + dy[k];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;

                if (arr[y][x] == 'C') 
                    v.push_back({x, y});
            }

            if (v.size() > 2) 
                ans++;
            else if (v.size() == 2) {
                sort(all(v));
                ss.insert(v);
            } 
        }
    }

    cout << ans + ss.size() << endl;
    
    return 0;
}

