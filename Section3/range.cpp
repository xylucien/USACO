/*
ID: xinyu.l1
TASK: range
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
const long long MAX = 2147483647;
int n;
int myMap[251][251];
int size[251];
int ubound;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
/*
void markoff(int i, int j, int range){
	for(int x = j;x<j+range;++x){
		myMap[i+range-1][x] = false;
	}
	for(int y = i;y<i+range;++y){
		myMap[y][j+range-1] = false;
	}
}

bool search(int i, int j, int range){
	if(i + range > n || j + range > n) return false;
	for(int x = j;x<j+range;++x){
		if(!myMap[i+range-1][x]) return false;
	}
	for(int y = i;y<i+range;++y){
		if(!myMap[y][j+range-1]) return false;
		
	}
	return true;
}

void scan(int i, int j){
	int max_size = 2;
	while(search(i,j,max_size)){
		markoff(i,j,max_size-1);
		++max_size;
	}
	--max_size;
	ubound = max(ubound, max_size);
	int cur_size = max_size;
	while(cur_size > 1){
		size[cur_size]+= (max_size-cur_size+1)*(max_size-cur_size+1);
		--cur_size;
	}
}
*/
bool merge(int x){
	bool flag = false;
	for(int i = 0;i<n-1;++i){
		for(int j = 0;j<n-1;++j){
			if(myMap[i][j] == (x-1) && myMap[i+1][j] == (x-1) && myMap[i][j+1] == (x-1) && myMap[i+1][j+1] == (x-1)){
				flag = true;
				//cout<<"merged "<<i<<' '<<j<<" by size "<<x<<endl;
				myMap[i][j] = x;
				++size[x];
			}
		}
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	n = read();
	string a;
	for(int i = 0;i<n;++i){
		cin>>a;
		for(int j = 0;j<n;++j){
			myMap[i][j] = a[j] - '0';
		}
	}
	/*
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			if(myMap[i][j]) scan(i,j);
		}
	}
	*/
	int cur_size = 2;
	while(merge(cur_size))++cur_size;
	for(int i = 2;i<cur_size;++i){cout<<i<<' '<<size[i]<<endl;}
	return 0;
}