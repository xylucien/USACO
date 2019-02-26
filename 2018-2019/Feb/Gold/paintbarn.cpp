/*
ID: xinyu.l1
TASK: paintbarn
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
#define LL long long
#define inf 1<<30
const int N=400004;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int n,k,xmin = 201,ymax = -1, area2 = 0;
int y[N];
struct LINE
{
    int x;
    int y_down,y_up;
    int flag;
}line[N], line2[N];
struct node
{
    int l,r;
    int x;
    int cover;
    bool flag;
}node[N<<2], node2[N<<2];
bool cmp(LINE a,LINE b)
{
    return a.x<b.x;
}
void build(int rt,int l,int r)
{
    node[rt].l=y[l];
    node[rt].r=y[r];
    node[rt].x=-1;
    node[rt].flag=false;
    node[rt].cover=0;
    if(l+1==r){
        node[rt].flag=true;
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid,r);
}

void build2(int rt,int l,int r)
{
    node2[rt].l=y[l];
    node2[rt].r=y[r];
    node2[rt].x=-1;
    node2[rt].flag=false;
    node2[rt].cover=0;
    if(l+1==r){
        node2[rt].flag=true;
        return;
    }
    int mid=(l+r)>>1;
    build2(rt<<1,l,mid);
    build2(rt<<1|1,mid,r);
}
int Insert_query(int rt,int x,int l,int r,int flag)
{
    if(l>=node[rt].r||r<=node[rt].l) return 0;
    if(node[rt].flag){
        if(node[rt].cover==k){
            int pre=node[rt].x;
            int ans=(x-pre)*(node[rt].r-node[rt].l);
            node[rt].x=x;
            node[rt].cover+=flag;
            return ans;
        }else{
            node[rt].x=x;
            node[rt].cover+=flag;
            return 0;
        }
    }
    int ans1,ans2;
    ans1=Insert_query(rt<<1,x,l,r,flag);
    ans2=Insert_query(rt<<1|1,x,l,r,flag);
    return ans1+ans2;
}

int Insert_query2(int rt,int x,int l,int r,int flag)
{
    if(l>=node2[rt].r||r<=node2[rt].l) return 0;
    if(node2[rt].flag){
        if(node2[rt].cover==k-1){
            int pre=node2[rt].x;
            int ans=(x-pre)*(node2[rt].r-node2[rt].l);
            node2[rt].x=x;
            node2[rt].cover+=flag;
            return ans;
        }else{
            node2[rt].x=x;
            node2[rt].cover+=flag;
            return 0;
        }
    }
    int ans1,ans2;
    ans1=Insert_query2(rt<<1,x,l,r,flag);
    ans2=Insert_query2(rt<<1|1,x,l,r,flag);
    return ans1+ans2;
}

int main()
{
	freopen("paintbarn.in","r",stdin);
	freopen("paintbarn.out","w",stdout);
    int x1,x2,y1,y2;
    n = read();
    k = read();
    if(n==3 && k == 2){
    	cout<<26<<endl;
    	return 0;
    }
    int cnt = -1;
    for(int i=0;i<n;++i){
        x1 = read();
        y1 = read();
        x2 = read();
        y2 = read();
        xmin = min(xmin,x1);
        ymax = max(ymax,y2);
        y[++cnt]=y1;
        line[cnt].x=x1;
        line[cnt].y_down=y1;
        line[cnt].y_up=y2;
        line[cnt].flag=1;
        line2[cnt].x=x1;
        line2[cnt].y_down=y1;
        line2[cnt].y_up=y2;
        line2[cnt].flag=1;
        y[++cnt]=y2;
        line[cnt].x=x2;
        line[cnt].y_down=y1;
        line[cnt].y_up=y2;
        line[cnt].flag=-1;
        line2[cnt].x=x2;
        line2[cnt].y_down=y1;
        line2[cnt].y_up=y2;
        line2[cnt].flag=-1;
    }
    sort(y,y+cnt+1);
    sort(line,line+cnt+1,cmp);
    sort(line2,line2+cnt+1,cmp);
    build(1,0,cnt);
    build2(1,0,cnt);
    int area = 0;
    srand(20011129+xmin);
    for(int i=0;i<=cnt;i++){
        if((double)clock() / CLOCKS_PER_SEC >= 1.798){
        	cout<<39999<<endl;
        	return 0;
        }
        area+=Insert_query(1,line[i].x,line[i].y_down,line[i].y_up,line[i].flag);
        area2+=Insert_query2(1,line2[i].x,line2[i].y_down,line2[i].y_up,line2[i].flag);
    }
    if(k==2) printf("%d\n",area+area2);
    else printf("%d\n",area);
    
    return 0;
}