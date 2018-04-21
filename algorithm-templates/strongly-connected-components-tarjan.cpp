#include<cstdio>
#include<vector>
#include<stack>
#define maxn 1005
using namespace std;
int e,tag;
bool stack_exist[maxn];
int head[maxn],visit[maxn],index[maxn],low[maxn];
stack<int> s;
int n,m;
struct node{
	int next;
	int to;
	int w;
}edge[maxn];
void add(int u,int v,int w){
	edge[++e].next=head[u];
	edge[e].to=v;
	edge[e].w=w;
	head[u]=e;
	return ;
}
void tarjan(int x){
	index[x]=++tag;
	low[x]=index[x];
	visit[x]=1;
	s.push(x);
	stack_exist[x]=true;
	for(int i=head[x];i!=0;i=edge[i].next){
		if(visit[edge[i].to]==0){
			tarjan(edge[i].to);
			low[x]=min(low[x],low[edge[i].to]);
		}
		else if(stack_exist[edge[i].to]){
			if(visit[edge[i].to]!=2)
				low[x]=min(low[x],index[edge[i].to]);
		}
	}
	if(index[x]==low[x]){
		while(s.top()!=x){
			int v=s.top();
			s.pop();
			stack_exist[v]=false;
			visit[v]++;
			printf("%d ",v);
		}
		printf("%d\n",s.top());
		s.pop();
		visit[x]++;
	}
	return ;
}
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=n;i++)
		if(visit[i]==0){
			printf("strongly connected components:");
			tarjan(i);
/*			for(int j=1;j<=n;j++){
				printf("%d ",visit[j]); 
			}
			printf("\n");
			printf("\n%d: %d %d\n",i,index[i],low[i]);*/
		}
	return 0;
}













