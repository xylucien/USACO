/*
ID: xinyu.l1
TASK: countcross
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
int n, k, r;
int info[101][101];
bool visited[101][101];
int area[101][101];
int ans[100010], pointer;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

void init(){
	int a1, a2, b1, b2;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			info[i][j] = 15;
		}
	}
	for(int i = 1;i<=n;++i){
		info[1][i]--;
		info[n][i]-=4;
		info[i][1]-=8;
		info[i][n]-=2;		
	}
	for(int i = 0;i<r;++i){
		a1 = read(), a2 = read(), b1 = read(), b2 = read();
		if(a1==b1){
			info[a1][min(a2,b2)]-=2;
			info[a1][max(a2,b2)]-=8;
		}
		else{
			info[min(a1,b1)][a2]-=4;
			info[max(a1,b1)][a2]--;
		}
	}	
}

void printGraph(){
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			cout<<info[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}

void search(int i, int j){
	//cout<<i<<j<<' '<<pointer<<endl;
	area[i][j] = pointer;
	visited[i][j] = true;
	if((info[i][j]&1)      && !visited[i-1][j]) search(i-1,j);
	if(((info[i][j]>>1)&1) && !visited[i][j+1]) search(i,j+1);
	if(((info[i][j]>>2)&1) && !visited[i+1][j]) search(i+1,j);
	if(((info[i][j]>>3)&1) && !visited[i][j-1]) search(i,j-1);
}

int main(int argc, char const *argv[])
{
	freopen("countcross.in","r",stdin);
	freopen("countcross.out","w",stdout);
	n = read();
	k = read();
	r = read();
	init();
	//printGraph();
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			if(!visited[i][j]){++pointer;search(i,j);}
		}
	}
	for(int i = 0;i<k;++i){
		int x = read(), y = read();
		++ans[area[x][y]];
	}
	long long pairs = 1;
	for(int i = 1;i<=pointer;++i){
		for(int j = 1;j<=pointer;++j){
			if(i==j)continue;
			pairs+=ans[i]*ans[j];
		}
	}
	cout<<pairs/2<<endl;
	return 0;
}