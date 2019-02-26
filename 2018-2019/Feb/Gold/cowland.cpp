/*
ID: xinyu.l1
TASK: cowland
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
const long long MAX = 400004;
#define lowbit(x) (x&-x)

int first[MAX],attraction[MAX],depth[MAX],edge[MAX<<1],nxt[MAX<<1],que[MAX],btree[MAX<<1];
int n,q;
int Mycase,edge_count,pos;
int f[MAX][20];
int head,tail;
int stk1[MAX],stk2[MAX],st[MAX],ed[MAX],top;
bool visited[MAX];

inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

void add_edge(int a,int b)
{
    edge_count++;
    edge[edge_count]=b,nxt[edge_count]=first[a],first[a]=edge_count;
    edge_count++;
    edge[edge_count]=a,nxt[edge_count]=first[b],first[b]=edge_count;
}

void update(int x,int value)
{
    while(x<=2*n){
        btree[x]^=value;
        x+=lowbit(x);
    }
}

int getsum(int x)
{
    int sum = 0;
    while(x>0){
        sum^=btree[x];
        x-=lowbit(x);
    }
    return sum;
}
 
int getLCA(int a,int b)
{
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for(int i=0;i<20;i++){
        if((diff>>i)&1)
        a=f[a][i];
    }
    if(a==b) return a;
    for(int i=19;i>=0;--i){
        if(f[a][i]!=f[b][i])
        a=f[a][i];
        b=f[b][i];
    }
    return f[a][0];
}

void change(int pos,int value)
{
    update(st[pos], attraction[pos]);
    update(ed[pos], attraction[pos]);
    update(st[pos], value);
    update(ed[pos], value);
    attraction[pos] = value;
}

int query(int a,int b)
{
    int c = getLCA(a,b);
    return getsum(st[a])^getsum(st[b])^attraction[c];
}

void dfs(int s)
{
    stk1[++top] = s;
    stk2[top] = first[s];
    st[s] = ++pos;
    depth[s] = 1;
    visited[s] = true;
    for(int i=0;i<19;i++)
    f[s][i] = 0;
    while(top){
        int i = stk2[top];
        if(i){
            int v = edge[i];
            stk2[top] = nxt[i];
            if(!visited[v]){
                visited[v] = true;
                depth[v] = depth[stk1[top]] + 1;
                f[v][0] = stk1[top];
                for(int i=1;i<19;++i) f[v][i] = f[f[v][i-1]][i-1];
                stk1[++top] = v;
                st[v] = ++pos;
                stk2[top] = first[v];
            }
        }
        else ed[stk1[top--]] = ++pos;
    }
}

int main()
{
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);
    int a,b;
    n = read();
    q = read();
    for(int i=1;i<=n;++i) attraction[i] = read();
    for(int i=1;i<n;++i){
        a = read();
        b = read();
        add_edge(a,b);
    }

    dfs(1);

    for(int i=1;i<=n;++i){
        update(st[i],attraction[i]);
        update(ed[i],attraction[i]);
    }
    for(int i=1;i<=q;++i){
        Mycase = read();
        a = read();
        b = read();
        if(Mycase == 1) change(a,b);
        else printf("%d\n", query(a,b));
    }
    return 0;
 }