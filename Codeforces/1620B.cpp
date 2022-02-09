#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> process() {
    int n;
    cin >> n;
    vector<int> res(n);
    
    for (int& a : res) {
        cin >> a;
    }
    
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y,a[200000],s=0;
        cin>>x>>y;
        for(int i=0;i<4;i++){
            int b,n;
            cin>>b;
            for(int j=0;j<b;j++) cin>>a[j];
            if(i<2) n=y;
            else n=x;
            s=max(s,(a[b-1]-a[0])*n);
        }
        cout<<s<<endl;
    }
}

//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int C;
//    cin >> C;
//
//    for (int c = 0; c < C; ++c) {
//        int w, h;
//        cin >> w >> h;
//        
//        vector<int> hpoints1 = process(); //y=0
//        vector<int> hpoints2 = process(); //y=h
//        vector<int> vpoints1 = process(); //x=0
//        vector<int> vpoints2 = process(); //x=h
//
//        array all = {hpoints1, hpoints2, vpoints1, vpoints2};
//        array m = {h, h, w, w};
//        
//        int max= 0;
//        int mult = -1;
//        int i = 0;
//        for (vector<int> v:all) {
//            sort(v.begin(), v.end());
//            int newMax = v[v.size() - 1] - v[0];
//            
//            if (newMax > max) {
//                max = newMax;
//                mult = m[i];
//            }
//            
//            ++i;
//        }
//        
//        int ans = max * mult; //b/c *2
//        cout << ans << '\n';
//    }
//
//    return 0;
//}
