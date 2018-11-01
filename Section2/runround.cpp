/*
ID: xinyu.l1
TASK: runround
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <cstdlib>

using namespace std;

unsigned long long n;
int cur_length;
int reverse_info[20];
bool visited[20];
bool used[10];
vector<int> info;

bool check(){
	memset(used,false,sizeof(used));
	memset(visited,false,sizeof(visited));
	for(auto i = info.begin();i!=info.end();++i){
		if((*i == 0) || used[*i]) return false;
		used[*i] = true;
	}
	int cur_position = 0;
	for(int i = 0;i<cur_length;++i){
		cur_position = (cur_position + info[cur_position])%(cur_length);
		if(visited[cur_position]) return false;
		else visited[cur_position] = true;
	}
	if(cur_position == 0) return true;
	else return false;
}

void quickprint(){
	for(auto i = info.begin(); i!=info.end();++i) cout<<*i;
	cout<<endl;
}

void update(){//could have done better for this part
	int a = info.size() - 1;
	++info[a];
	while(info[a] > 9){
		info[a] = 0;
		if(a==0) {info.insert(info.begin(),1);++cur_length;}
		else ++info[--a];
	}
}

void readNumber(unsigned long long temp){
	while(temp!=0){
		reverse_info[cur_length] = temp%10;
		++cur_length;
		temp/=10;
	}
	for(int i = 0;i<cur_length;++i) info.push_back(reverse_info[cur_length - i - 1]);
}

int main(int argc, char const *argv[])
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	cin>>n;
	if(n==0){cout<<1<<endl;return 0;}
	cur_length = 0;
	readNumber(n);
	update();
	while(233){
		if(check()) {quickprint();return 0;}
		else update();
	}
}