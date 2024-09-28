#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

void solve() {
    string n; cin >> n;
    int N = n.size();
    auto add_to_n = [&](int what) {
        string ws = to_string(what);
        if (ws.size() > N) {
            swap(n, ws);
            N = n.size();
        }

        string o(N, '.');
        string tmp = string(N-ws.size(), '0')+ws;
        bool carry = false;
        for (int i = N-1; i >= 0; i--) {
            int d = tmp[i]-'0' + n[i]-'0' + carry;
            carry = false;
            if (d >= 10) {
                carry = true;
                d -= 10;
            }
            o[i] = (char)(d+'0');
        }

        string res;
        if (carry) res += '1';
        res += o;
        return res;
    };
    n = add_to_n(1);
    N = n.size();

    int m; cin >> m;
    vi p10_mod = {1};
    while (p10_mod.size() < N) p10_mod.pb(10*p10_mod.back()%m);

    int ans = inf;
    int n_mod_m = 0;
    for (int i = 0; i < N; i++) {
        (n_mod_m += p10_mod[N-1-i]*(n[i]-'0')) %= m;
    }
    ckmin(ans, (m-n_mod_m)%m);
    
    int M = to_string(m).size();
    vi len_M_nums = {0};
    int next_p10 = 1;
    for (int i = M-1; i >= 0; i--) {
        next_p10 *= 10;
        if (N-1-i >= 0) {
            len_M_nums[0] *= 10;
            len_M_nums[0] += n[N-1-i]-'0';
        }
    }
    int max_p10 = next_p10/10;

    for (int i = 0; i < N-1; i++) {
        int& x = len_M_nums.emplace_back(len_M_nums.back());
        x /= 10;
        if (i+M < N)
            x += max_p10*(n[N-1-(i+M)]-'0');
    }

    int cur_p10 = 1;
    int pad = 0;
    for (int i = 0; i < len_M_nums.size(); i++) {
        int x = len_M_nums[i];
        int res = inf;
        if (x <= m) 
            ckmin(res, m-x);
        else
            ckmin(res, next_p10-x+m);

        if (!res) {
            ans = 0;
            break;
        }

        if (i < 15) {
            __int128 pls = res;
            pls *= cur_p10;
            pls -= pad;
            if (pls < ans)
                ans = pls;
        }
        if (i < 14) {
            pad += (n[N-1-i]-'0')*cur_p10;
            cur_p10 *= 10;
        }
    }

    // ps(len_M_nums);
    for (int i = 0; i < len_M_nums.size(); i++) if (len_M_nums[i] == m-1) {
        // [max(0, N-M-i), N-i)
        int j;
        for (j = N-i; j < N && n[j] == '9'; j++) ;
        if (N-j > 12) break;

        if (j == N) {
            if (ans > 1) ans = 1;
            continue;
        }
        int luv = 0;
        for (int k = j; k < N; k++) {
            luv *= 10; 
            luv += 9-(n[k]-'0');
        }
        luv++;
        ckmin(ans, luv);
    }

    cout << add_to_n(ans) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
