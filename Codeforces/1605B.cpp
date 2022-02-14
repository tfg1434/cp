#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        if(is_sorted(s.begin(), s.end()))
        {
            cout << 0 << "\n";
            continue;
        }
        
        string t = s;
        sort(t.begin(), t.end());
        cout << 1 << "\n";
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
                ans.push_back(i+1);
        }
        cout << ans.size() << " ";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i+1 == ans.size()];
        // int n; cin >> n;
        // string s; cin >> s;
        // if (is_sorted(s.begin(), s.end())) {
            // cout << 0 << endl;
            // continue;
        // }

        // vector<int> ans;
        // string copy = s;
        // sort(copy.begin(), copy.end());
        // // cout << copy << ' ' << s << endl;
        // for (int i = 0; i < n; i++) {
            // cout << "DEBUG: " << copy[i] << ' ' << s[i] << endl;
            // if (copy[i] != s[i]) ans.push_back(i);
        // }
        
        // cout << 1 << endl;
        // cout << ans.size() << ' ';
        // for (auto i : ans) cout << i + 1 << ' ';
        // cout << endl;
    }    
    
    return 0;
}

