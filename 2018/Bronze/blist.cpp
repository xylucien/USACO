/*
ID: xinyu.l1
TASK: blist
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
int n;
int info[10000];
int myMax;
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("blist.in","r",stdin);
	freopen("blist.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i){
		int a,b,cnt;
		cin>>a>>b>>cnt;
		for(int j = a;j<=b;++j){
			info[j]+=cnt;
		}
	}
	for(int i = 0;i<9999;++i){
		if(info[i]>myMax) myMax = info[i];
	}
	cout<<myMax<<endl;
	return 0;
}