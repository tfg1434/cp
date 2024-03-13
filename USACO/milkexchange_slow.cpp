#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n;
    cin >> n;

    vector<int> A(n); 
    ll sum = 0;

    for (int &i : A){
        cin >> i;
        sum += i;
    }
    rotate(A.begin(), next(min_element(A.begin(), A.end())), A.end());

    vector<int> stk;
    vector<ll> reduce(n + 5, 0);

    auto procStack = [&](int pos){
        for (int i = 1; i < stk.size(); i++){
            int delta = A[stk[i]] - A[stk[i - 1]];
            reduce[stk[i - 1] - pos] += delta; 
        }
    };

    for (int i = n - 1; i >= 0; i--){
        while (stk.size() and A[stk.back()] >= A[i]){
            stk.pop_back();
        }
        stk.push_back(i);
        for (int i = 0; i < stk.size(); i++) cout << stk[i] << " \n"[i==stk.size()-1];
        procStack(i);
    }

    for (int i = 1; i <= n; i++){
        sum -= reduce[i];
        cout<<sum<<"\n";
    }
}
