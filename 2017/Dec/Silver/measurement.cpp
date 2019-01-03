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
int n,g, cow_info[100010];
set<int> wall;
map<int, int> myMap;
int myMap_pointer = 0;
int cur_peak, ans;
struct log
{
	int cow_id, change, day;
	bool operator <(const log &x)const{
        return day < x.day;
    }
}logs[100010];

void refresh_wall(int x){
	if(x == g) return;
	for(int i = 1;i<=myMap_pointer;++i){
		if(cow_info[i] == x) wall.insert(i);
	}
	//cout<<"done"<<endl;	
}

int find_next_max(){
	int myMax = 0;
	for(int i = 0;i<=myMap_pointer;++i){
		if(cow_info[i] > myMax) myMax = cow_info[i];
	}
	return myMax;
}

int main(int argc, char const *argv[])
{
	freopen("measurement.in","r",stdin);
	//freopen("measurement.out","w",stdout);
	cin>>n>>g;
	cur_peak = g;
	string temp_input;
	for(int i = 0; i < n; ++i){
		cin>>logs[i].day>>logs[i].cow_id>>temp_input;
		int sign = (temp_input[0] == '+') ? 1 : -1;
		logs[i].change = (sign * atoi((temp_input.substr(1)).c_str()));
	}
	sort(logs,logs+n);
	cow_info[0] = g;
	for(int i = 0;i<n;++i){
		if(myMap.count(logs[i].cow_id) == 0){
			myMap[logs[i].cow_id] = ++myMap_pointer;
			cow_info[myMap_pointer] = g;
		}
		int cur_index = myMap[logs[i].cow_id];
		cow_info[cur_index] += logs[i].change;
		auto x = wall.find(cur_index);
		if(cow_info[cur_index] < cur_peak){
			if(x != wall.end()){
				cur_peak = find_next_max();
				wall.erase(x);
				if(wall.empty()){
					refresh_wall(cur_peak);
					if(wall.size()!=1 || wall.find(cur_index) == wall.end()){
						++ans;
						cout<<"Day "<<i<<": recess "<<cur_index<<" with max "<<cur_peak<<endl;		
					}
				}
				else{
					++ans;
					cout<<"Day "<<i<<": recess "<<cur_index<<" with max "<<cur_peak<<endl;
				}		
			}
		}
		else if(cow_info[cur_index] == cur_peak){
			if(cur_peak!=g){
				++ans;
				wall.insert(cur_index);	
				cout<<"Day "<<i<<": remain "<<cur_index<<" with max "<<cur_peak<<endl;
			}
		}
		else{
			if(x == wall.end() || wall.size()!=1){
				++ans;
				wall.clear();
				wall.insert(cur_index);
				cur_peak = cow_info[cur_index];
				cout<<"Day "<<i<<": refresh "<<cur_index<<" with max "<<cur_peak<<endl;
			}
			else cur_peak = cow_info[cur_index];
		}
	}
	cout<<wall.size()<<' '<<cur_peak<<endl;
	cout<<ans<<endl;
	return 0;
}