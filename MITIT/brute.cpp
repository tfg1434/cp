#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);; cin.tie(NULL)
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i =0 ; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int maxVal = INT_MAX;
            for(int k = i; k <= j; k++){
                for(int l = k + 1; l <= j; l++){
                    maxVal = min(maxVal, a[k] ^ a[l]);
                }
            }
            if(maxVal == k){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
