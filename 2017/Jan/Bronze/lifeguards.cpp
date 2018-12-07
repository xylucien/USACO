/*
ID: xinyu.l1
TASK: lifeguards
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
int n,myMax,ans, info[1010];
struct staff
{
	int start,end;
}staff_list[100];
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>staff_list[i].start>>staff_list[i].end;
		for(int j = staff_list[i].start;j<staff_list[i].end;++j){
			++info[j];
		}
	}
	for(int i = 0;i<1001;++i){if(info[i])++myMax;}
	
	for(int i = 0;i<n;++i){
		int cur_max = myMax;
		for(int j = staff_list[i].start;j<staff_list[i].end;++j){
			if(info[j] == 1) --cur_max;
		}
		ans = ans<cur_max?cur_max:ans;
	}
	cout<<ans<<endl;
	return 0;
}