/*
ID: xinyu.l1
TASK: multimoo
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
bool visited[251][251];
int n, ans1, ans2;
int original[251][251];

inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int bfs_pointer, cur_size, curcursize;
int belong[62510];
bool blocks_visited[62510];
int discretete[1000010];
set<int> discrete;
int discrete_arr[62510];
pair<int, int> nb[90000];
struct block
{
	int size, ID;
	set<int> connected;
	//map<int, int> connectedInfo;
}graph[62510];

/*
void printMap(int i){
	for(auto x = graph[i].connectedInfo.begin(); x != graph[i].connectedInfo.end(); ++x){
		cout<<x->first<<' '<<x->second<<endl;
	}
	cout<<endl;
}

void printSet(int i){
	for(auto x = graph[i].connected.begin(); x != graph[i].connected.end(); ++x){
		cout<<*x<<endl;
	}
	cout<<endl;	
}
*/
void find(int i, int j){
	if(i<n-1 && original[i+1][j]!=original[i][j]){
		if((graph[belong[i*n+j]].connected.insert(belong[(i+1)*n+j])).second ){
			graph[belong[(i+1)*n+j]].connected.insert(belong[i*n+j]);
		}
	}
	if(j<n-1 && original[i][j+1]!=original[i][j]){
		if((graph[belong[i*n+j]].connected.insert(belong[i*n+j+1])).second ){
			graph[belong[i*n+j+1]].connected.insert(belong[i*n+j]);			
		}
	}
} 

void dfs(int i, int j, int val){
	if(visited[i][j]) return;
	visited[i][j] = true;
	belong[i*n+j] = bfs_pointer;
	if(i>0 && original[i-1][j]==val && !visited[i-1][j]){
		++graph[bfs_pointer].size;
		dfs(i-1,j,val);
	}
	if(i<n-1 && original[i+1][j]==val && !visited[i+1][j]){
		++graph[bfs_pointer].size;
		dfs(i+1,j,val);
	}
	if(j>0 && original[i][j-1]==val && !visited[i][j-1]){
		++graph[bfs_pointer].size;
		dfs(i,j-1,val);
	}
	if(j<n-1 && original[i][j+1]==val && !visited[i][j+1]){
		++graph[bfs_pointer].size;
		dfs(i,j+1,val);
	}
}

void block_dfs(int a, int b, int block){
	if(blocks_visited[block]) return;
	blocks_visited[block] = true;
	curcursize+=graph[block].size;
	for(auto x = graph[block].connected.begin(); x!=graph[block].connected.end(); ++x){
		if(graph[*x].ID == a || graph[*x].ID == b) block_dfs(a,b,*x);
	}
}

void search(int a, int b){
	for(int i = 1;i<=bfs_pointer;++i){
		if((graph[i].ID == a || graph[i].ID == b) && !blocks_visited[i]){
			curcursize = 0;
			block_dfs(a,b,i);
			cur_size = max(curcursize, cur_size);
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("multimoo.in","r",stdin);
	freopen("multimoo.out","w",stdout);
	n = read();
	int temp_max = 0;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			original[i][j] = read();
			++discretete[original[i][j]];
			temp_max = max(original[i][j],temp_max);
		}
	}
	int m = 0;
	for(int i = 0;i<=temp_max;++i){
		if(discretete[i]) {discrete_arr[m] = i;++m;}
	}
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			if(!visited[i][j]){
				++bfs_pointer;
				++graph[bfs_pointer].size;
				graph[bfs_pointer].ID = original[i][j];
				dfs(i,j,original[i][j]);
				ans1 = max(ans1,graph[bfs_pointer].size);
			}
		}
	}
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			find(i,j);
		}	
	}

	srand(unsigned(time(NULL)));
	for(int i = 0;i<6000000;++i){
		cur_size = 0;
		memset(blocks_visited,0,sizeof(blocks_visited));
		int ii=rand()%m, jj=rand()%m;
		while(ii==jj){ii = rand()%n+1;}
		search(discrete_arr[ii],discrete_arr[jj]);
		ans2 = max(ans2, cur_size);
		
		if((double)clock() / CLOCKS_PER_SEC >= 1.97){
			cout<<ans1<<endl<<ans2<<endl;
			return 0;
		}
	}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}