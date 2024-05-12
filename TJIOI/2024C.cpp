#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define int int64_t
const int inf = 2e18;

int n, q;
vector<int> a;
const int max_c = 1e5;
vector<int> where[max_c+1];

void solve() {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        where[a[i]].push_back(i);
    }
    int mx = *max_element(all(a));

    vector<int> longest_segment;
    multiset<int> lens;
    set<pair<int, int>> st; // l, r
    st.insert({0, n});
    lens.insert(n);
    for (int c = mx; c > 0; c--) {
        vector<pair<int, int>> pairs;
        vector<vector<int>> breaks;
        pair<int, int> prev = {-1, -1};
        for (int i = 0; i < where[c].size(); i++) {
            auto it = st.lower_bound({where[c][i], inf}); it--;
            auto p = *it;

            if (prev.f == -1 || p != prev) {
                vector<int> vec = {where[c][i]}; breaks.push_back(vec);
                pairs.push_back(p);
            } else {
                breaks.back().push_back(where[c][i]);
            }
            prev = p;
        }

        for (int i = 0; i < breaks.size(); i++) {
            auto p = pairs[i];
            auto vec = breaks[i];
            st.erase(p); lens.erase(lens.find(p.s - p.f));
            int l = p.f;
            for (auto j : vec) {
                if (l < j) st.insert({l, j}), lens.insert(j-l);
                l = j+1;
            }
            if (l < p.s) st.insert({l, p.s}), lens.insert(p.s-l);
        }
        if (lens.size()) longest_segment.push_back(*rbegin(lens));
    }

    vector<int> ans(q);
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].f;
        queries[i].s = i;
    }
    sort(all(queries));
    // for (auto x : longest_segment) cerr << x << ' ';
    // cerr << endl;
    // int i = 0, cnt = 0;
    // int cur = 0;

    int free = 0;
    for (int i = 0; i < min((int)longest_segment.size(), mx); i++) free += longest_segment[i];

    for (auto [m, ind] : queries) {
        if (free >= m) ans[ind] = mx;
        else ans[ind] = mx+(m-free+n-1)/n;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}


