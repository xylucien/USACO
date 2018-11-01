/*
ID: xinyu.l1
TASK: hamming
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>

using namespace std;

int N,B,D;
int MAX;
int cur_info[100];
bool flag = false;

int hamming_distance(int a, int b){
	int count = 0;
	for(int i = 0;i<B;++i){
		if((a&1)!=(b&1)) ++count;
		a/=2;
		b/=2;
	}
	return count;
}

void printAnswer(){
	for(int i = 1;i<=N;++i){
		if(i==N) cout<<cur_info[i-1];
		else if((i%10)!=0) cout<<cur_info[i-1]<<" ";
		else cout<<cur_info[i-1]<<endl;
	}
	cout<<endl; 
}

bool check(int position, int cur_num){
	for(int i = 0;i<cur_num;++i){
		if((position != i) && (hamming_distance(cur_info[i],position) < D)) return false;
	}
	return true;
}

void search(int num_left){
	if(num_left == 0){
		flag = true;
		printAnswer();
		return;
	}
	else{
		if(flag) return; // prune
		for(int i = (num_left<N)?(cur_info[N - num_left - 1]+1):0;i<MAX;++i){
			if(flag) return;
			if(check(i,N - num_left)){
				cur_info[N - num_left] = i;
				search(num_left-1);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	cin>>N>>B>>D;
	MAX = int(pow(2,B));
	search(N);
	return 0;
}