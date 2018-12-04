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
int ax1,ax2,ay1,ay2,bx1,bx2,by1,by2;

bool is_covered(int x, int y){
	return ((x >= bx1 && x <= bx2) && (y >= by1 && y <= by2));
}

int intersect(){
	int intersecting_length;
	if((ax1 >= bx1) && (ax2 <= bx2)){
		//case y intersecting
		intersecting_length = min(ay2-by1, by2-ay1);
		return intersecting_length*(ax2-ax1);
	}
	else{
		//case x intersecting
		intersecting_length = min(ax2-bx1, bx2-ax1);
		return intersecting_length*(ay2-ay1);
	}
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	int state = 0;
	cin>>ax1>>ay1>>ax2>>ay2>>bx1>>by1>>bx2>>by2;	
	int original = (ax2-ax1)*(ay2-ay1);
	if(is_covered(ax1,ay1)) ++state;
	if(is_covered(ax1,ay2)) ++state;
	if(is_covered(ax2,ay1)) ++state;
	if(is_covered(ax2,ay2)) ++state;
	if(state<2){cout<<original<<endl;return 0;}
	else if(state == 2){
		cout<<original-intersect()<<endl;
		return 0;
	}
	else{cout<<0<<endl;return 0;}
}