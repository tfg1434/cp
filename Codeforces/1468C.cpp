#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
int q;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    auto cmp = [](pii a, const pii b) { 
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    };
    //money, idx
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    queue<int> qu; //idx
    set<int> served;
    
    cin >> q;
    int idx = 1;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int m; cin >> m;
            pq.push({ m, idx });
            qu.push(idx);
            idx++;

        } else if (t == 2) {
            while (served.count(qu.front())) {
                qu.pop();
            }
            int c = qu.front();
            cout << c << ' ';
            served.insert(c);

        } else if (t == 3) {
            while (served.count(pq.top().second)) {
                pq.pop();
            }
            int c = pq.top().second;
            cout << c << ' ';
            served.insert(c);
        }
    }
    cout << '\n';
    
    return 0;
}

