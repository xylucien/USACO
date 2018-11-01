/*
ID: xinyu.l1
TASK: zerosum
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
int n;

void printAnswer(string x){
	for(int i = 0;i<n;++i){
		if(i!=n-1) cout<<i+1<<x[i];
		else cout<<i+1;
	}
	cout<<endl;
}

bool check(string x){
	int sum = 0;
	int cur_sum = 1;
	int indicator = 1;
	for(int i = 0;i<=n-1;++i){
		if(i == n-1) {sum+=cur_sum*indicator;break;}
		if(x[i] == ' ') {cur_sum = cur_sum*10+i+2;}
		else if(x[i] == '+') {sum+=cur_sum*indicator; indicator = 1; cur_sum = i+2;}
		else if(x[i] == '-') {sum+=cur_sum*indicator; indicator = -1; cur_sum = i+2;} 
	}
	if(sum == 0) return true;
	else return false;
}

void recur(int num_left, string x){
	if(num_left == 0){
		if(check(x)) {printAnswer(x); return;}
		else return;
	}
	else{
		recur(num_left-1,x+' ');
		recur(num_left-1,x+'+');
		recur(num_left-1,x+'-');
	}
}

int main(int argc, char const *argv[])
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	cin>>n;
	recur(n-1,"");
	return 0;
}