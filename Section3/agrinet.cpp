/*
ID: xinyu.l1
TASK: agrinet
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>
#define MAX 10000000

using namespace std;

int n;
int info[101][101];
bool visited[101];
int answer = 0;
int Mycount = 1;

void prim(){
	int cur_min = MAX;
	int new_i = -1;
	int new_j = -1;
	for(int x = 0;x<n;++x){
		if(visited[x]){
			for(int i = 0;i<n;++i){
				if(x != i){
					if(!visited[i] && cur_min > info[x][i]){
						cur_min = info[x][i];
						new_i = x;
						new_j = i;
					}
				}
			}
		}
	}
	visited[new_j] = true;
	answer+=cur_min;
	++Mycount;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			cin>>info[i][j];
		}
	}
	visited[0] = true;
	while(Mycount != n) prim();
	cout<<answer<<endl;
	return 0;
}