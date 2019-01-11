/*
ID: xinyu.l1
TASK: sort
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
int n, arr[100010], ans;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int main(int argc, char const *argv[])
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n = read();
	for(int i = 0;i<n;++i)arr[i] = read();
	bool sorted = false;
	while(!sorted){
		sorted = true;
		++ans;
		for(int i = 0;i<n-1;++i){
			if(arr[i+1] < arr[i]){
				//int temp = arr[i+1];
				//arr[i+1] = arr[i];
				//arr[i] = temp;
				swap(arr[i+1],arr[i]);
				sorted = false;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}