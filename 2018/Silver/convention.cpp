/*
ID: xinyu.l1
TASK: convention
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
int arrvied_time[100010];
int diff_info[10001][10001];
int n,m,c;
int myMax = 999999;

void recur(int cur_bus, int num, int c_index, int cur_wait){
	if(cur_bus<=m){
		for(int i = 1;i<=c;++i){
			cur_wait = (diff_info[c_index][c_index + i -1] > cur_wait) ? diff_info[c_index][c_index + i -1]:cur_wait;
			recur(cur_bus+1,i,c_index + i,cur_wait);
		}
	}
	else{
		if(c_index == n) myMax = num < myMax ? num : myMax;
	}
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("convention.in","r",stdin);
	//freopen("convention.out","w",stdout);
	cin>>n>>m>>c;
	for(int i = 0;i<n;++i) cin>>arrvied_time[i];
	sort(arrvied_time,arrvied_time+n);
	for(int i = 0;i<n;++i){
		for(int j = i;j<n;++j){
			diff_info[i][j] = arrvied_time[j] - arrvied_time[i];
		}
	}
	recur(0,0,0,0);
	

	/*
	int bus_remained = m;
	
	for(int i = 0;i<n;++i){
		if(i%c==0){
			if(i+c>n) update(i,n-1);
			else update(i,i+c-1);				
		}
	}
	int m1 = myMax;
	//cout<<m1<<endl;
	myMax = 0;
	for(int i = n-1;i>=0;--i){
		if((n-i-1)%c==0){
			if(i-c<-1) update(0,i);
			else update(i-c+1,i);	
		}
	}
	int m2 = myMax;
	//cout<<m2<<endl;
	myMax = 0;

	if(m1<=m2){
		for(int i = 0;i<n;i+=c){
			diff_info[i] = 0;
			--bus_remained;
		}		
	}
	else{
		for(int i = n;i>=0;i-=c){
			diff_info[i] = 0;
			--bus_remained;
		}
	}
	while(bus_remained > 0){
		int cur_max = 0, cur_pos = -1;		
		for(int i = 0;i<n;++i){
			if(diff_info[i] > cur_max){
				cur_max = diff_info[i];
				cur_pos = i;
			}
		}
		diff_info[cur_pos] = 0;
		--bus_remained;
	}
	for(int i = 0;i<n;++i){
		if(diff_info[i] == 0){
			int j = i;
			int cur_count = 0;
			while(diff_info[j+1]!=0){
				cur_count+=diff_info[j+1];
				++j;
			}
			myMax = cur_count > myMax ? cur_count : myMax;
		}
	}
	*/
	cout<<myMax<<endl;
	return 0;
}