/*
ID: xinyu.l1
TASK: escape
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

const int MAXN = 5000;
const int MAXM = 40000;
const int MOD =  1000000009;
int pointer = 0;
int n, m, graph[3010][3010];

inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool flag, visited[MAXN];

struct Edge{
    int u, v, w;
    bool used;
    bool operator<(const Edge &other) const { return w < other.w; }
}E[MAXM];

struct UnionFindSet {
    int a[MAXN];

    void init(const int n) { for (int i = 0; i < n; i++) a[i] = i; }

    int find(const int x) { return x == a[x] ? x : a[x] = find(a[x]); }

    void merge(const int x, const int y) {a[find(x)] = find(y);}

    bool test(const int x, const int y) { return find(x) == find(y); }
} MyUnionFindSet;

struct EdgeGroup {
    int used;
    vector<Edge> edges;
};

map<int, EdgeGroup> groups;

void Kruskal(){
    int cnt = 0, i = 0;
    MyUnionFindSet.init(n*m);
   	while(cnt!=n*m-1){
        if(!MyUnionFindSet.test(E[i].u, E[i].v)){
            MyUnionFindSet.merge(E[i].u, E[i].v);
            E[i].used = true;
            ++groups[E[i].w].used;
            ++cnt;
            //cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].w<<endl;
        }
        ++i;
    }
}

void printGraph(){
	for(int i = 0;i<pointer;++i){
		cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].w<<endl;
	}
}

int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	n = read();
	m = read();
    for(int j = 0;j<n;++j){
    	for(int i = 0;i<m-1;++i){
    		E[pointer].u = i*n + j;
    		E[pointer].v = (i+1)*n + j;
    		E[pointer].w = read();
    		groups[E[pointer].w].edges.push_back(E[pointer]);
    		++pointer;
    	}
    }
    for(int i = 0;i<n-1;++i){
    	for(int j = 0;j<m;++j){
    		E[pointer].u = i*n + j;
    		E[pointer].v = i*n + j+1;
    		E[pointer].w = read();
    		groups[E[pointer].w].edges.push_back(E[pointer]);
    		++pointer;
    	}
    }
    //printGraph();
    sort(E, E + 2*m*n-n-m);
    Kruskal();
    long long ans = 1;
    for (int i = 0; i < 2*m*n-m-n;++i) if(E[i].used) graph[E[i].u][E[i].v] = graph[E[i].v][E[i].u] = true;
    for (auto it = groups.begin(); it!=groups.end(); it++){
        if (it->second.used == 0) continue;
        int t = 0;
        for(unsigned int s = 1; s < (1 << it->second.edges.size()); s++){
            int popcount = 0;
            for(unsigned int i = 0; i < it->second.edges.size(); i++) if (s & (1 << i)) popcount++;
            if(popcount != it->second.used) continue;

            for(auto e = it->second.edges.begin(); e!=it->second.edges.end(); e++) {
                graph[e->u][e->v] = graph[e->v][e->u] = false;
            }

            for(auto e = it->second.edges.begin(); e!=it->second.edges.end(); e++) {
                if (!(s & (1 << (e - it->second.edges.begin())))) continue;
                graph[e->u][e->v] = graph[e->v][e->u] = true;
            }

            MyUnionFindSet.init(n*m);
            flag = false;
            for (int i = 0; i < n*m;++i) {
            	if(flag)break;
                for (int j = i + 1; j < n*m;++j) {
                    if (graph[i][j]){
                        if(MyUnionFindSet.test(i, j)){
                            flag = true;
                            break;
                        }
                        MyUnionFindSet.merge(i, j);
                    }
                }
            }
            if(!flag) ++t;
        }
        (ans*=t)%=MOD;
        for(auto e = it->second.edges.begin(); e != it->second.edges.end(); e++){
            graph[e->u][e->v] = graph[e->v][e->u] = e->used;
        }
    }
    cout<<ans<<endl;
    return 0;
}