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
vector<char> cons = { 'A', 'E', 'I', 'O', 'U' };


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tc = 0;
    
    int T; cin >> T; while (T--) {
        tc++;
        string a, b; cin >> a >> b;
        set<string> ans;

        auto f = [&]() -> void {
            for (ll i = 1; i < a.size(); i++) {
                string c = a.substr(0, i);
                
                for (ll j = 1; j < b.size(); j++) {
                    bool f = count(all(cons), c[c.size() - 1]);
                    bool s = count(all(cons), b[j]);
                    if (f == s) continue; 

                    ans.insert(c+b.substr(j, b.size() - j));
                }
            }
        };
        f();
        swap(a, b);
        f();

        cout << "Couple #" << tc << ": " << ans.size() << " possible names" << endl;
        for (auto x : ans) cout << x << endl; 
        cout << endl;
    }    
    
    return 0;
}

