#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,avx")

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int low = 1;
        int high = 1e9;
        int thing = -1;
        while(low <= high){
            int mid = (low + high)/2;
            long long val1 = (n + (n % (mid + 1)))/2 * ((n - (n % (mid + 1)))/(mid + 1) + 1);
            if(val1 <= k){
                thing = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << thing << "\n";
    }
}
