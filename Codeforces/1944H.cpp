#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

string make_str(vi a) {
    int n = a.size();
    string s(n, 'a');
    for (int i = 0; i < n; i++) s[i] += a[i]-1;
    return s;
}

void solve() {
    cout << "? aa" << endl;
    int p; cin >> p; p--;

    auto ask = [&](string s) -> array<int, 2> {
        reverse(all(s));
        int h = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            h *= p;
            h += s[i]-'a'+1;
        }
        cout << "? " << s << endl;
        int r; cin >> r;
        return {h, r};
    };

    auto [h1, r1] = ask(string(10, 'z'));
    int km = h1-r1;
    r1++;
    vi r1_base_p(10);
    for (int i = 10-1; i >= 0; i--) {
        r1_base_p[i] = r1%p;
        r1 /= p;
    }
    vi dif_base_p(10);
    for (int i = 0; i < 10; i++) {
        dif_base_p[i] = 26-r1_base_p[i];
    }

    int first_non_positive = 0;
    while (first_non_positive < 10 && dif_base_p[first_non_positive] >= 1) first_non_positive++;
    if (first_non_positive < 10) {
        for (int i = first_non_positive; i < 10; i++) {
            dif_base_p[i] = 26;
        }
        while (true) {
            first_non_positive--;
            dif_base_p[first_non_positive] -= 1;
            if (dif_base_p[first_non_positive] >= 1) {
                break;
            } else {
                dif_base_p[first_non_positive] = 26;
            }
        }
        for (int i = 0; i < 10; i++) assert(1 <= dif_base_p[i] && dif_base_p[i] <= 26);
    }
    auto [h2, r2] = ask(make_str(dif_base_p));
    int m = km-(h2-r2);

    cout << "! " << p << ' ' << m << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
