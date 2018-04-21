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
int c=0,lc,ans,e=0,q,n,m;
int find_p[maxn],dfs_d[maxn],dfs_p[maxn],dfs_w[maxn],head[maxn];
void add(int u,int v,int d){
	edge[++e].next=head[u];
	edge[e].to=v;
	edge[e].w=d;
	head[u]=e;
	return ;
}
void dfs_lca(int pre,int now,int deep,int weight){//遍历从第一个点开始，第一个输入的点-->根 
	c++;//遍历顺序编号 
	dfs_p[c]=now;//此节点的下标 
	dfs_d[c]=deep;//深度 
	dfs_w[c]=weight;//权值和-->沿路权值和 
	for(int i=head[now];i!=0;i=edge[i].next){//now相连的所有点 
		if(edge[i].to!=pre){//不向上 
			dfs_lca(now,edge[i].to,deep+1,weight+edge[i].w);//继续dfs 
			c++;//回到这个节点 
			dfs_p[c]=now;//同样记录 
			dfs_d[c]=deep;
			dfs_w[c]=weight;
		}
	}
	c++;//同样又一次回到了起点 
	dfs_p[c]=now;
	dfs_d[c]=deep;
	dfs_w[c]=weight;
	find_p[now]=c;//now这个点最后被记录的位置 
	return ;
}
void lca(){
	dfs_lca(0,1,1,0);
	return ;
}
void find_lca(int u,int v){
	if(find_p[u]>find_p[v]) swap(u,v);
	int ans=min(dfs_d[find_p[u]],dfs_d[find_p[v]]);
	for(int i=find_p[u];i<=find_p[v];i++){
		if(dfs_d[i]<ans) lc=dfs_p[i];
	}
	return ;
}
int main(){
	int u,v,d;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		add(u,v,d);
		add(v,u,d);
	}
	lca();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&u,&v);
		find_lca(u,v);
		printf("%d",lc);
	}
	return 0;
}
