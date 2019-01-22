/*
ID: xinyu.l1
TASK: planting
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
int n, info[100010];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("planting.in","r",stdin);
	freopen("planting.out","w",stdout);
	n = read();
	int a,b;
	for(int i = 0;i<n-1;++i){
		a = read();
		b = read();
		++info[a];
		++info[b];
	}
	int Mymax = 0;
	for(int i = 0;i<100001;++i){
		Mymax = max(info[i],Mymax);
	}
	cout<<Mymax+1<<endl;
	return 0;
}