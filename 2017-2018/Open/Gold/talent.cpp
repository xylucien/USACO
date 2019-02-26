/*
ID: xinyu.l1
TASK: talent
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
int n, w;
int weight[1000], score[1000];
pair<int, int> info[1000];
double dp[1000];
int cur_w, cur_s, pointer;
//double info[1000];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
bool cmp(pair<int, int> a, pair<int,int> b){
	if((double)a.second/a.first > (double)b.second/b.first) return true;
	else if ((double)a.second/a.first == (double)b.second/b.first) return a.first < b.first;
	return false;
}
int main(int argc, char const *argv[])
{
	freopen("talent.in","r",stdin);
	//freopen("talent.out","w",stdout);
	n = read();
	w = read();
	for(int i = 0;i<n;++i){
		weight[i] = read();
		score[i] = read();
		info[i].first = weight[i];
		info[i].second = score[i];
		//info[i] = (double) score[i]/weight[i];
	}
	sort(info,info+n,cmp);
	//for(int i = 0;i<n;++i) cout<<info[i].first<<' '<<info[i].second<<endl;
	// int i;
	// for(i = 0;i<n;++i){
	// 	if(cur_w + info[i].first>= w) break;
	// 	cur_w += info[i].first;
	// 	cur_s += info[i].second;		
	// }
	// double answer = (double)cur_s/cur_w*1000;
	// for(i;i<n;++i){
	// 	answer = max(answer, (double)(cur_s+info[i].second) /(cur_w + info[i].first));
	// }
		
	// cout<<i<<endl;
	bool flag = false;
	for(int i = 1;i<=n;++i){

		if(flag && dp[i] < dp[i-1]) {answer = dp[i-1]; break;}
	}
	cout<<(int) answer<<endl;
	//printf("%d\n", (double));
	return 0;
}