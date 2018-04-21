#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#define maxn 10005
using namespace std;
int a[maxn],n,q;
int f[21][maxn];
void re_rmq(int count){
	for(int i=1;i<=n;i++)
	  f[i][0]=a[i];
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			if(i+(1<<j)-1<=count){
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	} 
	return ;
}
int query_rmq(int l,int r){
	int k=log(r-l+1)/log(2);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	re_rmq(n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(y<x) swap(x,y);
		int ans=query_rmq(x,y);
		printf("%d\n",ans);
	}  
	return 0;
}
