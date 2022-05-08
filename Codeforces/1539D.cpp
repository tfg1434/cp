#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

struct Prod {
    ll a, b, idx;
};
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; while (cin >> n) {
        vector<Prod> ps(n);
        for (ll i = 0; i < n; i++) {
            cin >> ps[i].a >> ps[i].b;
            ps[i].idx = i+1; 
        }
        sort(all(ps), [](Prod a, Prod b) { return a.b < b.b; });

        ll cnt = 0, ans = 0;
        ll l = 0, r = n-1;
        while (l < r) {
            cout << l << ' ' << r << endl;
            //cnt >= b_l. no point leave, buy em' all
            if (cnt > ps[l].b) {
                cnt += ps[l].a;
                ans += ps[l].a;
                l++;

            //cnt < b_l, use right pointer and buy min(b_l - cnt, a_r)
            //products at price 2 rubles. but if cnt >= b_r, buy for 
            //price 1 ruble.
            //finally, if a_r == 0 decrement r
            //don't need to re-sort because buying affects a, not b
            } else {
                while (l < r && cnt + ps[r].a <= ps[l].b) {
                    if (cnt >= ps[r].b) {
                        ans += ps[r].a;
                    } else if (cnt + ps[r].a > ps[r].b) {
                        ans += 2 * (ps[r].b - cnt) + cnt + ps[r].a - ps[r].b;
                    }  else {
                        ans += 2 * ps[r].a;
                    }

                    cnt += ps[r].a;
                    ps[r].a = 0;
                    r--;
                }
                if (l >= r) break;
                if (cnt == ps[l].b) continue;
                else {
                    ll take = ps[l].b - cnt;
                    if (cnt >= ps[r].b) ans += take;
                    else if (cnt + take > ps[r].b) {
                        ans += 2 * (ps[r].b - cnt) + cnt + take - ps[r].b;
                    } else {
                        ans += 2 * take;
                    }

                    cnt += take;
                    ps[r].a -= take;
                }
            }
        }

        ll take = ps[l].a;
        if (cnt >= ps[l].b) ans += take;
        else if (cnt + take > ps[l].b) {
            ans += 2 * (ps[l].b - cnt) + cnt + take - ps[l].b;
        } else {
            ans += 2 * take;
        }

        cnt += take;
        ps[l].a = 0;
        cout << ans << endl;
    }        
    
    return 0;
}

