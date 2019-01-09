/*
ID: xinyu.l1
TASK: shuffle
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
const long long  MAX=2147483647;
int n, ans;
int myLinklist[100010];
bool visited[100010], f;
int cur_cnt;
set<pair<int,int>> cur_search;
void dfs(int x){
	visited[x] = true;
	if(!visited[myLinklist[x]]){
		++cur_cnt;
		cur_search.insert(make_pair(myLinklist[x],cur_cnt));
		dfs(myLinklist[x]);
	}
	if(f) return;
	bool flag = false;
	for(auto it = cur_search.begin(); it!=cur_search.end(); ++it){
		if((*it).first == myLinklist[x]) {flag = true; cur_cnt-=((*it).second - 1); break;}
	}
	if(!flag) cur_cnt = 0;
	f = true;
}

int main(int argc, char const *argv[])
{
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i) cin>>myLinklist[i];
	for(int i = 1;i<=n;++i){
		if(visited[i]) continue;
		cur_cnt = 1;
		cur_search.clear();
		cur_search.insert(make_pair(i,cur_cnt));
		f = false;
		dfs(i);
		ans+=cur_cnt;
	}
	cout<<ans<<endl;
	return 0;
}