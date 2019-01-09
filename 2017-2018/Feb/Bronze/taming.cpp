/*
ID: xinyu.l1
TASK: taming
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
int myMin[101];
int ans_min = 1, ans_max = 1;
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("taming.in","r",stdin);
	freopen("taming.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i) cin>>myMin[i];
	if(myMin[0] > 0){
		cout<<-1<<endl;
		return 0;
	}
	myMin[0] = 0;
	for(int i = 1;i<n;++i){
		if(myMin[i] > i){
			cout<<-1<<endl;
			return 0;
		}
		if(myMin[i]==-1) continue;
		if(myMin[i]==0){++ans_min;continue;}
		if(myMin[i-myMin[i]] == -1)++ans_min;
		for(int j = 0;j<myMin[i];++j){
			if((myMin[i-myMin[i]+j] == -1) || (myMin[i-myMin[i]+j] == j)){
				myMin[i-myMin[i]+j] = j;
			}
			else{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	ans_max = ans_min;
	for(int i = 0;i<n;++i){
		if(myMin[i] == -1)++ans_max;
	}
	cout<<ans_min<<' '<<ans_max<<endl;
	return 0;
}