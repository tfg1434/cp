#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
set<char> blocks[4];
vector<vector<int>> perms;


void perm(vector<int> a, int n, int k, int i) {
    if (i == 0) {
        perms.push_back(a);
        return;
    }

    for (int ii = 0; ii < n; ii++) {
        swap(a[ii], a[n-1]);
        perm(a, n-1, k, i-1);
        swap(a[ii], a[n-1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < 4; i++) {
        blocks[i].clear();
        string s; cin >> s;
//        cout << s << endl;
        for (char c : s) blocks[i].insert(c);
    }

    vector<int> a = {0, 1, 2, 3};
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
//        cout << word << endl;
        perms.clear();
        perm(a, a.size(), word.size(), word.size());
        
        bool ok = false;
        for (auto &p : perms) {
//            cout << p[0] << p[1] << p[2] << p[3] << endl;
            bool ok2 = true;
            for (int j = 0; j < word.size(); j++) {
                if (blocks[p[j]].count(word[j]) == 0) {
                    ok2 = false;
                    break;
                }
            }
            if (ok2) {
                ok = true;
                break;
            }
        }

        if (word == "CODE") {
            int breakpoint = 0;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}

