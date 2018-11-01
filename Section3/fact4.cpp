/*
ID: xinyu.l1
TASK: fact4
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
const long long  MAX=2147483647;
int n;
int product = 1;

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i){
		product*=i;
		while((product%10) == 0) product/=10;
		product%=1000000;
	}
	cout<<product%10<<endl;
	return 0;
}