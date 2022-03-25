#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

struct Room {
    int x, y;
    vector<pii> children;
    bool checked = false;
    int component = -1;
};
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr int MAX_N = 105;
Room castle[MAX_N][MAX_N];
int roomSize[MAX_N * MAX_N];


void floodFill(int component, int x, int y) {
    if (castle[x][y].checked) {
        // assert("components equal" && component == castle[x][y].component);
        return;
    } 

    castle[x][y].checked = true;
    castle[x][y].component = component;
    roomSize[component]++;
    
    for (auto p : castle[x][y].children) {
        floodFill(component, p.first, p.second);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            castle[x][y].x = x;
            castle[x][y].y = y;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        x--, y--, a--, b--;
        castle[x][y].children.push_back( { a, b } );
    }
    int component = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!castle[x][y].checked) floodFill(component++, x, y);
        }
    }
    int ans = *max_element(roomSize, roomSize + sizeof roomSize / sizeof roomSize[0]);

    cout << ans << '\n';

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using pii = pair<int, int>;
// #define ll long long
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define IN(A, B, C) assert(B <= A && A <= C)

// constexpr int MOD = 1e9 + 7;
// constexpr int INF = 1e9;
// constexpr ll INFF = 1e18;
// vector<vector<bool>> mansion;


// int dfs(int x, int y, int cnt) {
    // cout << x << " " << y << " " << cnt << endl;
    // // if (!mp.count({x, y})) return cnt + 1;

    // if (mansion[x+1][y]) return dfs(x+1, y, cnt+1);
    // if (mansion[x-1][y]) return dfs(x-1, y, cnt+1);
    // if (mansion[x][y+1]) return dfs(x, y+1, cnt+1);
    // if (mansion[x][y-1]) return dfs(x, y-1, cnt+1);

    // return cnt + 1;
// }

// int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // int n, m; cin >> n >> m;
    // mansion = vector<vector<bool>>(n, vector<bool>(n, false));
    // for (int i = 0; i < m; i++) {
        // int x, y, a, b; cin >> x >> y >> a >> b;
        // x--, y--, a--, b--;
        // mansion[x][y] = true;
        // mansion[a][b] = true;
    // }

    // cout << dfs(0, 0, 0) << '\n';

    // return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// using pii = pair<int, int>;
// #define ll long long
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define IN(A, B, C) assert(B <= A && A <= C)

// struct Room {
    // vector<pii> children;
    // int component = -1;
    // bool checked = false;
// };
// constexpr int MOD = 1e9 + 7;
// constexpr int INF = 1e9;
// constexpr ll INFF = 1e18;
// Room mansion[105][105];
// int roomSize[105 * 105];


// void floodFill(int component, int x, int y) {
    // if (mansion[x][y].checked) return;

    // mansion[x][y].component = component;
    // mansion[x][y].checked = true;
    // roomSize[component]++;

    // for (auto [cx, cy] : mansion[x][y].children) {
        // if ((abs(x - cx) == 1) ^ (abs(y - cy) == 1)) {
            // floodFill(component, cx, cy);
        // }
    // }
// }

// int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // int n, m; cin >> n >> m;
    // for (int i = 0; i < m; i++) {
        // int x, y, a, b; cin >> x >> y >> a >> b;
        // mansion[x][y].children.emplace_back(a, b);
    // }
    // int component = 0;
    // for (int y = 0; y < n; y++) {
        // for (int x = 0; x < n; x++) {
            // if (!mansion[x][y].checked) floodFill(component++, x, y);
        // }
    // }
    // cout << *max_element(roomSize, roomSize + sizeof(roomSize) / sizeof(roomSize[0])) << '\n';
    
    // return 0;
// }

