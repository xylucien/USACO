/*
ID: xinyu.l1
TASK: lamps
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int mycounting = 0;
int n, c;
vector<int> ON;
vector<int> OFF;
vector<int> SOLUTION;
bool cur_info[8][100];

bool cmp(int i, int j){
	for(int x = 0;x<n;++x){
		if(cur_info[i][x]!=cur_info[j][x]) return (cur_info[i][x] == false);
	}
}

void printAnswer(){
	for(auto i = SOLUTION.begin();i!=SOLUTION.end();++i){
		for(int j = 0;j<n;++j) 
			{cout<<cur_info[*i][j];}
		cout<<endl;
	}
}

bool check_step(int i){
	int step;
	if(i==0) step = 0;
	else if(i<=4) step = 1;
	else step = 2;
	return ((c - step == 0) || (c - step > 1));
}

void press(int number, int cur_place){
	int start, one_step;
	if(number == 1){
		start = 0; one_step = 1;
	}
	else if(number == 2){
		start = 0; one_step = 2;
	}
	else if(number == 3){
		start = 1; one_step = 2;
	}
	else if(number == 4){
		start = 0; one_step = 3;
	}
	for(int i = start;i<n;i+=one_step) cur_info[cur_place][i] = !cur_info[cur_place][i];
}

int main(int argc, char const *argv[])
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	cin>>n;
	cin>>c;
	
	memset(cur_info, true, sizeof(cur_info[0][0]) *8*100);
	press(1,1);
	press(2,2);
	press(3,3);
	press(4,4);
	press(1,5);
	press(4,5);
	press(2,6);
	press(4,6);
	press(3,7);
	press(4,7);

	int temp;
	while(1){
		cin>>temp;
		if(temp == -1) break;
		else ON.push_back(temp);
	}
	while(1){
		cin>>temp;
		if(temp == -1) break;
		else OFF.push_back(temp);
	}
	
	for(int i = 0;i<8;++i){
		bool flag = false;
		for(auto j = ON.begin();j!=ON.end();++j){
			if(cur_info[i][(*j) - 1]!=true){flag = true;break;}
		}
		for(auto k = OFF.begin();k!=OFF.end();++k){
			if(flag)break;
			if(cur_info[i][(*k) - 1]!=false){flag = true;break;}
		}
		if((!flag) && check_step(i)){
			++mycounting;
			SOLUTION.push_back(i);
		}
	}
	
	sort(SOLUTION.begin(),SOLUTION.end(),cmp);
	
	if(mycounting==0) cout<<"IMPOSSIBLE"<<endl;
	else printAnswer();
	
	return 0;
}