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
void dfs_lca(int pre,int now,int deep,int weight){//�����ӵ�һ���㿪ʼ����һ������ĵ�-->�� 
	c++;//����˳���� 
	dfs_p[c]=now;//�˽ڵ���±� 
	dfs_d[c]=deep;//��� 
	dfs_w[c]=weight;//Ȩֵ��-->��·Ȩֵ�� 
	for(int i=head[now];i!=0;i=edge[i].next){//now���������е� 
		if(edge[i].to!=pre){//������ 
			dfs_lca(now,edge[i].to,deep+1,weight+edge[i].w);//����dfs 
			c++;//�ص�����ڵ� 
			dfs_p[c]=now;//ͬ����¼ 
			dfs_d[c]=deep;
			dfs_w[c]=weight;
		}
	}
	c++;//ͬ����һ�λص������ 
	dfs_p[c]=now;
	dfs_d[c]=deep;
	dfs_w[c]=weight;
	find_p[now]=c;//now�������󱻼�¼��λ�� 
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
