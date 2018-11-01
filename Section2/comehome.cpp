/*
ID: xinyu.l1
TASK: comehome
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int path_number;
int MAX = 10001;
bool flag = false;

struct pasture
{
	char name;
	bool connected_info[60];
	int distance_info[60];
}pasture_info[60];

struct state
{
	char cur_node, prev_node;
	int cur_distance;
}answer;

bool cmp(state a, state b){
	return a.cur_distance > b.cur_distance;
}

priority_queue <state, vector<state>, decltype(&cmp)> search_queue(cmp); 

void initialize(){
	for(int i = 0;i<60;++i){
		for(int j = 0;j<60;++j){
			pasture_info[i].distance_info[j] = MAX;
			pasture_info[i].connected_info[j] = false;
		}
	}
}

void Z_initialize(){
	for(int x = 0; x<60;++x){
		if(pasture_info['Z' - 65].connected_info[x]){	
			state temp;
			temp.prev_node = 'Z';
			temp.cur_node = char(65+x);
			temp.cur_distance = pasture_info['Z' - 65].distance_info[x];
			search_queue.push(temp);
		}
	}	
}

void search(){
	state cur_top = search_queue.top();
	if(cur_top.cur_node >= 65 && cur_top.cur_node < 90){
		flag = true;
		answer = cur_top;
	}
	else{
		search_queue.pop();
		for(int x = 0; x<60;++x){
			if((cur_top.cur_node != char(x+65)) && (cur_top.prev_node != char(x+65)) && (pasture_info[cur_top.cur_node - 65].connected_info[x])){	
				state temp;
				temp.prev_node = cur_top.cur_node;
				temp.cur_node = char(x+65);
				temp.cur_distance = cur_top.cur_distance + pasture_info[cur_top.cur_node - 65].distance_info[x];
				search_queue.push(temp);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	cin>>path_number;
	initialize();
	for(int i = 0;i<path_number;++i){
		char node1, node2;
		int distance_between_nodes;
		cin>>node1>>node2>>distance_between_nodes;
		if(!pasture_info[node1 - 65].connected_info[node2 - 65]){
			pasture_info[node1 - 65].connected_info[node2 - 65] = true;
			pasture_info[node2 - 65].connected_info[node1 - 65] = true;
		}
		if(pasture_info[node1 - 65].distance_info[node2 - 65] > distance_between_nodes){
			pasture_info[node1 - 65].distance_info[node2 - 65] = distance_between_nodes;
			pasture_info[node2 - 65].distance_info[node1 - 65] = distance_between_nodes;
		} 
	}
	Z_initialize();
	while(!flag) search();
	cout<<answer.cur_node<<' '<<answer.cur_distance<<endl;
	return 0;
}