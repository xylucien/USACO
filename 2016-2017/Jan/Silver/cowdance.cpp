/*
ID: xinyu.l1
TASK: cowdance
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
long long n, Tmax, cowInfo[10010];
multiset<long long> stage;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool search(int x){
	stage.clear();
	for(int i = 0;i<x;++i) stage.insert(cowInfo[i]);
	for(int i = x;i<n;++i){
		int a = *(stage.begin());
		stage.erase(stage.begin());
		a+=cowInfo[i];
		if(a>Tmax) return false;
		stage.insert(a);		
	}
	return true;
}

int main(int argc, char const *argv[])
{
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);
	n = read();
	Tmax = read();
	for(int i = 0;i<n;++i) cowInfo[i] = read();
	int l = 1, r = (n+1);
	while(1){
		if(l == r-1){
			cout<<l<<endl;
			return 0;
		}
		int mid = (l+r)/2 - 1;
		if(search(mid)) r = mid+1;
		else l = mid+1;
	}
	return 0;
}