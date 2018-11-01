/*
ID: xinyu.l1
TASK: money
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
int coinage[30];
long long info[10010] = {1};
int n,target;
int main(int argc, char const *argv[])
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n>>target;
	for(int i = 0;i<n;++i) cin>>coinage[i];
	for(int i = 0;i<n;++i) for(int j = coinage[i];j<=target;++j) {info[j]+=info[j-coinage[i]];}
	cout<<info[target]<<endl;
	return 0;
}