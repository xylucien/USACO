/*
ID: xinyu.l1
TASK: sprime
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
int prime_list[30000];
bool flag[1000000];
int total;
int rolling[100];
const int ending[4] = {1,3,7,9};
int n;
void euler_sieve(int xx)
{
    total = 0;
    memset(flag, 0, sizeof(flag));
    for (int i = 2; i <= xx; ++i) {
        if (!flag[i])
            prime_list[total++] = i;
        for (int j = 0; i * prime_list[j] <= xx; ++j) {
            flag[i*prime_list[j]] = true;
            if (i % prime_list[j] == 0) break;
        }
    }
}

void rec(int state, int num){
	if(state == n){
		for(int i = 0;i<num;++i) cout<<rolling[i]<<endl;
		return;
	}
	int cache_info[30000];
	int temp_p = 0;
	for(int i = 0;i<num;++i){
		for(int j = 0;j<4;++j){
			int temp = rolling[i]*10+ending[j];
			bool flaghere = false;
			for(int k = 0;k<total;++k){
				if((temp!=prime_list[k]) && (temp % prime_list[k] == 0)){
					flaghere = true;
					break;
				}
			}
			if(!flaghere){
				cache_info[temp_p] = temp;
				temp_p++;
			}
		}
	}
	for(int i = 0; i<temp_p;++i){
		rolling[i] = cache_info[i];
	}
	rec(state+1,temp_p);
}

int randompow(int n){
	int temp = n;
	int result = 1;
	while(temp!=0){
		result*=10;
		--temp;
	}
	return result;
}
int main(int argc, char const *argv[])
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	cin>>n;
	rolling[0] = 2; rolling[1] = 3; rolling[2] = 5; rolling[3] = 7;
	int max_num = int(sqrt(randompow(n)))+1;
	euler_sieve(max_num);
	rec(1,4); 
	return 0;
}