/*
ID: xinyu.l1
TASK: maxcross
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
int broken[100010];
int n, k, b;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool search(int x){
	if(x==b){
		if(n>=k) cout<<b<<endl;
		return true;
	}
	for(int i = 1+x;i<=b;++i){
		if((broken[i] - broken[i-x-1] - 1) >= k){
			cout<<x<<endl;
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	freopen("maxcross.in","r",stdin);
	freopen("maxcross.out","w",stdout);
	n = read();
	k = read();
	b = read();
	for(int i = 1;i<=b;++i){
		broken[i] = read();
	}
	sort(broken, broken+b+1);
	if(n+1-broken[b]>=k){cout<<0<<endl;return 0;}
	for(int rpr = 0;rpr<=b;++rpr){
		if(search(rpr)) return 0;
	}
	return 0;
}