/*
ID: xinyu.l1
TASK: piepie
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
int n, d;
int dist[200001], B[200002], E[200002];
//pair<int, int> B[100001], E[100001];
//int E1[100001], E2[100001], B1[100001], B2[100001];
queue<pair<int, int> > searching_queue; 
const long long MAX = 2147483647;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
struct cmpB
{
	bool operator()(int a, int b) const{
		return E[a] < E[b];
	}	
};

struct cmpE
{
	bool operator()(int a, int b) const{
		return B[a] < B[b];
	}	
};

/*
pair<int, int> get_pair(int x){
	if(x<n) return B[x];
	else return E[x-n];
}
void update(int point){
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int> > searching_queue;
	searching_queue.push(make_pair(point, 1));
	while(!searching_queue.empty()){
		pair<int, int> temp = searching_queue.front();
		searching_queue.pop();
		if(visited[temp.first]) continue;
		visited[temp.first] = true;
		for(int i = 0;i<2*n;++i){
			if(info[temp.first][i] && temp.first!=i){
				dist[i] = min(temp.second+1, dist[i]);
				searching_queue.push(make_pair(i,temp.second+1));
			}
		}
	}
}
*/
multiset<int, cmpB> setB;
multiset<int, cmpE> setE;

int main(int argc, char const *argv[])
{
	freopen("piepie.in","r",stdin);
	freopen("piepie.out","w",stdout);
	n = read();
	d = read();
	for(int i = 0;i<2*n;++i){
		B[i] = read();
		E[i] = read();
		B[i] = -B[i];
		E[i] = -E[i];
		dist[i] = -1;
	}
	for(int i = 0;i<n;++i){
		if(E[i] == 0) {searching_queue.push(make_pair(i, 1)); dist[i] = 1;}
		else setB.insert(i);
		if(B[i+n] == 0) {searching_queue.push(make_pair(i+n, 1)); dist[i+n] = 1;}
		else setE.insert(i+n);
	}
	while(!searching_queue.empty()){
		int point = searching_queue.front().first;
		int step  = searching_queue.front().second;
		//cout<<point<<' '<<step<<endl;
		searching_queue.pop();
		if(point < n){
			while(1){
				auto Mylow = setE.lower_bound(point);
				if(Mylow == setE.end() || B[*Mylow] > d+B[point]) break;
				dist[*Mylow] = step + 1;
				searching_queue.push(make_pair(*Mylow, step+1));
				setE.erase(Mylow);
			}
		}
		else{
			while(1){
				auto Mylow = setB.lower_bound(point);
				if(Mylow == setB.end() || E[*Mylow] > d+E[point]) break;
				dist[*Mylow] = step + 1;
				searching_queue.push(make_pair(*Mylow, step+1));
				setB.erase(Mylow);
			}
		}
	}
	for(int i = 0;i<n;++i) cout<<dist[i]<<endl;
	// for(int i = 0;i<n;++i){
	// 	dist[i] = 20020226;
	// 	B[i].first = read();
	// 	B1[i] = B[i].first;
	// 	B[i].second = read();
	// 	B2[i] = B[i].second;
	// 	if(B[i].second == 0){
	// 		dist[i] = 1;
	// 		start.push_back(i);
	// 	}
	// }
	// for(int i = 0;i<n;++i){
	// 	dist[i+n] = 20020226;
	// 	E[i].second = read();
	// 	E2[i] = E[i].second;
	// 	E[i].first = read();
	// 	E1[i] = E[i].first;
	// 	if(E[i].first == 0) start.push_back(i+n);
	// }
	// sort(B,B+n);
	// sort(E,E+n);
	// sort(E1, E1+n);
	// sort(B1, B1+n);
	// for(int i = 0;i<n;++i){
	// 	int Mylow = lower_bound(E1,E1+n,B[i].second) - E1;
	// 	for(int j = Mylow;j<n;++j){
	// 		if(E1[j] > d + B[i].second) break;
	// 		info[n+j][i] = true;
	// 	}
	// 	Mylow = lower_bound(B1,B1+n,E[i].second) - B1;
	// 	for(int j = Mylow;j<n;++j){
	// 		if(B1[j] > d + E[i].second) break;
	// 		info[j][n+i] = true;
	// 	}
	// }
	// for(auto x = start.begin();x!=start.end();++x){
	// 	update(*x);
	// }
	// for(int i = 0;i<n;++i){
	// 	if((dist[i]) == 20020226) cout<<-1<<endl;
	// 	else cout<<dist[i]<<endl;
	// }
	// for(int i = 0;i<2*n;++i){
	// 	for(int j = 0;j<2*n;++j){
	// 		cout<<info[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	//cout<<E[0].first<<' '<<E[1].first<<endl;
	return 0;
}