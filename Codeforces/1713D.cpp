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


ll ask(vector<ll> c) {
    cout << "? " << c[0] << " " << c[2] << endl;
    ll x; cin >> x;
    if (x == 1) {
        cout << "? " << c[0] << ' ' << c[3] << endl;
        cin >> x;
        if (x == 1) return c[0];
        return c[3];
    } else if (x == 2) {
        cout << "? " << c[1] << ' ' << c[2] << endl;
        cin >> x;
        if (x == 1) return c[1];
        return c[2];
    } else {
        cout << "? " << c[1] << ' ' << c[3] << endl;
        cin >> x;
        if (x == 1) return c[1];
        return c[3];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        
        vector<ll> a, b;
        for (ll i = 1; i <= (1ll << n); i++) a.push_back(i);

        while (len(a) > 2) {
            while (!a.empty()) {
                vector<ll> c(4);
                c[0] = a.back(); a.pop_back(); 
                c[1] = a.back(); a.pop_back();
                c[2] = a.back(); a.pop_back();
                c[3] = a.back(); a.pop_back();

                ll x = ask(c);
                b.push_back(x);
            }
            swap(a, b);
            b.clear();
        }

        if (a.size() == 2) {
            cout << "? " << a[0] << ' ' << a[1] << endl;
            ll x; cin >> x;
            if (x == 2) swap(a[0], a[1]);
        } 
        cout << "! " << a[0] << endl;
    }    
    
    return 0;
}

