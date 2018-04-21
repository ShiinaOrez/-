#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
struct node{
	int next;
	int to;
	int w;
}edge[maxn];
struct Node{
	int from;
	int to;
	int w;
}g[maxn];
int n,m,e=0;
int head[maxn],fa[maxn];
void add(int u,int v,int d){
	edge[++e].next=head[u];
	edge[e].to=v;
	edge[e].w=d;
	head[u]=e;
	return ;
}
bool comp(const Node p1,const Node p2){
	return p1.w<p2.w;
}
int find(int x){
	int y=x;
	if(fa[y]!=y)
	  fa[x]=find(fa[y]);
	else return y;  
	return fa[x];  
}
void union_forst(int x,int y){
	fa[x]=y;
	return ;
}
void kruskal(){
	int c=0;
	for(int i=1;i<=m;i++){
		if(c==n-1) break;
		int pre=g[i].from;
		int ver=g[i].to;
		if(find(pre)!=find(ver)){
			add(pre,ver,g[i].w);
			add(ver,pre,g[i].w);
			union_forst(pre,ver);
			c++;
		}
	}
	return ;
}
int main(){
	int u,v,d;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		fa[i]=i;
		scanf("%d%d%d",&u,&v,&d);
		g[i].from=u;
		g[i].to=v;
		g[i].w=d;
	}
	sort(g+1,g+1+m,comp);
	kruskal();
	return 0;
}
