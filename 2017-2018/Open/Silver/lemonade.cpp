/*
ID: xinyu.l1
TASK: lemonade
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
int n, info[100010];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool cmp(int a, int b){
	return a>b;
}

int main(int argc, char const *argv[])
{
	freopen("lemonade.in","r",stdin);
	freopen("lemonade.out","w",stdout);
	n = read();
	for(int i = 1;i<=n;++i)info[i] = read();
	sort(info+1, info+n+1, cmp);
	int ans = 0;
	for(int i = 1;i<=n;++i){
		if(info[i] >= i-1) ++ans;
		else break;
	}
	cout<<ans<<endl;
	return 0;
}