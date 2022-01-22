#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, B, D;
vector<vector<bool>> codewords;

vector<bool> toBin(int n){
    vector<bool> res;
    while(n!=0) {
        res.insert(res.begin(), n % 2 != 0);
        n/=2;
    }
    while (res.size() <= B) res.insert(res.begin(), false);
    
    return res;
}

int toDec(vector<bool> bin){
    int res = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i]) res += pow(2, i);
    }
    return res;
}

int hammingDist(vector<bool> a, vector<bool> b){
    int res = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) res++;
    }
    return res;
}

int main() {
//    freopen("hamming.in", "r", stdin);
//    freopen("hamming.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B >> D;
    vector<bool> zero(B, false);
    codewords.reserve(N);
    codewords.push_back(zero);

    for (int n = 1; n < /*pow(2, B)*/INT_MAX; ++n) {
        if (codewords.size() == N) break;
        
        vector<bool> asBin = toBin(n);
        bool ok = true;
        
        for (int j = 0; j < codewords.size(); j++) {
            vector<bool> codeword = codewords[j];
            
            if (hammingDist(codeword, asBin) < D) {
                ok = false;
                break;
            }
        }
        
        if (ok) codewords.push_back(asBin);
    }
    sort(codewords.begin(), codewords.end(), [](vector<bool> a, vector<bool> b){
        return toDec(a) < toDec(b);
    });

    for (int i = 0; i < N; i++) {
        if (i % 10 == 0 && i > 0)
            cout << '\n';
        cout << ((i % 10 == 0) ? to_string(toDec(codewords[i])) : " " + to_string(toDec(codewords[i])));
    }

    return 0;
}
