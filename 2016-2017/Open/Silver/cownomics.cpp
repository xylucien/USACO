/*
ID: xinyu.l1
TASK: cownomics
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

int n,m,ans;
string spotty[501], plain[501];
bool checked[501];

inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool NBmatch(int i, int j, int k){
	memset(checked,0,sizeof(checked));
	int set;
	for(int x = 0;x<n;++x){
		set = 0;
		if(spotty[x][i]=='A') set+=0;
		else if(spotty[x][i]=='C') set+=1;
		else if(spotty[x][i]=='G') set+=2;
		else if(spotty[x][i]=='T') set+=3;
		if(spotty[x][j]=='A') set+=0;
		else if(spotty[x][j]=='C') set+=4;
		else if(spotty[x][j]=='G') set+=8;
		else if(spotty[x][j]=='T') set+=12;
		if(spotty[x][k]=='A') set+=0;
		else if(spotty[x][k]=='C') set+=16;
		else if(spotty[x][k]=='G') set+=32;
		else if(spotty[x][k]=='T') set+=48;
		checked[set] = 1;
	}
	for(int x = 0;x<n;++x){
		set = 0;
		if(plain[x][i]=='A') set+=0;
		else if(plain[x][i]=='C') set+=1;
		else if(plain[x][i]=='G') set+=2;
		else if(plain[x][i]=='T') set+=3;
		if(plain[x][j]=='A') set+=0*4;
		else if(plain[x][j]=='C') set+=4;
		else if(plain[x][j]=='G') set+=8;
		else if(plain[x][j]=='T') set+=12;
		if(plain[x][k]=='A') set+=0*8;
		else if(plain[x][k]=='C') set+=16;
		else if(plain[x][k]=='G') set+=32;
		else if(plain[x][k]=='T') set+=48;
		if(checked[set]) return false;
	}
	return true;		
}

bool match(int i, int j, int k){
	for(int x = 0;x<n;++x){
		for(int y = 0;y<n;++y){
			if(spotty[x][i]==plain[y][i] && spotty[x][j]==plain[y][j] && spotty[x][k]==plain[y][k]) return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	n = read();
	m = read();
	for(int i = 0;i<n;++i)cin>>spotty[i];
	for(int i = 0;i<n;++i)cin>>plain[i];
	for(int i = 0;i<m;++i){
		for(int j = i+1;j<m;++j){
			for(int k = j+1;k<m;++k){
				if(NBmatch(i,j,k)) ++ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}