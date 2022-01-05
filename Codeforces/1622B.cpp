#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C;
    cin >> C;
    
    for (int c = 0; c < C; ++c) {
        int n;
        cin >> n;
        
        vector<int> p(n);
        for (int& predicted:p)
            cin >> predicted;
        
        string s;
        cin >> s;
        
        map<int, int> like;
        map<int, int> dislike;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
                like[p[i]] = i;
            else
                dislike[p[i]] = i;
        }
        
        int curr = 1;
        for (pair<const int, int> d:dislike)
            p[d.second] = curr++;
        
        for (pair<const int, int> l:like)
            p[l.second] = curr++;

        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        
        cout << endl;
    }

    return 0;
}
