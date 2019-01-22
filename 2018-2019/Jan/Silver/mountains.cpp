/*
ID: xinyu.l1
TASK: mountains
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
int n, ans;
pair<int, int> mountains[100010];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	freopen("mountains.in","r",stdin);
	freopen("mountains.out","w",stdout);
	n = read();
	for(int i = 0;i<n;++i){
		mountains[i].first = read();
		mountains[i].second = read();
	}
	sort(mountains,mountains+n,cmp);
	int pointer;
	bool flag;
	for(int i = 0;i<n-1;++i){
		pointer = i+1;
		flag = true;
		while(mountains[pointer].second == mountains[i].second) ++pointer;
		while(pointer<n){
			int d = abs(mountains[pointer].first - mountains[i].first);
			if(mountains[pointer].second - d >= mountains[i].second){
				flag = false;
				break;
			}
			++pointer;
		}
		if(flag) ++ans;
	}
	cout<<ans+1<<endl;
	return 0;
}