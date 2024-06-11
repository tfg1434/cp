#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
int tt; cin >> tt;
while(tt--){
int p,q,x,y; cin >> p >> q >> x >> y;
p=abs(p); q=abs(q); x=abs(x); y=abs(y);
int gcd_ = gcd(p,q);
if(x%gcd_!=0 || y%gcd_!=0){
cout<<"NO"<<endl; continue;
}
x/=gcd_;
y/=gcd_;
p/=gcd_;
q/=gcd_;
x%=2;
y%=2;
p%=2;
q%=2;
int DIR[4][2] = {{0,0},{1,0},{0,1},{1,1}};
bool ok[2][2] = {{0,0},{0,0}};
for(int i=0;i<4;i++){
int a = (DIR[i][0]*p + DIR[i][1]*q)%2;
int b = (DIR[i][1]*p + DIR[i][0]*q)%2;
ok[a][b] = true;
}
if(ok[x][y]) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
}
