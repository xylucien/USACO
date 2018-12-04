/*
ID: xinyu.l1
TASK: measurement
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
map<string, int> myMap;
int n, ans, cur_rank, last_rank;
int cow_info[3] = {7,7,7};
//int cow_info[3];
struct change
{
	int delta[3];
}changes[101];

void updateMilk(int day){
	cow_info[0]+=changes[day].delta[0];
	cow_info[1]+=changes[day].delta[1];
	cow_info[2]+=changes[day].delta[2];
	//cow_info[0]+=cow_info[0];
	//cow_info[1]+=cow_info[1];
	//cow_info[2]+=cow_info[2];
}

int getCurrentRank(){
	if(cow_info[0] > cow_info[1]){
		if(cow_info[0] > cow_info[2]) return 1;
		else if(cow_info[0] == cow_info[2]) return 5;
		else return 4;
	}
	if(cow_info[0] == cow_info[1]){
		if(cow_info[0] < cow_info[2]) return 4;
		if(cow_info[0] == cow_info[2]) return 7;
		else return 3;
	}
	else{
		if(cow_info[1] > cow_info[2]) return 2;
		if(cow_info[1] == cow_info[2]) return 6;
		else return 4;
	}

}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	myMap["Bessie"] = 0;
	myMap["Elsie"] = 1;
	myMap["Mildred"] = 2;
	cin>>n;
	for(int i = 0;i<n;++i){
		int cur_day;
		string cur_name;
		cin>>cur_day>>cur_name;
		cin>>changes[cur_day].delta[myMap[cur_name]];
	}
	for(int i = 0;i<=100;++i){
		updateMilk(i);
		cur_rank = getCurrentRank();
		if(cur_rank!=last_rank)++ans;
		last_rank = cur_rank;
		//cout<<"Day "<<i<<": "<<cur_rank<<" with "<<cow_info[0]<<" "<<cow_info[1]<<" "<<cow_info[2]<<endl;
	}
	cout<<ans-1<<endl;
	return 0;
}