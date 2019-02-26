/*
ID: xinyu.l1
TASK: teamwork
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
int n,k,info[10001], dp[10001];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	n = read();
	k = read();
	for(int i = 1;i<=n;++i){
		info[i] = read();
	}
	for(int i = 1;i<=n;++i){
		dp[i] = dp[i-1] + info[i];
		int Mymax = info[i];
		for(int j = 1;j<k;++j){
			if(i-j<1) break;
			Mymax = max(Mymax, info[i-j]);
			dp[i] = max(dp[i], dp[i-j-1] + Mymax*(j+1));
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}