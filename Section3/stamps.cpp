/*
ID: xinyu.l1
TASK: stamps
LANG: C++                 
*/
#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int coinage[51];
int reached_value[2000000];
int total_cnt = 1;
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin>>k>>n;
	for(int i=0;i<2000000;++i) {reached_value[i] = 20020226;}
	for(int i=0;i<n;++i) {cin>>coinage[i];}
	//sort(coinage,coinage+n);
	reached_value[0] = 0;
	for(int i=0;i<n;++i){
		for(register int j = coinage[i];j<=2000000;++j){
			if((reached_value[j - coinage[i] != 20020226]) && (reached_value[j - coinage[i]]+1 <= k)){
				reached_value[j] = min(reached_value[j], reached_value[j-coinage[i]] + 1);
			}
		}
	}
	while(1){
		if(reached_value[total_cnt]==20020226) break;
		else ++total_cnt;
	}
	cout<<total_cnt-1<<endl;
	return 0;
}