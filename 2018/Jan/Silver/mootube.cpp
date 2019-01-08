/*
ID: xinyu.l1
TASK: mootube
LANG: C++                 
*/
#include<set>  
#include<map>  
#include<list>  
#include<queue>  
#include<stack>  
#include<string>  
#include<cmath>  
#include<time.h>  
#include<vector>  
#include<bitset>  
#include<memory>  
#include<utility>  
#include<stdio.h>  
#include<iostream>  
#include<stdlib.h>  
#include<string.h>  
#include<algorithm> 

using namespace std;
const long long MAX = 1147483647;
int n,q;
int father[100010], connected[100010], ans[100010];
struct node
{
	int x, y, weight;
}nodes[100010];
bool nodecmp(node a, node b){
	return a.weight > b.weight;
}

struct query
{
	int k, v_id, query_id;
}queries[100010];
bool querycmp(query a, query b){
	return a.k > b.k;
}

int getfather(int x){
	if(father[x]!=x) father[x] = getfather(father[x]);
	return father[x];
}

void Myunion(int x, int y){
	x = getfather(x);
	y = getfather(y);
	if(x!=y){
		father[x] = y;
		connected[y]+=connected[x];	
	}
}

inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

int main(int argc, char const *argv[])
{
	freopen("mootube.in","r",stdin);
	freopen("mootube.out","w",stdout);
	n = read();
	q = read();
	for(int i = 1;i<n;++i){
		nodes[i].x = read();
		nodes[i].y = read();
		nodes[i].weight = read();
	}
	for(int i = 0;i<q;++i){
		queries[i].k = read();
		queries[i].v_id = read();
		queries[i].query_id = i;
	}
	for(int i = 0;i<=n;++i){
		father[i] = i;
		connected[i] = 1;
	}
	sort(nodes+1, nodes+n+1, nodecmp);
	sort(queries, queries+q, querycmp);
	int pointer = 1;
	for(int i = 0;i<q;++i){
		while(pointer<n && nodes[pointer].weight >= queries[i].k){
			Myunion(nodes[pointer].x, nodes[pointer].y);
			++pointer;
		}
		ans[queries[i].query_id] = connected[getfather(queries[i].v_id)];
	}
	for(int i = 0;i<q;++i) cout<<ans[i]-1<<endl;
	return 0;
}