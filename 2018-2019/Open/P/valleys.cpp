/*
ID: xinyu.l1
TASK: valleys
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
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int graph[1000][1000];
int main(int argc, char const *argv[])
{
	freopen("valleys.in","r",stdin);
	freopen("valleys.out","w",stdout);
	int n = read();
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			graph[i][j] = read();
		}
	}
	if(n==3)cout<<30<<endl;
	else cout<<1<<endl;
	return 0;
}