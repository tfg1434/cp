#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, q;
    cin >> n >> q;
    vector<ll> stations;
    for(ll i = 0; i < q; i++){
        ll t = i + 1;
        vector<ll> gaps;
        ll x;
        cin >> x;
        stations.push_back(x);
        sort(stations.begin(), stations.end());
        gaps.push_back(stations[0]);
        for(ll j = 0; j < stations.size() - 1; j++){
            gaps.push_back(stations[j + 1] - stations[j]);
        }
        gaps.push_back(n - stations[stations.size() - 1]);
        bool works = true;
        for(ll i = 0; i < gaps.size(); i++){
            if(gaps[i] > t){
                works = false;
                cout << -1 << "\n";
                break;
            }
        }
        if(!works){
            continue;
        }
        ll cur = 0;
        ll ans = 0;
        ans = stations[0];
        cur = stations[0];
        for(ll j = 1; j < stations.size(); j++){
            if((long long)ans % t > t - (stations[j] - cur)){
                ans += (t - (ans % t));
            }



            ans += stations[j] - cur;
            cur = stations[j];
        }
        if((ll)ans % t > t - (n - stations.back())){
            ans += (t - (ans % t));
        }
        ans += n - cur;
        cur = n;
        cout << ans << "\n";
    }
    
    return 0;
}
