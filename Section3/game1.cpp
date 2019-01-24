/*
ID: xinyu.l1
TASK: game1
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
int n;
int board[110];
int sum[110];
int state[110][110];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	n = read();
	for(int i = 1;i<=n;++i){
		board[i] = read();
		sum[i] += sum[i-1] + board[i];
		state[i][i] = board[i];
	}
	for(int i = n-1;i>=1;--i){
		for(int j = i+1;j<=n;++j){
			state[i][j] = max(sum[j] - sum[i-1] - state[i+1][j], sum[j] - sum[i-1] - state[i][j-1]);
		}
	}
	cout<<state[1][n]<<' '<<sum[n]-state[1][n]<<endl;
	return 0;
}