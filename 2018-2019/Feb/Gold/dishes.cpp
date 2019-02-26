/*
ID: xinyu.l1
TASK: dishes
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
int n;
int plate[100010];
int clean = -1;
deque<int> counter[100010];
int counter_base[100010];
int myMapPointer, myMapLength;
const long long MAX = 2147483647;

inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

int search(int x){
	if(x > counter_base[myMapLength-1]) return myMapLength;
	else return lower_bound(counter_base, counter_base + myMapLength, x) - counter_base;
}

int main(int argc, char const *argv[])
{
	freopen("dishes.in","r",stdin);
	freopen("dishes.out","w",stdout);

	n = read();
	for(int i = 0;i<n;++i) plate[i] = read();

	counter[0].push_back(plate[0]);
	counter_base[0] = plate[0];
	++myMapLength;

	for(int i = 1;i<n;++i){
		if(plate[i] < clean){
			cout<<i<<endl;
			return 0;
		}
		int newPointer = search(plate[i]);
		//int newPointer = lower_bound(counter_base, counter_base + myMapLength, plate[i]) - counter_base;
		if(newPointer == myMapLength){
			counter[myMapLength].push_back(plate[i]);
			counter_base[myMapLength] = plate[i];
			++myMapLength;				
		}
		else{
			while(counter[newPointer].back() < plate[i]){
				clean = counter[newPointer].back();
				counter[newPointer].pop_back();
			}
			counter[newPointer].push_back(plate[i]);
		}
	}
	cout<<n<<endl;
	return 0;
}