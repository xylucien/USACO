/*
ID: xinyu.l1
TASK: dining
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
const long long MAX = 2147483647;
int n, m, k;
vector< pair<int, int> > graph[50001];
pair<int, int> tastiness[50001];
int Ninfo[50001], curBayinfo[50001];
bool visited[50001], answer[50001];
priority_queue< pair<int, int> > q;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout);
	n = read();
	m = read();
	k = read();
	int a,b,w;
	for(int i = 0;i<m;++i){
		a = read();
		b = read();
		w = read();
		graph[a].push_back(make_pair(b,w));
		graph[b].push_back(make_pair(a,w));
	}
	for(int i = 1;i<=k;++i){
		tastiness[i].first = read();
		tastiness[i].second = read();
	}
	for(int i = 1;i<n;++i) Ninfo[i] = 20020226;
	q.push(make_pair(0,n));
	while(!q.empty()){
		int a = q.top().second;
		q.pop();
		if(visited[a]) continue;
		visited[a] = true;
		for(auto x : graph[a]){
			int b = x.first;
			int w = x.second;
			if(Ninfo[a] + w < Ninfo[b]) Ninfo[b] = Ninfo[a] + w;
			q.push(make_pair(-Ninfo[b], b));
		}
	}
	// for(int i = 1;i<=n;++i) cout<<Ninfo[i]<<' ';
	// cout<<endl<<endl;
	for(int i = 1;i<=k;++i){
		memset(visited, 0 , sizeof(visited));
		for(int i = 1;i<=n;++i) curBayinfo[i] = 20020226;		
		curBayinfo[tastiness[i].first] = 0;
		q.push(make_pair(0,tastiness[i].first));
		while(!q.empty()){
			int a = q.top().second;
			q.pop();
			if(visited[a]) continue;
			visited[a] = true;
			for(auto x : graph[a]){
				int b = x.first;
				int w = x.second;
				if(curBayinfo[a] + w < curBayinfo[b]) curBayinfo[b] = curBayinfo[a] + w;
				q.push(make_pair(-curBayinfo[b], b));
			}
		}

		// for(int i = 1;i<=n;++i) cout<<curBayinfo[i]<<' ';
		// cout<<endl<<endl;

		for(int j = 1;j<=n;++j){
			if(curBayinfo[j] + curBayinfo[n] <= Ninfo[j] + tastiness[i].second) answer[j] = true;
		}		
	}
	for(int i = 1;i<n;++i){
		if(answer[i]) cout<<1<<endl;
		else cout<<0<<endl;
	}	
	return 0;
}