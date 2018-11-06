/*
ID: xinyu.l1
TASK:kimbits
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
int n, max_bits, bits_count, start_bits; 
long long target, dp[50][50], sum;
bool num_info[50];

void determine(int cur_len){
	if(cur_len==0)return;
	sum = 0;
	for(int i = 0;i<=max_bits - bits_count;++i) sum+=dp[cur_len-1][i];
	if(sum<=target){
		target-=sum;
		num_info[cur_len] = true;
		++bits_count;
		determine(cur_len-1);
	}
	else determine(cur_len-1);
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	cin>>n>>max_bits>>target;
	for(int i = 0;i<=n;++i) dp[i][0] = 1;
	for(int j = 1;j<=n;++j){
		for(int k = 1;k<=max_bits;++k){
			dp[j][k] = dp[j-1][k-1] + dp[j-1][k];
		}
	}
	--target; 
	determine(n);
	for(int i = n; i >0; --i) cout<<num_info[i];
	cout<<endl;
	return 0;
}