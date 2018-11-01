/*
ID: xinyu.l1
TASK: humble
LANG: C++                 
*/
#include <iostream>

using namespace std;

int n,k;
int original[101], record[101], humble_numbers[100001];
int pointer;
const int MAX = 2147483647;
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	cin>>k>>n;
	for(int i = 0;i<k;++i) {cin>>original[i];}
	humble_numbers[0] = 1;
	while(pointer != n){
		int cur_min = MAX;
		int temp = 0;
		for(int j = 0;j<k;++j){	
			while(original[j]*humble_numbers[record[j]]<=humble_numbers[pointer]) record[j]++;
        	if(original[j]*humble_numbers[record[j]]<cur_min) {cur_min = original[j]*humble_numbers[record[j]];}
		}
		//cout<<"FOUND "<<cur_min<<" AT POSITION "<<pointer+1<<endl;
		humble_numbers[++pointer] = cur_min;
	}
	cout<<humble_numbers[n]<<endl;
	return 0;
}