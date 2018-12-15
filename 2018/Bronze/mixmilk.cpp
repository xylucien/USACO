/*
ID: xinyu.l1
TASK: mixmilk
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
int bucketsize[3], cur_milk[3];
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("mixmilk.in","r",stdin);
	freopen("mixmilk.out","w",stdout);
	cin>>bucketsize[0]>>cur_milk[0];
	cin>>bucketsize[1]>>cur_milk[1];
	cin>>bucketsize[2]>>cur_milk[2];
	for(int i = 0;i<100;++i){
		int cur_operation = i%3;
		int next_operation = (cur_operation+1)%3;
		int avaiable = bucketsize[next_operation] - cur_milk[next_operation];
		if(avaiable > cur_milk[cur_operation]){
			cur_milk[next_operation]+=cur_milk[cur_operation];
			cur_milk[cur_operation] = 0;
		}
		else{
			cur_milk[next_operation] = bucketsize[next_operation];
			cur_milk[cur_operation]-=avaiable;
		}
	}
	cout<<cur_milk[0]<<endl<<cur_milk[1]<<endl<<cur_milk[2]<<endl;
	return 0;
}