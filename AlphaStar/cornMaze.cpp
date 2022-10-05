#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll MAXR = 1e3+5;
//row, col
char maze[MAXR][MAXR];
constexpr ll N = 0, W = 1, S = 2, E = 3;
constexpr ll R = 0, F = 1, L = 2, B = 3;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll r, c; cin >> r >> c;

        auto valid = [&](ll x, ll y) {
            return x >= 0 && x < c && y >= 0 && y < r;
        };

        ll sx, sy, ex, ey;
        for (ll i = 0; i < r; i++) {
            for (ll j = 0; j < c; j++) {
                char ch; cin >> ch;
                maze[i][j] = ch;
                if (ch == 'S') sx = j, sy = i;
                if (ch == 'E') ex = j, ey = i;
            }
        }

        set<pll> seen;
        ll face = N;
        ll x = sx, y = sy;
        ll steps = 0;
        while (!(x == ex && y == ey) && steps < (ll)1e5) {
            steps++;
            ll dxr, dyr, dxf, dyf, dxl, dyl, dxb, dyb;
            if (face == N) {
                dxr = 1, dyr = 0;
                dxf = 0, dyf = -1;
                dxl = -1, dyl = 0;
                dxb = 0, dyb = 1;
            }
            if (face == S) {
                dxr = -1, dyr = 0;
                dxf = 0, dyf = 1;
                dxl = 1, dyl = 0;
                dxb = 0, dyb = -1;
            }
            if (face == E) {
                dxr = 0, dyr = 1;
                dxf = 1, dyf = 0;
                dxl = 0, dyl = -1;
                dxb = -1, dyb = 0;
            }
            if (face == W) {
                dxr = 0, dyr = -1;
                dxf = -1, dyf = 0;
                dxl = 0, dyl = 1;
                dxb = 1, dyb = 0;
            }
            vector<ll> dx = {dxr, dxf, dxl, dxb};
            vector<ll> dy = {dyr, dyf, dyl, dyb};

            for (ll i = R; i <= B; i++) {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if (valid (nx, ny) && maze[ny][nx] == '.') {
                    seen.insert({x, y});
                    x = nx, y = ny;
                    if (i == R) face = (face+4-1) % 4;
                    if (i == F) face = face;
                    if (i == L) face = (face + 1) % 4;
                    if (i == B) face = (face + 2) % 4;
                    
                    break;
                }
            }
            
            ll bbb = 5;
        }

        cout << ((x == ex && y == ey) ? "yes" : "no") << endl;
    }    
    
    return 0;
}

