#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 100005
using namespace std;
struct node{
	int next;
	int to;
	int w;
}edge[maxn];
struct Node{
	int w;
	bool ty;
}dis[maxn];
int n,m,q,e=0,head[maxn];
void add(int u,int v,int d){
	edge[++e].next=head[u];
	edge[e].to=v;
	edge[e].w=d;
	head[u]=e;
	return ;
}
void dij(int x){
	int c=n-1;
	dis[x].ty=1;
	for(int i=head[x];i!=0;i=edge[i].next)
	  dis[edge[i].to].w=edge[i].w;
	while(c>0){
		int min=900000000,p;
		for(int i=1;i<=n;i++){
			if(dis[i].ty==0&&dis[i].w!=0&&dis[i].w<min){
				p=i;
				min=dis[i].w;
			}
		}
		for(int i=head[p];i!=0;i=edge[i].next){
			if(dis[edge[i].to].ty!=1){
				if(dis[edge[i].to].w==0||dis[edge[i].to].w>dis[i].w+edge[i].w)
				  dis[edge[i].to].w=dis[p].w+edge[i].w;
			}
		}
		dis[p].ty=1;
		c--;
	}
	return ;
}
int main(){
	int u,v,d,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		add(u,v,d);
		add(v,u,d);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		dij(x);
		printf("%d\n",dis[y].w);
		for(int j=1;j<=n;j++){
			dis[j].w=0;
			dis[j].ty=0;
		}
	}
	return 0;
}
