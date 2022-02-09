/*
ID: toronto4
TASK: runround 
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

//void collectDigits(vector<int>& digits, int num) {
//    if (num >= 10) collectDigits(digits, num / 10);
//    
//    digits.push_back(num % 10);
//}


//void gen(string s, vector<bool> used, int depth, int target) {
//    if (depth == target){
//        s[depth] = '\0';
//        
//        if (stoi(s) > target && isRunaround(s)) {
//            cout << s << endl;
//            exit(0);
//        }
//        
//        return;
//    }
//
//    for (int i = 1; i <= 9; ++i) {
//        if (!used[i]) {
//            s[depth] = i + '0';
//            used[i] = true;
//            gen(s, used, depth + 1, target);
//            used[i] = false;
//        }
//    }
//}

bool isUnique(int a) {
    string s = to_string(a);
    
    set<int> sett(s.begin(), s.end());
    
    return s.size() == sett.size();
}

bool isRunaround(string s){
    int len = (int) s.length();

    int i = 0, ii;
    while (s[i] != 'x') {
        ii = i;
        i = (i + s[i] - '0') % len;
        s[ii] = 'x';
    }

    //all xs, ended at idx 0
    if (i != 0) return false;
    for (int iii = 0; iii < len; ++iii)
        if (s[iii] != 'x') return false;

    return true;
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    ++N;
    while (!isUnique(N) || !isRunaround(to_string(N))) ++N;
    cout << N << endl;

    return 0;
}
