/*
ID: xinyu.l1
TASK: numtri
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int info[1001][1001];
int f[1001][1001];
bool visited[1001][1001];
int n;

int find(int x, int y){
	if(y==n-1){
		visited[x][y] = true;
		f[x][y] = info[x][y];
		return f[x][y];
	}
	if(!visited[x][y+1]) {
		visited[x][y+1] = true;
		f[x][y+1] = find(x,y+1);
	}
	if(!visited[x+1][y+1]) {
		visited[x+1][y+1] = true;
		f[x+1][y+1] = find(x+1,y+1);
	}
	f[x][y] = max(info[x][y]+f[x][y+1],info[x][y]+f[x+1][y+1]);
	visited[x][y] = true;
	return f[x][y];
}

int main(int argc, char const *argv[])
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<=i;++j) cin>>info[j][i];
	}
	cout<<find(0,0)<<endl;
	return 0;
}