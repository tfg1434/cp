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
set<string> prefixes;

//https://www.programmerall.com/article/10612175942/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;
    while (true) {
        cin >> a;
        if (a == ".") break;
        
        prims.push_back(a);
    }
    string b;
    while (cin >> b || S.empty()) 
        S += b;

    cout << "hello?";
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
    
    
    
    return 0;
}
