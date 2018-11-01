/*
ID: xinyu.l1
TASK: concom
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
short cur_info[110];
short info[110][110];
bool flag = false;
bool visited[110];
bool controlled[110];

void Louise(int n){
	if(visited[n]) return;
	visited[n] = true;
	for(int j = 1;j<=100;++j){
		cur_info[j] += info[n][j];
		if(cur_info[j]>50){
				controlled[j] = true;
				Louise(j);
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	
	cin>>N;
	for(int i = 0;i<N;++i){
		int a,b;
		cin>>a>>b;
		cin>>info[a][b];
	}

	for(int i = 1;i<=100;++i){
		memset(cur_info,0,sizeof(cur_info));
		memset(visited,false,sizeof(visited));
		memset(controlled,false,sizeof(controlled));
		Louise(i);
		for(int x = 1;x<=100;++x){
			if(controlled[x] && x!=i) {cout<<i<<' '<<x<<endl;flag = true;}
		}
	}

	if(!flag) cout<<0<<endl;
	return 0;
}