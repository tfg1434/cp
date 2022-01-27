/*
ID: toronto4
TASK: prefix
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr int MAX_P_COUNT = 200;
constexpr int MAX_P_LEN = 10;
vector<string> prims;
string S;
set<string> prefixes { "" };
set<string> tried;

bool startsWith(string mainStr, string toMatch) {
    for (int i = 0; i < toMatch.size(); ++i) 
        if (mainStr[i] != toMatch[i]) return false;
    
    return true;
}

int main() {
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
//            if (tried.count(prefix)) continue;
//            tried.insert(prefix);
            
            if (S.rfind(prefix, 0) == 0) {
                for (string p:prims) {
                    string look = prefix + p;
                    cout << startsWith(S, look) << endl; 
                    if (S.rfind(look, 0) == 0) {
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
