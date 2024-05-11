#include <bits/stdc++.h>

using namespace std;

int n;

int ask(int tp, int i, int j, int k) {
    cout << tp << ' ' << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
    int res; cin >> res;
    return res;
}

void solve() {
    cin >> n;
    int A = 0;
    int B = 1;
    for (int i = 2; i < n; i++) {
        if (ask(2, 0, B, i) < 0) {
            B = i;
        }
    }

    vector<array<int, 2>> areas;
    for (int i = 1; i < n; i++) if (i != B) {
        int area = ask(1, A, B, i);
        areas.push_back({area, i});
    }
    sort(begin(areas), end(areas));

    vector<int> ans = {A, B};
    vector<int> rev;
    for (int i = 0; i < areas.size()-1; i += 2) {
        for (int j = 0; j < ans.size(); j++) cerr << ans[j] << " \n"[j==ans.size()-1];
        for (int j = 0; j < rev.size(); j++) cerr << rev[j] << " \n"[j==rev.size()-1];

        int X = areas[i][1], Y = areas[i+1][1];
        cerr << X << ' ' << Y << endl;
        if (ask(2, B, X, Y) > 0) {
            ans.push_back(X);
            if (i == areas.size()-2) {
                rev.push_back(Y);
                continue;
            }
            int Z = areas[i+2][1];
            if (ask(2, X, Z, Y) > 0) {
                rev.push_back(Y);
            } else {
                ans.push_back(Y);
            }

        } else {
            rev.push_back(X);
            if (i == areas.size()-2) {
                ans.push_back(Y);
                continue;
            }
            int Z = areas[i+2][1];
            if (ask(2, Y, Z, X) > 0) {
                ans.push_back(Y);
            } else {
                rev.push_back(Y);
            }
        }
    }
    if (ans.size() + rev.size() < n) {
        ans.push_back(areas.back()[1]);
    }
    while (rev.size()) {
        ans.push_back(rev.back());
        rev.pop_back();
    }

    cout << "0";
    for (int i = 0; i < n; i++) cout << ' ' << ans[i]+1; 
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}
