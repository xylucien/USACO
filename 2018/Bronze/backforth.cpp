/*
ID: xinyu.l1
TASK: backforth
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
int cnt;
bool visited[1000000];
int bucket_info[2][10];
int Tue[2][11],Wed[2][11],Thu[2][11],Fri[2][11];

void printArr(){
	for(int i = 0;i<11;++i){
		cout<<Tue[0][i]<<' ';
	}
	cout<<endl;
	for(int i = 0;i<11;++i){
		cout<<Tue[1][i]<<' ';
	}
	cout<<endl<<endl;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("backforth.in","r",stdin);
	freopen("backforth.out","w",stdout);
	for(int i = 0;i<10;++i)cin>>bucket_info[0][i];
	for(int i = 0;i<10;++i)cin>>bucket_info[1][i];
	
	int cur;
	for(int i = 0;i<10;++i){
		int d2 = bucket_info[0][i];
		if(d2 == -1) continue;
		for(int ii = 0;ii<10;++ii){
			Tue[0][ii] = bucket_info[0][ii];
			Tue[1][ii] = bucket_info[1][ii];
		}
		Tue[0][i] = -1;
		Tue[1][10] = d2;
		
		for(int j = 0;j<11;++j){
			int d3 = Tue[1][j];
			if(d3 == -1) continue;
			for(int jj = 0;jj<11;++jj){
				Wed[0][jj] = Tue[0][jj];
				Wed[1][jj] = Tue[1][jj];
			}
			Wed[0][i] = d3;
			Wed[1][j] = -1;

			for(int k = 0;k<10;++k){
				int d4 = Wed[0][k];
				if(d4 == -1) continue;
				for(int kk = 0;kk<10;++kk){
					Thu[0][kk] = Wed[0][kk];
					Thu[1][kk] = Wed[1][kk];
				}
				Thu[0][k] = -1;
				Thu[1][10] = d4;

				for(int l = 0;l<11;++l){
					int d5 = Thu[1][l];
					if(d5 == -1) continue;
					if(!visited[1000-d2+d3-d4+d5]){
						++cnt;
						visited[1000-d2+d3-d4+d5] = true;
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}