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
            if (S.rfind(prefix, 0) == 0) {
                for (string p:prims) {
                    if (S.rfind(prefix + p, 0) == 0) {
                        prefixes.insert(prefix + p);
                        found = true;
                    }
                } 
            } 
        } 
        
        if (!found) break;
    }

    const auto longest = std::max_element(prefixes.cbegin(), prefixes.cend(),
                                  [](const std::string& lhs, const std::string& rhs) { return lhs.size() < rhs.size(); });
    
    cout << *longest->size() << '\n';
    
    return 0;
}
