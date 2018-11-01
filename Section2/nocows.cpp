/*
ID: xinyu.l1
TASK: nocows
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
int cnt = 0;
int target_node,target_tier;
bool Btree_visited[210][210];
int Btree[210][210];

int dfs(int cur_node, int cur_tier){
	if(Btree_visited[cur_tier][cur_node]) return Btree[cur_tier][cur_node];
	if(cur_node == 1) return cur_tier == 1;
	Btree_visited[cur_tier][cur_node] = true;
	if(cur_tier > (cur_node+1)/2) return 0;
	if(cur_tier<2) return 0;
	for(int i = 1;i<cur_node;i+=2){
		for(int j = 1; j< cur_tier;++j){
			int coefficient = 1;
			if(j!=cur_tier-1) coefficient = 2;
			Btree[cur_tier][cur_node] += coefficient*dfs(i,cur_tier-1)*dfs(cur_node-i-1,j);
			Btree[cur_tier][cur_node] %= 9901;
		}
	}
	return Btree[cur_tier][cur_node];
}

int main(int argc, char const *argv[])
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	cin>>target_node>>target_tier;
	cout<<dfs(target_node,target_tier)<<endl;
	return 0;
}