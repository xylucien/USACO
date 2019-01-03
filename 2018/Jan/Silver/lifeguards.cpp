/*
ID: xinyu.l1
TASK: lifeguards
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
const long long  MAX=2147483647;
#define N 100010
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int n,a[N<<1],L[N],R[N],num=0,m,ans=0;
struct node{
    int len,covlen,is_covered;
}mySegTree[N<<4];
inline void pushup(int p){
    if(mySegTree[p].is_covered) return;
    mySegTree[p].covlen = mySegTree[p<<1].covlen + mySegTree[p<<1|1].covlen;
}
inline void build(int p,int l,int r){
    if(l==r){mySegTree[p].len=a[l+1]-a[l];return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    mySegTree[p].len = mySegTree[p<<1].len + mySegTree[p<<1|1].len;
}
inline void cover(int p,int l,int r,int x,int y){
    if(x<=l&&y>=r){
        mySegTree[p].is_covered++;
        if(mySegTree[p].is_covered==1) mySegTree[p].covlen=mySegTree[p].len;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid) cover(p<<1,l,mid,x,y);
    if(y>mid) cover(p<<1|1,mid+1,r,x,y);
    pushup(p);
}
inline void del(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        mySegTree[p].is_covered--;
        if(mySegTree[p].is_covered==0){
            if(l==r) mySegTree[p].covlen = 0;
            else pushup(p);
        }
        return;
    }
    int mid=l+r>>1;
    if(x<=mid) del(p<<1,l,mid,x,y);
    if(y>mid) del(p<<1|1,mid+1,r,x,y);
    pushup(p);
}
int main(){
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[++num]=L[i]=read();
        a[++num]=R[i]=read();
    }
    sort(a+1,a+num+1);
    //unique elements
    m = unique(a+1,a+num+1)-a-1;
    build(1,1,m-1);
    for(int i=1;i<=n;++i){
        L[i]=lower_bound(a+1,a+m+1,L[i])-a;
        R[i]=lower_bound(a+1,a+m+1,R[i])-a;
        cover(1,1,m-1,L[i],R[i]-1);
    }
    for(int i=1;i<=n;++i){
        del(1,1,m-1,L[i],R[i]-1);
        ans=max(ans,mySegTree[1].covlen);
        cover(1,1,m-1,L[i],R[i]-1);
    }
    printf("%d\n",ans);
    return 0;
}
/*
vector<int> working_cows;
struct lifeguard
{
	int start_t, end_t, alone_t;
}lifeguards[100010];

bool cmp(lifeguard a, lifeguard b){
	return a.start_t < b.start_t;
}
int n, total_t, myMin;
int main(int argc, char const *argv[])
{
	freopen("lifeguards.in","r",stdin);
	//freopen("lifeguards.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i) cin>>lifeguards[i].start_t>>lifeguards[i].end_t;
	sort(lifeguards,lifeguards+n,cmp);
	int cur_pos = 0, cur_time = lifeguards[0].start_t;
	while(cur_pos < n){
		for(auto x = working_cows.begin();x!=working_cows.end();++x){
			if(lifeguards[*x].end_t <= lifeguards[cur_pos].start_t)
		}
	}
	return 0;
}
*/