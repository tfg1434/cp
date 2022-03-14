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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        int n; cin >> n;
        map<char, vector<int>> m;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (char c = 'a'; c <= 'e'; c++) {
                int cnt = count(all(s), c);
                cnt -= (s.size() - cnt);
                m[c].push_back(cnt);
            }
        }
        for (char c = 'a'; c <= 'e'; c++) {
            sort(rall(m[c]));
        }

        int ans = 0;
        for (char c = 'a'; c <= 'e'; c++) {
            int curr = 0, tot = 0;
            for (int x : m[c]) {
                if (curr + x > 0) {
                    curr += x;
                    tot++;
                }
                else break;
            }
            ans = max(ans, tot);
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

