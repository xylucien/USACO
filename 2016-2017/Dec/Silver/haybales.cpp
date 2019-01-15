/*
ID: xinyu.l1
TASK: haybales
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
const long long  MAX=2147483647;
#define N 100010
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
long long n,q,a[N],L[N],R[N];

int search_left(int val, int l, int r){
	if(val <= a[0]) return 0;
	if(val == a[l]) return l;
	if(l == r-1) return l;
	int mid = (l+r)/2 - 1;
	if(val > a[mid]) return search_left(val, mid+1, r);
	else return search_left(val, l, mid+1);
}

int search_right(int val, int l, int r){
	if(val >= a[n-1]) return n-1;
	if(val == a[l]) return l;
	if(l == r-1) return l - 1;
	int mid = (l+r)/2 - 1;
	if(val > a[mid]) return search_right(val, mid+1, r);
	else return search_right(val, l, mid+1);
}

int main(int argc, char const *argv[])
{
	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);
	n = read();
	q = read();
	for(int i = 0;i<n;++i) a[i] = read();
	sort(a, a+n);	
	for(int i = 0;i<q;++i){
		L[i] = read();
		R[i] = read();
		if(L[i] > a[n-1] || R[i] < a[0]) cout<<0<<endl;
		else cout<<search_right(R[i],0,n) - search_left(L[i],0,n) + 1<<endl;
	}
	return 0;
}