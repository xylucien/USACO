/*
ID: xinyu.l1
TASK: butter
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
#include <chrono> 
#include<stdio.h>  
#include<iostream>  
#include<stdlib.h>  
#include<string.h>  
#include<algorithm> 

using namespace std;
using namespace std::chrono; 
const long long  MAX=21474837;
int N,P,C, myMin;
int cow_in[501];
int path_info[801][801];

inline int read(){
	int x=0,sign=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

int main(int argc, char const *argv[])
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	scanf("%d %d %d", &N, &P, &C);
	myMin = MAX;
	for(int i =0;i<N;++i) cow_in[i] = read();
	for(int i = 1;i<=P;++i){
		for(int j = 1;j<=P;++j){
			if(i==j)continue;
			else path_info[i][j] = MAX;
		}
	}
	int tempa,tempb;	
	for(int j = 0;j<C;++j){
		tempa = read();
		tempb = read();
		path_info[tempa][tempb] = read();
		path_info[tempb][tempa] = path_info[tempa][tempb];
	}
	
	for(int k = 1;k<=P;++k){
		for(int i = 1;i<=P;++i){
			if(path_info[i][k]!=MAX){
				for(int j = 1;j<i;++j){
					if(path_info[k][j]!=MAX){
						int temp = path_info[i][k] + path_info[k][j];
						if((path_info[i][j] == MAX) || (path_info[i][j] > temp)) {path_info[i][j] = temp;path_info[j][i] = temp;}
					}
				}				
			}
		}	
	}
	int temp_min;
	for(int i = 1;i<=P;++i){
		int temp_min = 0;
		for(int x = 0;x<N;++x){
			temp_min+=path_info[cow_in[x]][i];
			if(temp_min > myMin) break;
		}
		myMin = temp_min > myMin ? myMin : temp_min;
	}
	printf("%d\n", myMin);
	return 0;
}