/*
ID: xinyu.l1
TASK: billboard
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
int a1x,a1y,a2x,a2y,b1x,b1y,b2x,b2y,target_1x,target_1y,target_2x,target_2y;

int between(int x1, int x2, int y1, int y2){
	if(x1 <= y1){
		if(x2<=y1) return 0;
		else return min(x2-y1,y2-y1);
	}
	else if(x1 <=y2){
		return min(x2-x1,y2-x1);
	}
	else return 0;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	cin>>a1x>>a1y>>a2x>>a2y;
	cin>>b1x>>b1y>>b2x>>b2y;
	cin>>target_1x>>target_1y>>target_2x>>target_2y;
	//cout<<between(target_1y,target_2y,a1y,a2y);
	int ok = between(target_1x,target_2x,a1x,a2x) * between(target_1y,target_2y,a1y,a2y) + between(target_1x,target_2x,b1x,b2x) * between(target_1y,target_2y,b1y,b2y);
	cout<<(a2x-a1x)*(a2y-a1y) + (b2x-b1x)*(b2y-b1y) - ok<<endl;
	return 0;
}