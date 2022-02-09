#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, Q;
string S;

int isAbc(int idx) {
    return S[idx] == 'a' && S[idx + 1] == 'b' && S[idx + 2] == 'c';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> Q;
    cin >> S;
    S = ' ' + S;
    vector<int> v;

    for (int i = 1; i <= S.size(); i++) {
        if (isAbc(i)) {
            v.push_back(i);
        }
    }

    int ans = v.size();
    for (int q = 0; q < Q; q++) {
        int pos;
        char c;
        cin >> pos >> c;

        for (int i = pos-2; i <= pos; i++) {
            if (0 < i && i <= N - 2) ans -= isAbc(i);
        }
        S[pos] = c;

        for (int i = pos-2; i <= pos; i++) {
            if (0 < i && i <= N - 2) ans += isAbc(i);
        }

        cout << ans << endl;
    }
    
    return 0;
}

