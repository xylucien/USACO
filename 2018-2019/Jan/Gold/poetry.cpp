/*
ID: xinyu.l1
TASK: poetry
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
int n,m,k;
long long MODULO = 1000000007;
int requirement[500];
int reached_K[1000000];
map<int, pair<vector<int>, long long> > rhymes;
multiset<int> length_kinds;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("poetry.in","r",stdin);
	freopen("poetry.out","w",stdout);
	n = read();
	m = read();
	k = read();
	int a,b;
	for(int i = 0;i<n;++i){
		a = read();
		b = read();
		length_kinds.insert(a);
		rhymes[b].first.push_back(a);
	}
	reached_K[0] = 1;
	for(int i = 0;i<k;++i){
		if(reached_K[i]){
			for(auto x = length_kinds.begin();x!=length_kinds.end();++x) reached_K[i+(*x)]+=reached_K[i];
		}
	}
	for(auto x = rhymes.begin(); x!=rhymes.end(); ++x){
		for(auto y = ((*x).second.first).begin(); y!=((*x).second.first).end(); ++y){
			(*x).second.second+=reached_K[k-(*y)];
		}
	}
	char c;
	for(int i = 0;i<m;++i){
		cin>>c;
		++requirement[c-'A'];
	}
	long long FinalAnswer = 1;
	for(int i = 0;i<26;++i){
		if(requirement[i]){
			long long cur = 0;
			for(auto x = rhymes.begin(); x!=rhymes.end(); ++x){
				cur+= (int)(pow((*x).second.second,requirement[i]));
			}
			//cur%=MODULO;
			FinalAnswer*=cur;
			//FinalAnswer%=MODULO;
		}
	}

	cout<<FinalAnswer%MODULO<<endl;
	return 0;
}