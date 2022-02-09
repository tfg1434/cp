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
        ll xLap = max(0ll, min(x2, other.x2) - max(x1, other.x1));
        ll yLap = max(0ll, min(y2, other.y2) - max(y1, other.y1));
        
        return xLap * yLap;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Rect white, a, b;
    cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    
    ll total = white.intersect(a) + white.intersect(b) - a.intersect(b);
    if (total >= white.area())
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
    
//    if (white.hasIntersect(a) || white.hasIntersect(b))
//        cout << "NO" << '\n';
//    else
//        cout << "YES" << '\n';
    
    return 0;
}



