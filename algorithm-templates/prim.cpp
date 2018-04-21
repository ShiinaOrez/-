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
int fa[maxn],head[maxn];
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
void prim(){
	for(int i=1;i<n;i++){
		for(int i=1;i<=m;i++){
			int pre=g[i].from;
			int ver=g[i].to;
			if((fa[pre]==0&&fa[ver]!=0)||(fa[pre]!=0&&fa[ver]==0)){
				if(fa[pre]!=0)
			 	 fa[pre]=0;
				else fa[ver]=0;  
				add(pre,ver,g[i].w);
				add(ver,pre,g[i].w);
			}
		}
	}
	return ;
}
int main(){
	int u,v,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<m;i++){
		fa[i]=i;
		scanf("%d%d%d",&u,&v,&d);
		g[i].from=u;
		g[i].to=v;
		g[i].w=d;
	}
	sort(g+1,g+1+m,comp);
	prim();
	return 0; 
}
