#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 100005
using namespace std;
int fa[maxn];
int n,m,q;
int find(int x){
	int y=x;
	if(fa[y]!=y)
	  fa[x]=find(fa[y]);
	else return y;
	return fa[x];  
}
void merge(int u,int v){
	fa[find(u)]=v;
	return ;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	  fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(find(v)!=find(u))
		  merge(u,v);
	}
}
