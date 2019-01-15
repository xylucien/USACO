/*
ID: xinyu.l1
TASK: citystate
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
#define pc pair<string, string>
using namespace std;
const long long MAX = 2147483647;
int cnt[30][30][30][30];
pc myInfo[200010];
long long n, ans;

bool myEqual(int a){
	return (myInfo[a].first[0] == myInfo[a].second[0]) && (myInfo[a].first[1] == myInfo[a].second[1]);
}

void myInput(int i){
	++cnt[myInfo[i].first[0] - 'A'][myInfo[i].first[1] - 'A'][myInfo[i].second[0] - 'A'][myInfo[i].second[1] - 'A'];
}

inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("citystate.in","r",stdin);
	freopen("citystate.out","w",stdout);
	n = read();
	for(int i = 0;i<n;++i){
		cin>>myInfo[i].first>>myInfo[i].second;
		myInput(i);
	}
	for(int i = 0;i<n;++i){
		if(myEqual(i)) continue;
		int cur_cnt = cnt[myInfo[i].second[0] - 'A'][myInfo[i].second[1] - 'A'][myInfo[i].first[0] - 'A'][myInfo[i].first[1] - 'A'];
		ans+=cur_cnt;
	}
	cout<<ans/2<<endl;
	return 0;
}