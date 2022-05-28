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
string _;
set<string> opts[35];
int GetIndex(set<string> S, string K)
{
 
    // To store the index of K
    int Index = 0;
 
    // Traverse the Set
    for (auto u : S) {
 
        if (u == K)
            return Index;
 
        Index++;
    }
 
    // If K is not present
    // in the set
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k; cin >> n >> k;

    ll adjs = 0;
    vector<vector<string>> raw(n);
    for (ll i = 0; i < n; i++) {
        cin >> _ >> _ >> _ >> _;

        string word;
        ll j = 0;
        while (cin >> word && word != "acorn.") {
            opts[j].insert(word);
            j++;
            // cout << word << endl;
            raw[i].push_back(word);
            if (i == 0) adjs++;
        }
    }

    vector<vector<ll>> processed(n);
    for (ll i = 0; i < n; i++) {
        vector<string> v = raw[i];
        for (ll j = 0; j < v.size(); j++) {
            processed[i].push_back(GetIndex(opts[j], raw[i][j]));
        }
    }
    // for (auto v : processed) {
        // for (auto x : v) {
            // cout << x << " ";
        // }
        // cout << endl;
    // }
    sort(all(processed));

    ll total = 1;
    for (ll i = 0; i < adjs; i++) total *= opts[i].size();

    ll ans = 0;
    ll step = total;
    vector<ll> cnt(adjs, 0);
    for (ll i = 0; i < adjs; i++) {
        step /= opts[i].size();
        
        while (ans + step <= k) {
            ans += step;
            cnt[i]++;
        } 
    }
    // cout << cnt << endl;
    cnt[adjs-1]--;

    auto incCnt = [&]() {
        cnt[adjs-1]++;
        for (ll i = adjs-1; i > 0; i--) {
            if (cnt[i] == opts[i].size()) {
                cnt[i-1]++;
                cnt[i] = 0;
            }
        }
    };

    for (ll i = 0; i < processed.size(); i++) {
        if (processed[i] < cnt) {
            // cout << cnt << endl;
            incCnt();
            // cout << cnt << endl;
        }
    }

    for (ll i = 0; i < cnt.size(); i++) {
        auto iter = opts[i].begin();
        advance(iter, cnt[i]);
        cout << *iter << ' ';
    }
    
    return 0;
}

