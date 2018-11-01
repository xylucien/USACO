/*
ID: xinyu.l1
TASK: ariprog
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
struct dict
{
	int x,y;
}answer[10010];

bool cmp(dict a, dict b){
	return (a.y<b.y || (a.y==b.y && a.x<b.x));
}

int n,m;
int bisquare[400000]; 
bool used[400000];
int pointer = -1;

/*
void print_result(int b){
	for(int i = 0;i<=bisquare[pointer-1];++i){
		if(info[i]) {
			if(!flag)flag = true;
			cout<<i<<' '<<b<<endl;
		}
	}
	memset(info,false,bisquare[pointer-1]+1);
	memset(used,false,pointer-1);
}
void search(int start_index, int b){
	if(used[start_index]) return;
	int times = 1;
	for(int j = start_index + 1; j<pointer; ++j){
		if(bisquare[j] > (bisquare[start_index] + times*b)) break;
		if(bisquare[j] == (bisquare[start_index] + times*b)){
			used[j] = true;
			++times;
		}
	}
	int excess = times - n;
	int xx = 0;
	while(excess>=0){
		info[bisquare[start_index] + xx*b] = true;
		++xx;
		--excess;
	}
}
*/
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	cin>>n;cin>>m;
	for(int i = 0;i<=m;++i){
		for(int j = i;j<=m;++j){
			if(!used[i*i+j*j]) bisquare[++pointer] = (i*i+j*j);
			used[i*i+j*j] = true;
		}
	}
	++pointer;
	sort(bisquare,bisquare+pointer);
	int p = 0;
	for(int i = 0;i<pointer-n+1;++i){
		for(int j = i+1;j<pointer;++j){
			int diff = bisquare[j] - bisquare[i];
			int final_num = bisquare[i]+diff*(n-1);
			if(final_num > bisquare[pointer-1]) break;
			int count = 0;
			for(int k = bisquare[i];k<=final_num;k+=diff){
				if(used[k]) ++count;
				else break;
			}
			if(count == n){
				answer[p].x = bisquare[i];
				answer[p].y = diff;
				++p;
			} 
		}
	}

	/*max_diff = bisquare[pointer-1];
	memset(used,false,pointer-1);
	for(int diff = 1;diff<=max_diff;++diff){	
		for(int i = 0;i<pointer-n+1;++i){
			if(bisquare[i]+diff*(n-1) <= max_diff) search(i,diff);
			else break;
		}
		print_result(diff);
	}*/
	
	if(p==0) cout<<"NONE"<<endl;
	else{
		sort(answer,answer+p,cmp);
		for(int i = 0;i<p;++i) cout<<answer[i].x<<" "<<answer[i].y<<endl;
	}
	return 0;
}