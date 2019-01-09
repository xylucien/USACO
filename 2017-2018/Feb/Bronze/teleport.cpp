/*
ID: xinyu.l1
TASK: teleport
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
int a,b,c,d;
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("teleport.in","r",stdin);
	freopen("teleport.out","w",stdout);
	cin>>a>>b>>c>>d;
	int e = abs(min(a,b) - min(c,d)) + abs(max(a,b) - max(c,d));
	int f = abs(a-b);
	cout<<(e<f?e:f)<<endl;
	return 0;
}