/*
dijkstra�㷨
disigned by Metralix����� 
���룺
10
1 2 2
2 3 1
1 3 4
2 4 6
3 4 1
3 5 4
4 5 10
4 6 5
5 6 3
1 4 22
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=6; 
int cost[maxn][maxn];
struct str{
	int dis;
	int way[maxn];
	int n;
}d[maxn];
bool used[maxn];
int vn=maxn;

void dijkstra(int s){
	//��ʼ�� 
	for(int i=0;i<maxn;i++){
		d[i].dis=inf;
		d[i].n=0;
		//memset(d[i].way,d[i].way+maxn,0);
		for(int j=0;j<maxn;j++){
			d[i].way[j]=0;
		}
	}
	fill(used,used+vn,false);
	d[s].dis=0;
	
	while(true){
		int v=-1;
		//����δʹ�ù��Ķ�����ѡ��һ��������С�ĵ�
		for(int u=0; u<vn; u++){
			if( !used[u] && (v ==-1 || d[u].dis < d[v].dis )) v=u;
		} 
		if(v == -1) break;
		//��Ϊ�Ѷ� 
		used[v] = true;
		//�ɳ� 
		for(int i=0;i<vn;i++){
			if(d[i].dis < d[v].dis+cost[v][i]){
				d[i].dis=d[i].dis;
			}else{
				d[i].dis=d[v].dis+cost[v][i];
				d[i].way[d[i].n]=v;
				d[i].n++;
			}
		}
	}
}

int main(){
	//��ͼ 
	memset(cost,inf,sizeof(cost));
	int side_num;
	scanf("%d",&side_num);
	for(int i=0;i<side_num;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		cost[a-1][b-1]=c;
		cost[b-1][a-1]=c;
		cost[i][i]=0;
	} 
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			printf("%d ",cost[i][j]); 
		}
		printf("\n");
	}
	int p;
	printf("������Դ�㣺");
	scanf("%d",&p);
	dijkstra(p);
	for(int i=0;i<maxn;i++){
		printf("��%d�����·������%d\n",i,d[i].dis);
		printf("·����");
		for(int j=1;j<d[i].n;j++){
			printf(" ->%d ",d[i].way[j]);
		}
		printf("\n");
	}
	return 0;
}

