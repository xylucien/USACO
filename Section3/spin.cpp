/*
ID: xinyu.l1
TASK: spin
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
int ans_time, info[360];
struct wedge
{
	int cur_pos, extent;
};

struct wheel
{
	int speed, wedge_num;
	wedge wedge_info[5];
}wheel_info[5];

int hf_cut(int x){
	return (x>=360)?(x-360):x;
}
/*
void printWheels(){
	cout<<"AT TIME "<<ans_time<<endl;
	for(int i = 0;i<5;++i){
		cout<<"WHEEL"<<i<<" INFO "<<endl;
		cout<<"Speed: "<<wheel_info[i].speed<<endl;
		for(int j = 0;j<wheel_info[i].wedge_num;++j){
			cout<<wheel_info[i].wedge_info[j].cur_pos<<" WITHEXTENTOF"<<wheel_info[i].wedge_info[j].extent;
		}
		cout<<endl;
	}
	cout<<endl;
}

bool is_contained(int a_start, int a_end, int b_start, int b_end){
	if(a_start <= b_start){
		if(a_end>=b_start) return true;
	}
	else{
		if(b_end>=a_start) return true;
	}
	return false;	
}
*/
/*
bool check_between(int x){
	for(int i = 0;i<wheel_info[x].wedge_num;++i){
		int a_start = wheel_info[x].wedge_info[i].cur_pos;
		int a_end = wheel_info[x].wedge_info[i].cur_pos + wheel_info[x].wedge_info[i].extent;
		for(int j = 0;j<wheel_info[x+1].wedge_num;++j){
			int b_start = wheel_info[x+1].wedge_info[j].cur_pos;
			int b_end = wheel_info[x+1].wedge_info[j].cur_pos + wheel_info[x+1].wedge_info[j].extent;
			if(a_end > 360){
				if(b_end > 360){
					if(is_contained(a_start, 360, b_start, 360) || is_contained(a_start, 360, 0, b_end - 360)|| is_contained(0, a_end - 360, b_start, 360) || is_contained(0, a_end - 360, 0, b_end - 360)) return true;
				}
				else{
					if(is_contained(a_start, 360, b_start, b_end) || is_contained(0, a_end-360, b_start, b_end)) return true;
				}
			}
			else{
				if(b_end > 360){
					if(is_contained(a_start, a_end, b_start, 360) || is_contained(a_start, a_end, 0, b_end - 360)) return true;
				}
				else{
					if(is_contained(a_start, a_end, b_start, b_end)) return true;
				}	
			}
		}
	}
	return false;
}
*/
bool final_check(){
	for(int i = 0;i<360;++i){
		if(info[i]==5) return true;
	}
	return false;
}

void UpdatebySecond(){
	++ans_time;
	memset(info,0,sizeof(info));
	for(int i = 0;i<5;++i){
		for(int j = 0;j<wheel_info[i].wedge_num;++j){
			wheel_info[i].wedge_info[j].cur_pos+=wheel_info[i].speed;
			wheel_info[i].wedge_info[j].cur_pos = hf_cut(wheel_info[i].wedge_info[j].cur_pos);
			for(int k = wheel_info[i].wedge_info[j].cur_pos; k<=wheel_info[i].wedge_info[j].cur_pos + wheel_info[i].wedge_info[j].extent; ++k){
				++info[k%360];
			}

		}
	}
	//printWheels();
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	for(int i = 0;i<5;++i){
		cin>>wheel_info[i].speed>>wheel_info[i].wedge_num;
		for(int j = 0;j<wheel_info[i].wedge_num;++j){
			cin>>wheel_info[i].wedge_info[j].cur_pos>>wheel_info[i].wedge_info[j].extent;
		}
	}
	for(int i = 0;i<5;++i){
		for(int j = 0;j<wheel_info[i].wedge_num;++j){
			for(int k = wheel_info[i].wedge_info[j].cur_pos; k<=wheel_info[i].wedge_info[j].cur_pos + wheel_info[i].wedge_info[j].extent; ++k){
				++info[k%360];
			}
		}
	}
	if(final_check()){cout<<0<<endl;return 0;}
	while(ans_time<100000){
		UpdatebySecond();
		if(final_check()){
			cout<<ans_time<<endl;
			return 0;
		}
	}
	cout<<"none"<<endl;
	return 0;
}