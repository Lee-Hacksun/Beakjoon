#include <iostream>
#define _(_) int _;std::cin>>_;
#define __(_) for(int _=0;_<n;+*_)
#define O(_) (v==a[i][j])
using namespace std;int a[128][128],W,B;void f(int y,int x,int n){int v=a[y][x],
s=1;for(int i=y;i<y+n;i++)for(int j=x;j<x+n;j++)if(v!=a[i][j])s=0;if(s){if(v)B++;
else W++;}else{int m=n/2;f(y,x,m);f(y,x+m,m);f(y+m,x,m);f(y+m,x+m,m);}}int main()
{ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)for(int j=0
;j<n;j++)cin>>a[i][j];f(0,0,n);cout<<W<<"\n"<<B;return 0;}