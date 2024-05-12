// oops you don't need 2d segtree. i made an oopsie, thought largest rectangle is the max w x max h... this is wrong
// at least i learned how to write 2d segtree.

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define int int64_t
const int inf = 2e18;

int n, m, q;
vector<string> inp; 
vector<vector<int>> max_dim[2]; // h, w ie (x, y)
                                // n is the number of columns, m is the number of rows
vector<vector<int>> t, a;
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry-1) {
        if (lx == rx-1) {
            t[vx][vy] = a[lx][ly];
        } else {
            t[vx][vy] = t[2*vx+1][vy] + t[2*vx+2][vy];
        }
    } else {
        int my = (ly+ry)/2;
        build_y(vx, lx, rx, 2*vy+1, ly, my);
        build_y(vx, lx, rx, 2*vy+2, my, ry);
        t[vx][vy] = t[vx][2*vy+1] + t[vx][2*vy+2];
    }
}
void build_x(int vx, int lx, int rx) {
    if (lx < rx-1) {
        int mx = (lx+rx)/2;
        build_x(2*vx+1, lx, mx);
        build_x(2*vx+2, mx, rx);
    }
    build_y(vx, lx, rx, 0, 0, m);
}

int sum_y(int vx, int vy, int ly, int ry, int LY, int RY) {
    if (ry <= LY || RY <= ly) return 0;
    if (LY <= ly && ry <= RY) return t[vx][vy];
    int my = (ly+ry)/2;
    return sum_y(vx, 2*vy+1, ly, my, LY, RY) + sum_y(vx, 2*vy+2, my, ry, LY, RY);
}

int sum_x(int vx, int lx, int rx, int LX, int RX, int LY, int RY) {
    if (rx <= LX || RX <= lx) return 0;
    if (LX <= lx && rx <= RX) return sum_y(vx, 0, 0, m, LY, RY);
    int mx = (lx+rx)/2;
    return sum_x(2*vx+1, lx, mx, LX, RX, LY, RY) + sum_x(2*vx+2, mx, rx, LX, RX, LY, RY);
}

void init_tree() {
    int size_x = 1;
    while (size_x < 2*n) size_x *= 2;
    int size_y = 1;
    while (size_y < 2*m) size_y *= 2;
    t = vector<vector<int>>(size_x, vector<int>(size_y));
    build_x(0, 0, n);
}

void make_a() {
    a = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (inp[i][j] == '0') {
            cerr << max_dim[0][i][j] << ' ' << max_dim[1][i][j] << endl;
            // if (max_dim[0][i][j] == 4 && max_dim[1][i][j] == 2) {
                // cerr << i << ' ' << j << endl;
            // }
            a[max_dim[0][i][j]-1][max_dim[1][i][j]-1]++;
        }
    }
    // for (int j = 0; j < m; j++) {
        // for (int i = 0; i < n; i++) {
            // cerr << inp[i][j] << ' ';
        // }
        // cerr << endl;
    // }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cerr << a[i][j] << ' ';
        }
        cerr << endl;
    }
}

void precalc() {
    max_dim[0] = vector<vector<int>>(n, vector<int>(m));
    max_dim[1] = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        vector<int> s;
        for (int j = 0; j < m; j++) {
            if (inp[i][j] == '1') {
                while (s.size()) {
                    max_dim[1][i][s.back()] = j-s.back();
                    s.pop_back();
                }
            } else {
                s.push_back(j);
            }
        }
        while (s.size()) {
            max_dim[1][i][s.back()] = m-s.back();
            s.pop_back();
        }
    }

    for (int j = 0; j < m; j++) {
        vector<int> s;
        for (int i = 0; i < n; i++) {
            if (inp[i][j] == '1') {
                while (s.size()) {
                    max_dim[0][s.back()][j] = i-s.back();
                    s.pop_back();
                }
            } else {
                s.push_back(i);
            }
        }
        while (s.size()) {
            max_dim[0][s.back()][j] = n-s.back();
            s.pop_back();
        }
    }
}

void solve() {
    cin >> n >> m >> q; swap(n, m);
    inp = vector<string>(n, string(m, '*'));
    for (int j = 0; j < m; j++) {
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            inp[i][j] = s[i];
        }
    }
    precalc();
    make_a();
    init_tree();

    while (q--) {
        int Y, X; cin >> Y >> X; Y--; X--;
        cerr << X << ' ' << n << ' ' << Y << ' ' << m << endl;
        int ans = sum_x(0, 0, n, X, n, Y, m);
        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}



