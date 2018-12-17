/*
ID: xinyu.l1
TASK: convention2
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
int n,t, already_ate, pointer;
int max_wait = 0;
bool visited[100001];
struct cow
{
	int arr_t,stay_t,rank;
}cows[100001];
bool Compare(pair<cow,int> a, pair<cow,int> b){
	return a.first.rank > b.first.rank;
}
priority_queue<pair<cow,int>, vector<pair<cow,int>>, decltype(&Compare)> myQueue(Compare);

bool cmp(cow a, cow b){
	return a.arr_t < b.arr_t;
}

void eat(){
	visited[pointer] = true;
	//cout<<pointer<<' '<<cows[pointer].rank+1<<' '<<(t-cows[pointer].arr_t)<<endl;
	t+=cows[pointer].stay_t;
	for(int i = pointer+1;i<n;++i){
		if(cows[i].arr_t > t) break;
		if(!visited[i]) {
			myQueue.push(make_pair(cows[i],i));
			//cout<<i<<"is in"<<endl;
		}
	}
	if(myQueue.size() == 0){
		while(visited[pointer+1]){
			pointer++;
		}
		++pointer;
		t = cows[pointer].arr_t;
	}
	else{
		cow p = (myQueue.top()).first;
		pointer = (myQueue.top()).second;
		myQueue.pop();
		max_wait = (max_wait > (t-p.arr_t)) ? max_wait : (t-p.arr_t);
	}
	++already_ate;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("convention2.in","r",stdin);
	freopen("convention2.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>cows[i].arr_t>>cows[i].stay_t;
		cows[i].rank = i;
	}
	sort(cows, cows+n,cmp);
	pointer = 0;
	t = cows[0].arr_t;
	while(already_ate!=n) eat();
	cout<<max_wait<<endl;
	return 0;
}