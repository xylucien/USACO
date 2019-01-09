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
long long n,g, cow_info[100010];
set<int> wall;
int cur_peak, ans, MyM, discrete[100010];
struct log
{
	long long cow_id, change, day;
	bool operator <(const log &x)const{
        return day < x.day;
    }
}logs[100010];

void refresh_wall(int x){
	for(int i = 0;i<=MyM;++i){
		if(cow_info[i] == x) wall.insert(i);
	}
}

int find_next_max(){
	int myMax = 0;
	for(int i = 0;i<=MyM;++i){
		if(cow_info[i] > myMax) myMax = cow_info[i];
	}
	return myMax;
}

int main(int argc, char const *argv[])
{
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	cin>>n>>g;
	string temp_input;
	for(int i = 0; i < n; ++i){
		cin>>logs[i].day>>logs[i].cow_id>>temp_input;
		discrete[i] = logs[i].cow_id;
		int sign = (temp_input[0] == '+') ? 1 : -1;
		logs[i].change = (sign * atoi((temp_input.substr(1)).c_str()));
	}
	sort(discrete,discrete+n);
	MyM = unique(discrete,discrete+n) - discrete;
	for(int i = 0;i<n;++i){
		logs[i].cow_id = 1 + lower_bound(discrete,discrete+MyM,logs[i].cow_id) - discrete;
		cow_info[logs[i].cow_id] = g;
	}
	for(int i = 0;i<=MyM;++i) wall.insert(i);
	sort(logs,logs+n);
	cow_info[0] = g;
	cur_peak = g;
	for(int i = 0;i<n;++i){
		int cur_index = logs[i].cow_id;
		cow_info[cur_index] += logs[i].change;
		auto x = wall.find(cur_index);
		if(cow_info[cur_index] < cur_peak){
			if(x != wall.end()){
				wall.erase(x);
				if(wall.empty()){
					cur_peak = find_next_max();
					refresh_wall(cur_peak);
					if(wall.size()!=1 || wall.find(cur_index) == wall.end()){
						++ans;
						//cout<<"Day "<<i<<": recess "<<cur_index<<" with max "<<cur_peak<<endl;		
					}
				}
				else{
					++ans;
					//cout<<"Day "<<i<<": recess "<<cur_index<<" with max "<<cur_peak<<endl;
				}		
			}
		}
		else if(cow_info[cur_index] == cur_peak){
			++ans;
			wall.insert(cur_index);	
			//cout<<"Day "<<i<<": remain "<<cur_index<<" with max "<<cur_peak<<endl;
		}
		else{
			if(x == wall.end() || wall.size()!=1){
				++ans;
				wall.clear();
				wall.insert(cur_index);
				cur_peak = cow_info[cur_index];
				//cout<<"Day "<<i<<": refresh "<<cur_index<<" with max "<<cur_peak<<endl;
			}
			else cur_peak = cow_info[cur_index];
		}
	}
	//cout<<wall.size()<<' '<<cur_peak<<endl;
	cout<<ans<<endl;
	return 0;
}