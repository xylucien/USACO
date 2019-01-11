/*
ID: xinyu.l1
TASK: teleport
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
long long ans;
int n;
pair<int, int> info[100010];
map<int, int> f;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

int main(int argc, char const *argv[])
{
	freopen("teleport.in","r",stdin);
	freopen("teleport.out","w",stdout);
	n = read();
	for(int i = 0;i<n;++i){
		int a = info[i].first = read();
		int b = info[i].second = read();
		int diff = abs(a-b);
		ans+=diff;
		if(abs(a) > diff) continue;
		f[b]+=2;
		if((a<b&&a<=0) || (a>b&&a>0)){
			--f[0];
			--f[2*b];
		}
		if((a>b&&a<=0) || (a<b&&a>0)){
			--f[2*a];
			--f[2*b-2*a];
		}
	}
	int cur_slope = 0, cur_y = -10000000;
	long long cur_ans = ans;
	for(auto x : f){
		int new_y = x.first, d_slope = x.second;
		cur_ans+=(new_y - cur_y) * cur_slope;
		cur_slope += d_slope;
		cur_y = new_y;
		ans = min(ans, cur_ans);
	}
	cout<<ans<<endl;
	return 0;
}