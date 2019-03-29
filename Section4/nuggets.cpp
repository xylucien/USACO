/*
ID: xinyu.l1
TASK: nuggets
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
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int n, info[100010], ans = 100000;
bool dp[256*256];
int main(int argc, char const *argv[])
{
	bool flag = false;
	dp[0] = 1;
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	n = read();
	for(int i = 0;i<n;++i){
		info[i] = read();
		if(info[i] == 1){
			cout<<0<<endl;
			return 0;
		}
	}
	for(int i = 0;i<n;++i){
		if(flag)break;
		for(int j = 0;j<n;++j){
			if(i==j)continue;
			if(__gcd(info[i],info[j]) == 1){
				flag = true;
				break;
			}
		}
	}
	if(!flag){
		cout<<0<<endl;
		return 0;
	}
	for(int i = 0;i<n;++i){
		for(int j = 0;j<256*256;++j){
			if(dp[j]){
				dp[j+info[i]] = 1;
				//if(dp[j+info[i]-1]) ans = min(ans, j+info[i]-2);
				//else if(dp[j+info[i]+1]) ans = min(ans, j+info[i]-1);
			}
		}
	}
	for(int i = 0;i<256*256;++i){
		if(!dp[i]) ans = i;
	}
	cout<<ans<<endl;
	return 0;
}