/*
ID: xinyu.l1
TASK: rockers
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
int n, t, m;
int ans;
int info[100];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

struct state
{
	int cur_disk, cur_length, last_song, song_num;	
};

void printState(state x){
	cout<<x.cur_disk<<' '<<x.cur_length<<' '<<x.last_song<< ' ' << x.song_num << endl;
}

void bfs(){
	queue<state> q;
	q.push(state{1,0,-1,0});
	while(!q.empty()){
		state cur = q.front();
		q.pop();
		//printState(cur);
		ans = max(ans, cur.song_num);
		for(int i = cur.last_song+1;i<n;++i){
			if(info[i] > t) continue;
			if(cur.cur_length + info[i] > t){
				if(cur.cur_disk == m) continue;
				else q.push(state{cur.cur_disk+1, info[i], i, cur.song_num+1});
			}
			else q.push(state{cur.cur_disk, cur.cur_length+info[i], i, cur.song_num+1});
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	n = read();
	t = read();
	m = read();
	for(int i = 0;i<n;++i) info[i] = read();
	bfs();
	cout<<ans<<endl;
	return 0;
}