/*
ID: xinyu.l1
TASK: helpcross
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
int n, m, ans;
int chickenInfo[100010];
pair<int, int> cowInfo[100010];
bool helped[100010];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool cmp(pair<int, int> a, pair<int, int> b){
	int deltaA = a.second - a.first;
	int deltaB = b.second - b.first;
	return (deltaA!=deltaB) ? (deltaA<deltaB) : (a.first - b.first);
}

bool cmp2(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	freopen("helpcross.in","r",stdin);
	freopen("helpcross.out","w",stdout);
	n = read();
	m = read();
	for(int i = 0;i<n;++i){
		chickenInfo[i] = read();
	}
	for(int i = 0;i<m;++i){
		cowInfo[i].first = read();
		cowInfo[i].second = read();	
	}
	sort(chickenInfo,chickenInfo+n);
	sort(cowInfo,cowInfo+m, cmp2);
	for(int i = 0;i<n;++i){
		for(int j = 0;j<m;++j){
			if(!helped[j] && chickenInfo[i] >= cowInfo[j].first && chickenInfo[i] <= cowInfo[j].second){
				++ans;
				helped[j] = true;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}