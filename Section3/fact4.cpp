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
int n, k5, k2;
int product = 1;

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i){
		int temp = i;
		while(!(temp%5)) {
			++k5;
			temp/=5;
		}
	}
	k2 = k5;
	for(int i = 2;i<=n;++i){
		int temp = i;
		while(!(temp%5) && k5){
			temp/=5;
			--k5;
		}
		while(!(temp%2) && k2){
			temp/=2;
			--k2;
		}
		product*=(temp%10);
		product%=10;
	}
	cout<<product<<endl;
	return 0;
}