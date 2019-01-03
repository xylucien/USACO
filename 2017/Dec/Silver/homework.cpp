/*
ID: xinyu.l1
TASK: homework
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
int n,k;
int info[100001];
double sum[100001];
vector<int> ans;
int main(int argc, char const *argv[])
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i) cin>>info[i];
	for(int i = n-1;i>=0;--i){
		if(i==n-1) sum[n-1] = info[n-1];
		else sum[i] = sum[i+1] + info[i];
	}
	int cur_min = info[n-1];
	for(int i = n-1;i>=0;--i){
		cur_min = cur_min > info[i] ? info[i] : cur_min;
		sum[i]-=cur_min;
		sum[i]/=(n-i-1);
	}
	double cur_max = sum[0];
	for(int i = 1;i<n-1;++i){
		if(sum[i] < cur_max) continue;
		else if(sum[i] > cur_max){
			ans.clear();
			cur_max = sum[i];
			ans.insert(ans.end(),i);
		}
		else ans.insert(ans.end(),i);
	}
	for(auto x = ans.begin();x!=ans.end();++x) cout<<*x<<endl;
	return 0;
}