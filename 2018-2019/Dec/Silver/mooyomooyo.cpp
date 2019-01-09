/*
ID: xinyu.l1
TASK: mooyomooyo
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
vector<pair<int,int>> currentInfo;
int k,n;
int info[110][10];
bool visited[110][10];
bool indicator = true;
void clearVisited(){
	for(int i = 0;i<n;++i){
		for(int j = 0;j<10;++j){
			visited[i][j] = false;
		}
	}
}

void printGraph(){
	for(int i = 0;i<n;++i){
		for(int j = 0;j<10;++j){
			cout<<info[i][j];
		}
		cout<<endl;
	}
}

void bfs(int color, int i, int j){
	if((i < n-1) && info[i+1][j] == color && !visited[i+1][j]){
		visited[i+1][j] = true;
		currentInfo.push_back(make_pair(i+1,j));
		bfs(color,i+1,j);
	}

	if((i > 0) && info[i-1][j] == color && !visited[i-1][j]){
		visited[i-1][j] = true;
		currentInfo.push_back(make_pair(i-1,j));
		bfs(color,i-1,j);
	}

	if((j < 9) && info[i][j+1] == color && !visited[i][j+1]){
		visited[i][j+1] = true;
		currentInfo.push_back(make_pair(i,j+1));
		bfs(color,i,j+1);
	}

	if((j > 0) && info[i][j-1] == color && !visited[i][j-1]){
		visited[i][j-1] = true;
		currentInfo.push_back(make_pair(i,j-1));
		bfs(color,i,j-1);
	}
}

void doit(){
	clearVisited();
	bool flag = false;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<10;++j){
			if(info[i][j] == 0) continue;
			int cur_color = info[i][j];
			bfs(cur_color,i,j);
			if(currentInfo.size() >= k){
				flag = true;
				for (auto x = currentInfo.begin(); x != currentInfo.end(); ++x){
					info[(*x).first][(*x).second] = 0;
				} 
			}
			currentInfo.clear();
		}
	}
	if(flag){
		for(int i = 0;i<10;++i){
			for(int j = n-2;j>=0;--j){
				if(info[j][i]==0) continue;
				if(info[j+1][i]!=0) continue;
				for(int k = n-1;k>=0;--k){
					if(info[k][i] == 0){
						info[k][i] = info[j][i];
						info[j][i] = 0;
						break;
					}
				}
			}
		}
	}
	indicator = flag;	
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i<n;++i){
		long long temp;
		cin>>temp;
		for(int j = 9;j>=0;--j){
			info[i][j] = temp%10;
			temp/=10;
		}
	}
	
	while(indicator) doit();
	printGraph();
	return 0;
}