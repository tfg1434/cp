/*
ID: toronto4
TASK: prefix
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> prims;
string S;
set<string> prefixes { "" };
set<string> dp;

bool startsWith(string mainStr, string toMatch) {
    for (int i = 0; i < toMatch.size(); ++i) 
        if (mainStr[i] != toMatch[i]) return false;
    
    return true;
}

int main() {
//    freopen("prefix.in", "r", stdin);
//    freopen("prefix.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;
    while (cin >> a) {
        if (a == ".") break;
        
        prims.push_back(a);
    }
    
    while (cin >> a) S += a;

    while (true) {
        bool found = false;
        
        for (string prefix:prefixes) {
            if (dp.count(prefix)) continue;
            dp.insert(prefix);
            
            if (startsWith(S, prefix)) {
                for (string p:prims) {
                    string look = prefix + p;
//                    cout << startsWith(S, look) << endl; 
                    if (startsWith(S, look)) {
                        prefixes.insert(look);
                        found = true;
                    }
                }
            } 
        } 
        
        if (!found) break;
    }

    const auto longest = max_element(prefixes.cbegin(), prefixes.cend(),
                                  [](const string& lhs, const string& rhs) { return lhs.size() < rhs.size(); });
    
    cout << longest->size() << '\n';
    
    return 0;
}
