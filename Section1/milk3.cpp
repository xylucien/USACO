/*
ID: xinyu.l1
TASK: milk3
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool result[21];
int capacity[3];
int count = 0;
bool visited[21][21][21];
void fill(int info[]){
	if(info[0]==0){
		if(result[info[2]]) {return;}
		else {result[info[2]] = true;++count;}
	}
	for(int i = 0;i<3;++i){
		for(int j = 0;j<3;++j){
			if((info[i]!=0) && (info[j] < capacity[j]) && (i!=j)){
				int new_info[3];
				copy(info, info+3, new_info);		
				if(info[i] <= (capacity[j] - info[j])){
					new_info[j]+=new_info[i];
					new_info[i] = 0;
				}
				else{
					new_info[j] = capacity[j];
					new_info[i]-=(capacity[j] - info[j]);
				}
				if(!visited[new_info[0]][new_info[1]][new_info[2]]) {
					visited[new_info[0]][new_info[1]][new_info[2]] = true;
					fill(new_info);
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	for(int i = 0;i<3;++i) cin>>capacity[i];
	int initial[3];
	initial[0] = 0;
	initial[1] = 0;
	initial[2] = capacity[2];
	fill(initial);
	for(int i = 0;i<=20;++i){
		if(result[i]) {
			if(--count == 0) cout<<i<<endl;
			else cout<<i<<" ";
		}
	}
	return 0;
}