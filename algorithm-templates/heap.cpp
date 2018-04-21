#include<cstdio>//Ð¡¸ù¶Ñ 
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int heap[maxn];
void build_heap(int a,int p){
	heap[p]=a;
	while(p>=1&&heap[p/2]>heap[p]){
		swap(heap[p/2],heap[p]);
		p/=2;
	}
	return ;
}
void heaply(int p){
	int l=p*2,r=p*2+1;
	if(heap[l]>heap[r]){
		swap(heap[r],heap[p]);
		heaply(r);
	}
	else{
		swap(heap[l],heap[p]);
		heaply(l);
	}
	return ;
}
void heap_sort(){
	for(int i=n;i>=1;i--){
		printf("%d ",heap[1]);
		heap[1]=heap[i];
		heaply(1);
	}
	return ;
}
int main(){
	int a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		build_heap(a,i);
	}
	heap_sort();
	return 0;
}
