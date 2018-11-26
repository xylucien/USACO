/*
ID: xinyu.l1
TASK: fence
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
int n;
int path_info[501][501];
string ans = "";

int startpos, backup_plan;
bool flag = false, falg = false;

void find_circuit(int x){
	for(int j = 1;j<=500;++j){
		if(path_info[x][j]){
			--path_info[x][j];
			--path_info[j][x];
			find_circuit(j);
		}
	}
	ans = to_string(x)+"\n"+ans;
	return;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	cin>>n;
	int i,j;
	for(int a = 0;a<n;++a){
		cin>>i>>j;
		++path_info[i][j];
		++path_info[j][i];
		++path_info[i][0];
		++path_info[j][0];
	}
	
	for(int a = 1;a<=500;++a){
		if((!falg) && (path_info[a][0]!= 0)){
			backup_plan = a;
			falg = true;
		} 
		if(path_info[a][0]%2==1){
			flag = true;
			startpos = a;
			break;
		}
	}
	if(flag) find_circuit(startpos);
	else find_circuit(backup_plan);
	cout<<ans;
	return 0;
}