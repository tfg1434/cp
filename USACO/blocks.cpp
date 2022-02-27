#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
vector<set<char>> blocks(4);


void solve(string word, set<int> used, int depth) {
    if (depth == 3) {
        cout << "YES" << '\n';
    }

    for (int i = 0; i < blocks.size(); i++) {
        if (used.count(i)) continue;

        if (blocks[i].count(word[depth])) {
            used.insert(i);
            solve(word, used, depth + 1);
            used.erase(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < 4; i++) {
        blocks[i].clear();
        string s; cin >> s;
        for (char c : s) blocks[i].insert(c);
    }

    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        solve(word, set<int>(), 0);
    }
    
    return 0;
}

