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
int n,m,q,e=0;
int head[maxn],sp_fi[maxn],dis[maxn];
void add(int u,int v,int d){
	edge[++e].next=head[u];
	edge[e].to=v;
	edge[e].w=d;
	head[u]=e;
	return ;
}
void spfa(int x){
	int h=0,tail=0;
	tail++;
	sp_fi[tail]=x;
	while(h<=tail){
		h++;
		int now=sp_fi[h];
		for(int i=head[now];i!=0;i=edge[i].next){
			int p=edge[i].to,wei=edge[i].w;
			if(dis[p]==0||dis[p]>dis[now]+wei){
				dis[p]=dis[now]+wei;
				tail++;
				sp_fi[tail]=p;
			}
		}
	}
	return ;
}
int main(){
	int u,v,d,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		add(u,v,d);
		add(v,u,d);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		spfa(x);
		printf("%d\n",dis[y]);
		for(int j=1;j<=n;j++)
		  dis[j]=0;
	}
	return 0;
}
