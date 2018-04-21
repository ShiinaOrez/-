#include<cstdio>
#include<queue>
#define maxn 1005
using namespace std;
struct node{
	int next;
	int to;
	int w;
}edge[maxn];
bool visit[maxn];
int e,head[maxn];
int in[maxn];
int n,m;
queue<int> list;
void add(int u,int v,int w){
	edge[++e].next=head[u];
	edge[e].to=v;
	edge[e].w=w;
	head[u]=e;
	return ;
}
void scan(int x){
	for(int i=head[x];i!=0;i=edge[i].next){
		int v=edge[i].to;
		in[v]--;
		if(!in[v]) list.push(v);
	}
	return ;
}
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		in[v]++;
	}
	for(int i=1;i<=n;i++)
		if(!in[i]) list.push(i);
	while(!list.empty()){
		int now=list.front();
		scan(now);
		printf("%d ",now);
		list.pop();
	}
	return 0;
}
