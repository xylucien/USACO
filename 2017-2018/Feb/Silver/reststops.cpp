/*
ID: xinyu.l1
TASK: reststops
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

int L,N,rf,rc;
long long ans;
bool flag = false;
pair<int, int> info[100010];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

int find_next_max(int x){
	int Mymax = 0, pos;
	for(int i = x; i<=N;++i){
		if(info[i].second > Mymax){
			Mymax = info[i].second;
			pos = i;
		}
	}
	if(pos == N) flag = true;
	return pos;
}

int main(int argc, char const *argv[])
{
	freopen("reststops.in","r",stdin);
	//freopen("reststops.out","w",stdout);
	L = read();
	N = read();
	rf = read();
	rc = read();
	int last_position = 0;
	int tastiness;
	for(int i = 1;i<=N;++i){
		cin>>info[i].first>>info[i].second;
	}
	while(!flag){
		int next_goal = find_next_max(last_position+1);
		ans += (info[next_goal].first - info[last_position].first) * (rf - rc) * info[next_goal].second;
		last_position = next_goal;
	}
	cout<<ans<<endl;
	return 0;
}