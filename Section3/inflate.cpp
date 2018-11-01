/*
ID: xinyu.l1
TASK: inflate
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int total_time, n, total_max;
int points[10001];

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	cin>>total_time>>n;
	for(int i = 0;i<n;++i){
		int cur_cost, cur_points;
		cin>>cur_points>>cur_cost;
		for(int j = cur_cost;j<=total_time;++j){
			if(points[j - cur_cost] + cur_points > points[j]) points[j] = points[j - cur_cost] + cur_points;
			if(points[j] > total_max) total_max = points[j];
		}
	}
	cout<<total_max<<endl;
	return 0;
}