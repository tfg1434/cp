#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Rect{
    ll x1, x2, y1, y2;
    
    [[nodiscard]]
    ll area() const {
        return (x2-x1) * (y2-y1);
    }
    
    [[nodiscard]]
    ll intersect(Rect other) const {
        ll xLap = max(0ll, other.x1 - x2);
        ll yLap = max(0ll, other.y1 - y2);
        // ll xLap = max(0ll, min(x2, other.x2) - max(x1, other.x1));
        // ll yLap = max(0ll, min(y2, other.y2) - max(y1, other.y1));
        
        return xLap * yLap;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin>>x1>>y1>>x2>>y2;
    for(ll i=1; i<=2; i++){
        cin>>x3>>y3>>x4>>y4;
        if(x1>=x3 && y1>=y3 && x4>=x2 && y4>=y2){
            cout<<"NO"; 
            return 0;
        }
        if(x1>x4 || x3>x2 || y3>y2 || y4<y1) continue;
        if(x1>=x3 && y1>=y3 && x4>=x2)y1=y4;
        if(x1>=x3 && y1>=y3 && y4>=y2)x1=x4;
        if(x1>=x3 && y4>=y2 && x4>=x2)y2=y3;
        if(x4>=x2 && y1>=y3 && y4>=y2)x2=x3;
    }
    cout<<"YES"<<endl;
    return 0;
}



