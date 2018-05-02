#include<cstdio>
#define maxn 1005
using namespace std;
struct node{
	int to;
	int next;
}edge[maxn];
int head[maxn],sub_node[maxn],e,n,m,min=maxn,cog=0;
void add(int u,int v){
	edge[++e].next=head[u];
	edge[e].to=v;
	head[u]=e;
	return ;
}
int dfs(int now,int from){
	int sum=0,max=0;
	for(int i=head[now];i!=0;i=edge[i].next){
		int v=edge[i].to;
		if(v==from ) continue;
		sum+=dfs(v,now);
		if(sub_node[v]>max) max=sub_node[v];
	}
	sum++;
	if(max<(n-sum))
		max=n-sum;
	if(max<min){
		min=max;
		cog=now;
	}
	sub_node[now]=sum;
	return sum;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	int s=dfs(1,0);
	printf("this tree 's center of gravity is :%d\n",cog);
	for(int i=1;i<=n;i++) printf("%d ",sub_node[i]);
	return 0;
}
