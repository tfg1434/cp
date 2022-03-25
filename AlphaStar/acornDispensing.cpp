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
        assert("components equal" && component == castle[x][y].component);
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            castle[i][j].x = i;
            castle[i][j].y = j;
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

