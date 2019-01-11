/*
ID: xinyu.l1
TASK: snowboots
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
int n,b;
int info[251];
pair<int, int> boots[251];
bool visited[251];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

int main(int argc, char const *argv[])
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	n = read();
	b = read();
	for(int i = 1;i<=n;++i) info[i] = read();
	for(int i = 0;i<b;++i){
		boots[i].first = read();
		boots[i].second = read();
	}
	visited[1] = true;
	for(int discard = 0;discard<=b;++discard){
		for(int i = 1;i<=n;++i){
			if(visited[i]){
				if(boots[discard].first < info[i]) continue;
				for(int step = boots[discard].second; step>=0; --step){
					if(step+i > n) continue;
					if(boots[discard].first >= info[i+step]) visited[i+step] = true;
				}
			}
		}
		if(visited[n]){
			cout<<discard<<endl;
			return 0;
		}
	}
	return 0;
}