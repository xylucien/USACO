/*
ID: xinyu.l1
TASK: holstein
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>

using namespace std;

int vitamin_num,feed_num;
int required_info[30];
int used_num[20];
int feed_info[20][30];
int cur_types;
bool flag = false;
bool check(){
	for(int i = 0;i<vitamin_num;++i){
		int temp_vitamin = 0;
		for(int j = 0;j<cur_types;++j){
			temp_vitamin+=feed_info[used_num[j]][i];
		}
		if(required_info[i]>temp_vitamin){return false;}
	}
	return true;
}

void pick(int feeds_needed){
	if(feeds_needed==0){
		if(check()){
			flag = true;
			cout<<cur_types<<' ';
			int p = 0;
			for(int i = 0;i<cur_types;++i){
				if(p!=cur_types-1) {cout<<used_num[i]+1<<' ';++p;}
				else {cout<<used_num[i]+1<<endl;}
			}
			return;
		}
		else return;
	}
	else{
		if(flag) return;
		for(int i = (feeds_needed<cur_types)?(used_num[cur_types - feeds_needed - 1]+1):0;i<feed_num - feeds_needed+1;++i){
			used_num[cur_types - feeds_needed] = i;
			pick(feeds_needed-1);
		}
	}
}

void search(){
	for(cur_types = 1;cur_types<=feed_num;++cur_types){
		memset(used_num,0,sizeof(used_num));
		pick(cur_types); 
		if(flag) break;
	}
	return;
}

int main(int argc, char const *argv[])
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	cin>>vitamin_num;
	for(int i = 0;i<vitamin_num;++i) cin>>required_info[i];
	cin>>feed_num;
	for(int i = 0;i<feed_num;++i){
		for(int j = 0;j<vitamin_num;++j){
			cin>>feed_info[i][j];
		}
	}
	search();
	return 0;
}