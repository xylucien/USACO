/*
ID: xinyu.l1
TASK: pairup
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
pair<int, int> info[100010];
int n, ans, m;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
	n = read();
	for(int i = 0;i<n;++i){
		info[i].second = read();
		info[i].first = read();
		m+=info[i].second;	
	}
	sort(info, info+n);
	int l_pointer = 0, r_pointer = n-1;
	int l_cur = 0, r_cur = info[n-1].second;
	m/=2;
	for(int i = 0;i<m;++i){
		ans = max(ans, info[l_pointer].first + info[r_pointer].first);
		++l_cur; --r_cur;
		if(l_cur==info[l_pointer].second){++l_pointer; l_cur = 0;}
		if(r_cur==0)                     {--r_pointer; r_cur = info[r_pointer].second;}
	}
	cout<<ans<<endl;
	return 0;
}